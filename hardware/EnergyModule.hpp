/*
 * EnergyModule.hpp
 *
 *  Created on: May 8, 2014
 *      Author: dariaz
 */

#ifndef ENERGYMODULE_HPP_
#define ENERGYMODULE_HPP_

#include "HWModule.hpp"

class EnergyModule : public HWModule {
private:
	int current;

public:
	EnergyModule();
	virtual ~EnergyModule();

	void setCurrent(int _current){
			current = _current;
		}

		int getCurrent(bool useI2C) {
			if (useI2C){
				// will be implemented using read from i2c
				return current;
			}
			else {
				return current;
			}

		}
};

#endif /* ENERGYMODULE_HPP_ */
