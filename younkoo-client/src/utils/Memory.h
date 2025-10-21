#pragma once
#include <cstdint>
namespace utils {
	namespace memory {
		uint8_t* allocate_nearby_memory(uint8_t* nearby_addr, int size, int access);
		void clean_all_allocated_memory();
	}
}