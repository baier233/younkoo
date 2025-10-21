#include "KeepSprint.h"
#include "../../../render/Renderer.hpp"
#include "../render/gui/GUI.h"

#include <utils/Memory.h>
#include <wrapper/net/minecraft/entity/player/EntityPlayer.h>
#include <hotspot/classes/instance_klass.h>
#include <random>
#include <ranges>
#include <vector>
struct Bytecode
{
	int index = 0;
	int length = 0;
	java_runtime::bytecodes opcode = java_runtime::bytecodes::_nop;
	std::vector<int> operands;
	Bytecode* next = 0;
};
static int sprint_start_index = 0;
static int sprint_block_length = 0;
static std::vector<uint8_t> sprint_block;
static Bytecode instance{};
static java_hotspot::const_pool* new_constant_pool = 0;
static java_hotspot::const_method* c_method = 0;
static java_hotspot::const_pool* original_constant_pool = 0;
static double* keepsprint_factor_addr = 0;
KeepSprint::KeepSprint() :AbstractModule(xorstr_("KeepSprint"), Category::COMBAT, xorstr_("Keep Sprint."), 'V')
{
	this->setToggle(false);

}

KeepSprint& KeepSprint::getInstance()
{
	static KeepSprint instance = KeepSprint();
	return instance;
}
#include <hook/HookUtils.h>
static void doResovle() {
	static auto attack_id = Wrapper::EntityPlayer::attack_id();
	auto method = *reinterpret_cast<java_hotspot::method**>(attack_id);
	c_method = method->get_const_method();
	original_constant_pool = c_method->get_constants();
	auto cp_length = original_constant_pool->get_length();
	int cp_size = cp_length * 8 + java_hotspot::const_pool::get_size();

	new_constant_pool = reinterpret_cast<java_hotspot::const_pool*>(utils::memory::allocate_nearby_memory(reinterpret_cast<uint8_t*>(original_constant_pool), cp_size, PAGE_READWRITE));
	memcpy(new_constant_pool, original_constant_pool, cp_size);
	c_method->set_constants(new_constant_pool);
	auto tags = new_constant_pool->get_tags();
	for (int i = 0; i < tags->get_length(); i++)
	{
		auto tag = tags->at(i);
		if (tag == JVM_CONSTANT_Double)
		{
			double* addr = new_constant_pool->double_at_addr(i);
			LOG("Double " << i << " :" << *addr);
			if (*addr == 0.6)
			{
				keepsprint_factor_addr = addr;
			}
		}
	}

	auto bytecodes = c_method->get_bytecode();

	size_t bytecodes_length = bytecodes.size();
	int bytecodes_index = 0;
	auto indices = std::views::iota(size_t{ 0 }, bytecodes_length);

	Bytecode* current_bytecode = &instance;

	std::ranges::for_each(indices, [&](auto idx) {
		if (bytecodes_index >= bytecodes_length) return;

		const auto bytecode = static_cast<java_runtime::bytecodes>(bytecodes[bytecodes_index]);
		auto opcodes = java_runtime::bytecode(bytecodes.data() + bytecodes_index);
		current_bytecode->opcode = bytecode;
		current_bytecode->index = bytecodes_index;

		const auto& name = java_runtime::bytecode_names[bytecode];
		auto length = opcodes.get_length();
		current_bytecode->length = length;
		for (int i = 0; i < length - 1; ++i) {
			int operand = static_cast<int>(bytecodes[bytecodes_index + i]);
			current_bytecode->operands.push_back(operand);
		}
		bytecodes_index += length;
		current_bytecode->next = new Bytecode{};
		current_bytecode = current_bytecode->next;
		});
	current_bytecode = &instance;
	while (current_bytecode)
	{
		if (current_bytecode->opcode == java_runtime::bytecodes::_aload_0 && current_bytecode->next->opcode == java_runtime::bytecodes::_iconst_0 && current_bytecode->next->next->opcode == java_runtime::bytecodes::_invokevirtual)
		{
			sprint_start_index = current_bytecode->index;
			sprint_block_length = current_bytecode->length + current_bytecode->next->length + current_bytecode->next->next->length;
		}
		current_bytecode = current_bytecode->next;
	}


	sprint_block.reserve(sprint_block_length);
	memcpy(sprint_block.data(), reinterpret_cast<void*>(c_method->get_bytecode_start() + sprint_start_index), sprint_block_length);
	current_bytecode = instance.next;
	while (current_bytecode)
	{
		auto pre = current_bytecode->next;
		delete current_bytecode;
		current_bytecode = pre;
	}
}
void KeepSprint::onEnable()
{
	static std::once_flag flag;
	std::call_once(flag, [] {
		doResovle();
		});


	if (new_constant_pool && c_method)
	{
		c_method->set_constants(new_constant_pool);
	}
	if (keepsprint_factor_addr)
	{
		*keepsprint_factor_addr = 1.0;
	}
	if (sprint_start_index)
	{

		for (size_t i = 0; i < sprint_block_length; i++)
		{
			*reinterpret_cast<uint8_t*>(c_method->get_bytecode_start() + i + sprint_start_index) = static_cast<uint8_t>(java_runtime::bytecodes::_nop);
		}
	}

}

void KeepSprint::onDisable()
{
	if (original_constant_pool && c_method)
	{
		c_method->set_constants(original_constant_pool);
	}
	if (keepsprint_factor_addr)
	{
		*keepsprint_factor_addr = 0.6;
	}
	if (sprint_start_index)
	{
		memcpy(reinterpret_cast<void*>(c_method->get_bytecode_start() + sprint_start_index), sprint_block.data(), sprint_block_length);
	}
}
#include <hotspot/classes/instance_klass.h>

void KeepSprint::onUpdate()
{
	ToggleCheck;
	if (!keepsprint_factor_addr) return;
	
	if (keepsprint_factor_addr && *keepsprint_factor_addr != 1.0)
	{
		*keepsprint_factor_addr = 1.0;
	}

	if (sprint_start_index)
	{
		for (size_t i = 0; i < sprint_block_length; i++)
		{
			if (*reinterpret_cast<uint8_t*>(c_method->get_bytecode_start() + i + sprint_start_index) != static_cast<uint8_t>(java_runtime::bytecodes::_nop))
			{
				memcpy(reinterpret_cast<void*>(c_method->get_bytecode_start() + sprint_start_index), sprint_block.data(), sprint_block_length);
				break; 
			}
		}
	}
}
