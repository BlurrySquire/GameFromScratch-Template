#ifndef PLATFORM_HPP
#define PLATFORM_HPP

#include <cstdint>
#include <string>

#define UNUSED_PARAMETER(parameter) (parameter)

namespace Platform {
	void Sleep(uint64_t milliseconds);

	void LogOutput(const std::string& ouput);
}

#endif