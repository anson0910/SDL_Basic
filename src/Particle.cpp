/*
 * Particle.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: Anson
 */

#include "Particle.h"
#include <stdlib.h>

namespace screen {

Particle::Particle() {
	// generate x and y values between -1 and 1
	m_x = 2.0 * rand() / RAND_MAX - 1;
	m_y = 2.0 * rand() / RAND_MAX - 1;
	m_xSpeed = 0.01 * (2.0 * rand() / RAND_MAX - 1);
	m_ySpeed = 0.01 * (2.0 * rand() / RAND_MAX - 1);
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update() {
	m_x += m_xSpeed;
	m_y += m_ySpeed;
	if (m_x < -1 || m_x > 1) m_xSpeed = -m_xSpeed;
	if (m_y < -1 || m_y > 1) m_ySpeed = -m_ySpeed;
}

} /* namespace screen */
