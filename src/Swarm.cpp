/*
 * Swarm.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: Anson
 */

#include "Swarm.h"

namespace screen {

Swarm::Swarm() {
	m_pParticles = new Particle[NUM_PARTICLES];
}

Swarm::~Swarm() {
	delete [] m_pParticles;
}

void Swarm::update() {
	for (int i = 0; i < NUM_PARTICLES; i++)
		m_pParticles[i].update();
}

} /* namespace screen */
