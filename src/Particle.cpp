/*
 * Particle.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: Anson
 */

#include "Particle.h"
#include <stdlib.h>
#include <math.h>

namespace screen {

Particle::Particle() : m_x(0), m_y(0) {
	init();
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::init() {
	m_x = 0;
	m_y = 0;
	m_speed = 2.9 * rand() / RAND_MAX;
	m_speed *= m_speed;
	m_direction = 2 * M_PI * rand() / RAND_MAX;
}

void Particle::update(int interval) {
	m_direction += interval * 0.0003;

	double xSpeed = m_speed * cos(m_direction);
	double ySpeed = m_speed * sin(m_direction);
	m_x += xSpeed * interval;
	m_y += ySpeed * interval;

	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1) {
		init();
	}
}

} /* namespace screen */
