/*
 * AllTests.hpp
 *
 *  Created on: May 25, 2014
 *      Author: boris
 */

#ifndef ALLTESTS_HPP_
#define ALLTESTS_HPP_

#include <stdio.h>
#include "minunit.h"
#include "CMDParserTests.hpp"
#include "TLMParserTests.hpp"
#include "XMLValidatorTests.hpp"
#include "SendTests.hpp"
#include "ReceiveTests.hpp"
#include "WorkQueueTests.hpp"
#include "SendReceiveQueueTests.hpp"

#define ALL_TESTS					 	0xFFFF

#define CMD_PARSER_TESTS				0x0001
#define TLM_PARSER_TESTS				0x0002
#define SEND_TESTS						0x0004
#define VALIDATOR_TESTS					0x0008
#define WORK_QUEUE_TESTS				0x0010
#define SEND_RECEIVE_TESTS				0x0020
#define RECEIVE_TESTS					0x0040


class AllTests {
private:
	int type_tests;
	CMDParserTests::CMDParserTests cmdtests;
	TLMParserTests::TLMParserTests tlmtests;
	ReceiveTests::ReceiveTests rcvtests;
	XMLValidatorTests::XMLValidatorTests validatortests;
	SendTests::SendTests sendtests;
	WorkQueueTests::WorkQueueTests workqueuetests;
	SendReceiveQueueTests::SendReceiveQueueTests sendreceivequeuetests;
public:
	AllTests(int _type);
	virtual ~AllTests();
	void run_all_tests();
	char* all_tests();
};

#endif /* ALLTESTS_HPP_ */
