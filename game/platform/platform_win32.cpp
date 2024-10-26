#include "platform.hpp"

#if defined(PLATFORM_WINDOWS)

#include <Windows.h>

namespace Platform {
	void Sleep(uint64_t milliseconds) {
		SleepEx(static_cast<DWORD>(milliseconds), false);
	}

	void LogOutput(const std::string& output) {
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		WriteConsoleA(console, output.c_str(), static_cast<DWORD>(output.length()), nullptr, nullptr);
	}
}

#endif