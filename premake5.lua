workspace "Game From Scratch"
    architecture    "x86_64"
    startproject    "Game"

    targetdir       "build/bin/%{cfg.system}/%{cfg.buildcfg}"
    objdir          "build/obj/%/cfg.system}/%{cfg.buildcfg}"

    flags
    {
        "MultiProcessorCompile",
        "FatalWarnings"
    }

    configurations
    {
        "Debug",
        "Release"
    }

    filter "configurations:Debug"
        defines         "BUILD_DEBUG"
        optimize        "Off"
        runtime         "Debug"
        symbols         "Full"
    
    filter "configurations:Release"
        defines         "BUILD_RELEASE"
        optimize        "Full"
        runtime         "Release"
        symbols         "Off"
    
    filter "system:windows"
        defines         "PLATFORM_WINDOWS"
        systemversion   "latest"
        staticruntime   "On"
    
    filter "system:linux"
        defines         "PLATFORM_LINUX"
    
    project "Game"
        kind            "WindowedApp"
        location        "game"
        language        "C++"
        cppdialect      "c++20"
        warnings        "Extra"

        files
        {
            "**.cpp",
            "**.hpp"
        }

        includedirs
        {
            "%{prj.location}"
        }