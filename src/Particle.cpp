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
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

} /* namespace screen */
