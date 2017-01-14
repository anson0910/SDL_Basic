//============================================================================
// Name        : C1S8L61_SDLBasic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>

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
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
				screen.setPixel(x, y, 0x80, 0, 0xFF);
		screen.setPixel(400, 300, 0xFF, 0xFF, 0xFF);
		// update particles
		screen.update();
		// check events
		if (!screen.processEvents())
			break;
	}

	screen.close();
	return 0;
}
