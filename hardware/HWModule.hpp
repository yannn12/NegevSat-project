/*
 * HWModule.hpp
 *
 *  Created on: May 8, 2014
 *      Author: dariaz
 */

#ifndef HWMODULE_HPP_
#define HWMODULE_HPP_

#include <string>

using namespace std;

class HWModule {

private:
	int value;
	int status;
	string name;
public:
	HWModule(string _name){
		name = _name;
	}
	virtual ~HWModule(){}
	void setValue(int _value){
		value = _value;
	}

	/**
	 * Gets the hardware device value, if useI2C is true reads from i2c and sets the cache to the read value
	 * else, reads from cache.
	 */
	int getValue(bool useI2C){
		if (useI2C){
			// will be implemented using read from i2c
			return value;
		}
		else {
			return value;
		}
	}

	void setStatus(int _status) {
		status = _status;
	}

	int getStatus(){
		return status;
	}

	void setName(string _name){
		name = _name;
	}

	string getName(){
		return name;
	}
};

#endif /* HWMODULE_HPP_ */
