#include "Memory.h"
#include <Windows.h>
#include <vector>
static std::vector<uint8_t*> memory_to_release;
uint8_t* utils::memory::allocate_nearby_memory(uint8_t* nearby_addr, int size, int access)
{
	for (int i = 65536;
		i < 0x7FFFFFFF;
		i += 65536)
	{
		uint8_t* allocated = (uint8_t*)VirtualAlloc(nearby_addr + i, size, MEM_COMMIT | MEM_RESERVE, access);
		if (allocated) {
			memory_to_release.push_back(allocated);
			return allocated;
		}
		allocated = (uint8_t*)VirtualAlloc(nearby_addr - i, size, MEM_COMMIT | MEM_RESERVE, access);
		if (allocated) {
			memory_to_release.push_back(allocated);
			return allocated;
		}
	}
	return nullptr;
}

void utils::memory::clean_all_allocated_memory()
{
	for (auto& block : memory_to_release)
	{
		VirtualFree(block, 0, MEM_RELEASE);
	}
}
