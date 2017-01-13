# SDL_Basic
Simple SDL2(Simple DirectMedia Layer) C++ program.

## Instructions to run on Mac OS X using Eclipse CDT:
1. If you have not installed Homebrew, install it by pasting this in terminal:<br>
`/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`
2. Install SDL2 by typing in terminal:<br>
`brew install sdl2`
3. Right click on project folder, and select **Properties**.
4. Navigate to **C/C++ Build/Settings**.
5. In **GCC C++ Compiler/Includes**, add path `/usr/local/include/SDL2` to include paths(-I).
6. In **MacOS X C++ Linker/Libraries**, add path `SDL2` to Libraries(-l), <br>
and `/usr/local/lib` to library search path(-L).
7. Build and run **C1S8L61_SDLBasic.cpp**.
