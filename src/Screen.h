/*
 * Screen.h
 *
 *  Created on: Jan 13, 2017
 *      Author: Anson
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace screen {

class Screen {
public:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

public:
	Screen();
	virtual ~Screen();
	bool init();
	void clear();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	bool processEvents();
	void close();
	void boxBlur();
};

} /* namespace screen */

#endif /* SCREEN_H_ */
