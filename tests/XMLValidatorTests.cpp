/*
 * XMLValidatorTests.cpp
 *
 *  Created on: Jun 2, 2014
 *      Author: boris
 */

#include <tests/XMLValidatorTests.hpp>
#include "data_protocol/ValidatorFactory.hpp"


using namespace std;

XMLValidatorTests::XMLValidatorTests() {
	ValidatorFactory::ValidatorFactory factory;
	validator = factory.createValidator("XML");
}

XMLValidatorTests::~XMLValidatorTests() {
	// TODO Auto-generated destructor stub
}

bool XMLValidatorTests::create_packet(int num_bytes, char* buff){
	string packetstr(buff, num_bytes);
	return validator->buildPacket(packetstr);
}

char* XMLValidatorTests::test_valid(){
	char packet[] = "<?xml version='1.0'?>"
			"<packet>"
			"<upstreamPacket time='20140531165730'>"
			"<mission opcode='5' priority='3' time='20140531165740'/>"
			"<mission opcode='4' priority='2' time='20140531165750'/>"
			"<mission opcode='2' priority='1' time='20140531165755'/>"
			"</upstreamPacket>"
			"</packet>";
	mu_assert("error, build packet fail", create_packet(296, packet));
	mu_assert("error, validate failed", validator->validate());
	return 0;
}

char* XMLValidatorTests::test_bad_xml(){
	char packet[] = "<?xml version='1.0'?>"
				"<packet>"
				"<upstreamPacket time='20140531165730'>"
				"<mission opcode='5' priority='3' time='20140531165740'/>"
				"<mission opcode='4' priority='2' time='20140531165750'/>"
				"<mission opcode='2' priority='1' time='20140531165755'/>"
				"</upstreamPacket>"
				"</pa";
		mu_assert("error, build packet should fail", !create_packet(291, packet));
		return 0;
}

char* XMLValidatorTests::test_invalid_packet_element(){
	tests_run++;
	char packet[] = "<?xml version='1.0'?>"
			"<packet1>"
			"<upstreamPacket time='20140531165730'>"
			"<mission opcode='5' priority='3' time='20140531165740'/>"
			"<mission opcode='4' priority='2' time='20140531165750'/>"
			"<mission opcode='2' priority='1' time='20140531165755'/>"
			"</upstreamPacket>"
			"</packet1>";
	mu_assert("error, build packet fail", create_packet(298, packet));
	mu_assert("error, validate should fail failed", !validator->validate());
	return 0;
}

char* XMLValidatorTests::test_without_upstream(){
	tests_run++;
	char packet[] = "<?xml version='1.0'?>"
			"<packet>"
			"<upstreamPacke time='20140531165730'>"
			"<mission opcode='5' priority='3' time='20140531165740'/>"
			"<mission opcode='4' priority='2' time='20140531165750'/>"
			"<mission opcode='2' priority='1' time='20140531165755'/>"
			"</upstreamPacke>"
			"</packet>";
	mu_assert("error, build packet fail", create_packet(294, packet));
	mu_assert("error, validate should fail failed", !validator->validate());
	return 0;
}

char* XMLValidatorTests::test_invalid_missions(){
	tests_run++;
	// test1
	char packet[] = "<?xml version='1.0'?>"
			"<packet>"
			"<upstreamPacket time='20140531165730'>"
			"<mission1 opcode='5' priority='3' time='20140531165740'/>"
			"<mission2 opcode='4' priority='2' time='20140531165750'/>"
			"<mission3 opcode='2' priority='1' time='20140531165755'/>"
			"</upstreamPacket>"
			"</packet>";
	mu_assert("error, build packet fail", create_packet(299, packet));
	mu_assert("error, validate should fail failed", !validator->validate());

	// test2
	char packet2[] = "<?xml version='1.0'?>"
			"<packet>"
			"<upstreamPacket time='20140531165730'>"
			"</upstreamPacket>"
			"</packet>";
	mu_assert("error, build packet fail", create_packet(118, packet2));
	mu_assert("error, validate should fail", !validator->validate());

	//test3
	char packet3[] = "<?xml version='1.0'?>"
			"<packet>"
			"<upstreamPacket time='20140531165730'>"
			"<mission priority='3' time='20140531165740'/>"
			"<mission opcode='4' priority='2' time='20140531165750'/>"
			"<mission opcode='2' priority='1' time='20140531165755'/>"
			"</upstreamPacket>"
			"</packet>";
	mu_assert("error, build packet fail", create_packet(285, packet3));
	mu_assert("error, validate should fail", !validator->validate());

	//test4
	char packet4[] = "<?xml version='1.0'?>"
			"<packet>"
			"<upstreamPacket time='20140531165730'>"
			"<mission opcode='5' priority='3'/>"
			"<mission opcode='4' priority='2' time='20140531165750'/>"
			"<mission opcode='2' priority='1' time='20140531165755'/>"
			"</upstreamPacket>"
			"</packet>";
	mu_assert("error, build packet fail", create_packet(274, packet4));
	mu_assert("error, validate should fail", !validator->validate());
	return 0;
}

char* XMLValidatorTests::test_many_elements(){
	tests_run++;
	char packet[] = "<?xml version='1.0'?>"
			"<packet>"
			"<upstreamPacket time='20140531165730'>"
			"<mission opcode='5' priority='3' time='20140531165740'/>"
			"<mission opcode='4' priority='2' time='20140531165750'/>"
			"<mission opcode='2' priority='1' time='20140531165755'/>"
			"</upstreamPacket>"
			"</packet>"
			"<packet>"
			"</packet>";
	mu_assert("error, build packet fail", create_packet(323, packet));
	mu_assert("error, validate should fail", !validator->validate());

	char packet2[] = "<?xml version='1.0'?>"
			"<packet>"
			"<upstreamPacket time='20140531165730'>"
			"<mission opcode='5' priority='3' time='20140531165740'/>"
			"<mission opcode='4' priority='2' time='20140531165750'/>"
			"<mission opcode='2' priority='1' time='20140531165755'/>"
			"</upstreamPacket>"
			"<upstreamPacket time='20140531165730'>"
			"<mission opcode='5' priority='3' time='20140531165740'/>"
			"<mission opcode='4' priority='2' time='20140531165750'/>"
			"<mission opcode='2' priority='1' time='20140531165755'/>"
			"</upstreamPacket>"
			"</packet>";
	mu_assert("error, build packet fail", create_packet(544, packet2));
	mu_assert("error, validate should fail", !validator->validate());

	return 0;
}

char* XMLValidatorTests::runTests(){
	char* test_valid_res = test_valid();
	if (test_valid_res!= 0){
		return test_valid_res;
	}

	char* test_bad_xml_res =  test_bad_xml();
	if (test_bad_xml_res!= 0){
		return test_bad_xml_res;
	}

	char* test_test_invalid_packet_element_res = test_invalid_packet_element();
	if (test_test_invalid_packet_element_res!= 0){
		return test_test_invalid_packet_element_res;
	}

	char* test_without_upstream_res = test_without_upstream();
	if (test_without_upstream_res!= 0){
		return test_without_upstream_res;
	}

	char* test_invalid_missions_res = test_invalid_missions();
	if (test_invalid_missions_res!= 0){
		return test_invalid_missions_res;
	}

	char* test_many_elements_res = test_many_elements();
	if (test_many_elements_res!= 0){
		return test_many_elements_res;
	}
	return 0;
}
