/*
 * BinCMDParserTests.hpp
 *
 *  Created on: 7 ???? 2015
 *      Author: hod amran
 */

#ifndef BINCMDPARSERTESTS_H_
#define BINCMDPARSERTESTS_H_

#include "data_protocol/binary_protocol/BinCMDParser.hpp"
#include "minunit.h"

class BinCMDParserTests {
private:
	BinCMDParser::BinCMDParser parser;
public:
	BinCMDParserTests();
	virtual ~BinCMDParserTests();
	char* runTests();
};

#endif /* BINCMDPARSERTESTS_H_ */
