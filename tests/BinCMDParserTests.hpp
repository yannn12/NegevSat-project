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
	char* assert_mission_is_correct(WorkDescription::WorkDescription* work, unsigned long long _timestamp,char _code, int _priority, unsigned long long _time);
};

#endif /* BINCMDPARSERTESTS_H_ */
