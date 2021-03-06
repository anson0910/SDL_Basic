/*
 * Swarm.h
 *
 *  Created on: Jan 13, 2017
 *      Author: Anson
 */

#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace screen {

class Swarm {
public:
	static const int NUM_PARTICLES = 5000;

private:
	Particle *m_pParticles;
	int lastTime;

public:
	Swarm();
	virtual ~Swarm();
	const Particle * const getParticles() { return m_pParticles; }
	void update(int elapsed);
};

} /* namespace screen */

#endif /* SWARM_H_ */
