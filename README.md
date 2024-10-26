# GameFromScratch-Template
A work in progress template for creating a game from scratch in C++20.

## Project State
So far, in this template, there is:
- Extremely basic platform layer on Windows.
- No platform layer on Linux (Next step).
- A platform agnostic entry point (currently only Windows and Linux).

## Inner Workings
In the template's ``game`` project there is 2 source files. ``main.cpp`` which contains the platform agnostic ``game_main(std::vector<std::string> args)`` function. ``entry_point.cpp`` which handles the entry point for each platform, ``WinMain`` on Windows and ``main`` on Linux. 

The entry point does the following:
- Opens a console window if needed (Windows only).
- Hands over the command line arguments as a ``std::vector<std::string>``.
