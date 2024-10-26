#include "platform/platform.hpp"

#include <vector>
#include <string>

int game_main(const std::vector<std::string>& args) {
    UNUSED_PARAMETER(args);

    Platform::LogOutput("Hello, World!");
    Platform::Sleep(5000);

    return 0;
}