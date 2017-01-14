//============================================================================
// Name        : C1S8L61_SDLBasic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <Math.h>

#include "Screen.h"

using namespace std;
using namespace screen;

int main() {

	Screen screen;
	if (!screen.init()) {
		cout << "Error initializing SDL.\n";
		return 1;
	}

	while (true) {
		// set particles
		int elapsed = SDL_GetTicks();
		Uint8 red = (Uint8) ((1 + sin(elapsed * 0.002)) * 128);
		Uint8 green = (Uint8) ((1 + sin(elapsed * 0.001)) * 128);
		Uint8 blue = (Uint8) ((1 + sin(elapsed * 0.003)) * 128);
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
				screen.setPixel(x, y, red, green, blue);
		// update particles
		screen.update();
		// check events
		if (!screen.processEvents())
			break;
	}

	screen.close();
	return 0;
}
