/*
 * BinCMDParserTests.cpp
 *
 *  Created on: 7 ???? 2015
 *      Author: hod amran
 */

#include <tests/BinCMDParserTests.hpp>
#include <data_protocol/WorkDescription.hpp>
#include <data_protocol/binary_protocol/BinCMDParser.hpp>
char* BinCMDParserTests::runTests(){
	   BinCMDParser binParser;

		char*  mission1="dsfgds";
		char* mission2="sdfsadf";
		char*  mission3="sdfsadf";
		char*  mission4="sdfsadf";
		char* mission5="sdfsadf";
		char* mission6="sdfsadf";

		WorkDescription work1;
		WorkDescription work2;
		WorkDescription work3;
		WorkDescription work4;
		WorkDescription work5;
		WorkDescription work6;

		if (!(binParser.parsePacket(mission1,21,work1))){
			return fail_assert;
		}
		if (!(binParser.parsePacket(mission2,21,work2))){
				return fail_assert;
		}
		if (!(binParser.parsePacket(mission3,21,work3))){
				return fail_assert;
		}
		if (!(binParser.parsePacket(mission4,21,work4))){
				return fail_assert;
		}
		if (!(binParser.parsePacket(mission5,21,work5))){
				return fail_assert;
		}
		if (!(binParser.parsePacket(mission6,21,work6))){
				return fail_assert;
		}

		if (assert_mission_is_correct(&work1,20150110014640ULL, 5, 3, 20150531165740ULL) != 0){
			return fail_assert;
		}
		if (assert_mission_is_correct(&work2,20150110014640ULL, 4, 2, 20150531165750ULL) != 0){
			return fail_assert;
		}
		if (assert_mission_is_correct(&work3,20150110014640ULL, 2, 1, 20150531165755ULL) != 0){
			return fail_assert;
		}
		if (assert_mission_is_correct(&work4,20150110014640ULL, 3, 6, 20450531165740ULL) != 0){
			return fail_assert;
		}
		if (assert_mission_is_correct(&work5,20150110014640ULL, 5, 4, 20340531165750ULL) != 0){
			return fail_assert;
		}
		if (assert_mission_is_correct(&work6,20150110014640ULL, 6, 3, 20430531165755ULL) != 0){
			return fail_assert;

		}
		return 0;
}
BinCMDParserTests::BinCMDParserTests() {
	// TODO Auto-generated constructor stub

}
char* BinCMDParserTests::assert_mission_is_correct(WorkDescription::WorkDescription* work, unsigned long long timestamp,char code, int priority, unsigned long long time){
		mu_assert("error", work->getCode() == code);
		mu_assert("error", work->getPriority() == priority);
		mu_assert("error", work->getMissionTime() == timestamp);
		mu_assert("error", work->getMissionTime() == time);
		return 0;
}

BinCMDParserTests::~BinCMDParserTests() {
	// TODO Auto-generated destructor stub
}
