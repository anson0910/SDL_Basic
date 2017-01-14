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
	m_speed = 0.001 * rand() / RAND_MAX;
	m_direction = 2 * M_PI * rand() / RAND_MAX;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(int interval) {
	double xSpeed = m_speed * cos(m_direction);
	double ySpeed = m_speed * sin(m_direction);
	m_x += xSpeed * interval;
	m_y += ySpeed * interval;
}

} /* namespace screen */
