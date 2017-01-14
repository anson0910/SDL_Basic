/*
 * Swarm.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: Anson
 */

#include "Swarm.h"

namespace screen {

Swarm::Swarm() : lastTime(0) {
	m_pParticles = new Particle[NUM_PARTICLES];
}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

void Swarm::update(int elapsed) {
	int interval = elapsed - lastTime;
	for (int i = 0; i < NUM_PARTICLES; i++)
		m_pParticles[i].update(interval);
	lastTime = elapsed;
}

} /* namespace screen */
