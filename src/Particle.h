/*
 * Particle.h
 *
 *  Created on: Jan 13, 2017
 *      Author: Anson
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace screen {

struct Particle {

	double m_x, m_y;

private:
	double m_speed, m_direction;

private:
	void init();

public:
	Particle();
	virtual ~Particle();
	void update(int interval);
};

} /* namespace screen */

#endif /* PARTICLE_H_ */
