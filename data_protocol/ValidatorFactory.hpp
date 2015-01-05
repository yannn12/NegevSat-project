/*
 * ValidatorFactory.hpp
 *
 *  Created on: May 8, 2014
 *      Author: dariaz
 */

#ifndef VALIDATORFACTORY_HPP_
#define VALIDATORFACTORY_HPP_

#include <string>
#include "data_protocol/IValidator.hpp"

using namespace std;

class ValidatorFactory {
public:
	ValidatorFactory();
	virtual ~ValidatorFactory();
	IValidator::IValidator* createValidator(string type);
};

#endif /* VALIDATORFACTORY_HPP_ */
