//============================================================================
// Name        : C1S8L61_SDLBasic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>

using namespace std;

int main() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL init failed.\n";
		return 1;
	}
	cout << "SDL init successful.\n";

	SDL_Quit();
	return 0;
}
