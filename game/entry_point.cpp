#include <vector>
#include <string>

// Forward-declare main function from 'main.cpp'
int game_main(const std::vector<std::string>& args);

#if defined(PLATFORM_WINDOWS)

#include <Windows.h>
#include <shellapi.h>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
    UNREFERENCED_PARAMETER(hInstance);
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    if (nShowCmd) {
        AllocConsole();
    }

    // Process arguments
    int args_length;
    wchar_t** args_array = CommandLineToArgvW(GetCommandLineW(), &args_length);
    std::vector<std::string> arguments;
    for (int i = 0; i < args_length; i++) {
        char buffer[256];
        wcstombs_s(0, buffer, args_array[i], 0);
        arguments.emplace_back(std::string(buffer));
    }
    
    return game_main(arguments);
}

#elif defined(PLATFORM_LINUX)

int main(int argc, char* argv[]) {
    // Process arguments
    std::vector<std::string> arguments;
    for (int i = 0; i < argc; i++) {
        arguments.emplace_back(std::string(argv[i]));
    }

    return game_main(arguments);
}

#endif