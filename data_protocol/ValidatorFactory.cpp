/*
 * ValidatorFactory.cpp
 *
 *  Created on: May 8, 2014
 *      Author: dariaz
 */

#include <data_protocol/ValidatorFactory.hpp>
#include "data_protocol/XMLValidator.hpp"
#include <stdio.h>
using namespace std;

ValidatorFactory::ValidatorFactory() {
	// TODO Auto-generated constructor stub

}

ValidatorFactory::~ValidatorFactory() {
	// TODO Auto-generated destructor stub
}

IValidator::IValidator* ValidatorFactory::createValidator(string type) {
	if (type.compare("XML") == 0){
		XMLValidator::XMLValidator* validator = new XMLValidator();
		return validator;
	}
	else {
		printf ("ERROR::No such validator type\n");
		return 0;
	}
}

