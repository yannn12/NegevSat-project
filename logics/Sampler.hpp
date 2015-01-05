/*
 * Sampler.hpp
 *
 *  Created on: May 12, 2014
 *      Author: boris
 */

#ifndef SAMPLER_HPP_
#define SAMPLER_HPP_

#include "data_protocol/TLMParser.hpp"
#include "data_protocol/Sample.hpp"
#include "hardware/HardwareState.hpp"
#include <string>

using namespace std;

class Sampler {
private:
	HardwareState::HardwareState* hardware;
public:
	Sampler();
	virtual ~Sampler();
	void setHardware(HardwareState::HardwareState* _hardware){
		hardware = _hardware;
	}
	Sample::Sample* createSample(string type, bool i2c, unsigned long long time, int module);
};

#endif /* SAMPLER_HPP_ */
