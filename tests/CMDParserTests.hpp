/*
 * CMDParserTests.hpp
 *
 *  Created on: May 25, 2014
 *      Author: boris
 */

#ifndef CMDPARSERTESTS_HPP_
#define CMDPARSERTESTS_HPP_

#include "data_protocol/XMLValidator.hpp"
#include "data_protocol/CMDParser.hpp"
#include "minunit.h"

class CMDParserTests {

private:
	IValidator::IValidator* validator;
	CMDParser::CMDParser parser;
public:
	CMDParserTests();
	virtual ~CMDParserTests();
	char* runTests();
};

#endif /* CMDPARSERTESTS_HPP_ */
