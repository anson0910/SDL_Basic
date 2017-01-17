/*
 * Screen.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: Anson
 */

#include "Screen.h"

namespace screen {

Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {

}

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return false;

	m_window = SDL_CreateWindow("Particle Explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1,
			SDL_RENDERER_PRESENTVSYNC);
	m_texture = SDL_CreateTexture(m_renderer,
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH,
			SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (m_texture == NULL) {
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	// set all pixels to black
	clear();
	//memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	return true;
}

void Screen::boxBlur() {
	Uint32 *tmp = m_buffer1;
	m_buffer1 = m_buffer2;
	m_buffer2 = tmp;

	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			int redTotal = 0, greenTotal = 0, blueTotal = 0;
			for (int diffY = -1; diffY <= 1; diffY++) {
				for (int diffX = -1; diffX <= 1; diffX++) {
					int currY = y + diffY, currX = x + diffX;
					if (currY >= 0 && currY < SCREEN_HEIGHT && currX >= 0 && currX < SCREEN_WIDTH) {
						Uint32 color = m_buffer2[currY * SCREEN_WIDTH + currX];
						redTotal += color >> 24;
						greenTotal += color >> 16;
						blueTotal += color >> 8;
					}
				}
			}
			setPixel(x, y, redTotal / 9, greenTotal / 9, blueTotal / 9);
		}
	}
}

void Screen::clear() {
	memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
	memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

void Screen::update() {
	SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return;
	Uint32 color = 0;
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;
	m_buffer1[y * SCREEN_WIDTH + x] = color;
}

bool Screen::processEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

void Screen::close() {
	delete [] m_buffer1;
	delete [] m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} /* namespace screen */
