/*
 * XMLValidatorTests.hpp
 *
 *  Created on: Jun 2, 2014
 *      Author: boris
 */

#ifndef XMLVALIDATORTESTS_HPP_
#define XMLVALIDATORTESTS_HPP_

#include "minunit.h"
#include "data_protocol/XMLValidator.hpp"
#include <string>

using namespace std;

class XMLValidatorTests {
private:
	IValidator::IValidator* validator;
public:
	XMLValidatorTests();
	virtual ~XMLValidatorTests();
	bool create_packet(int num_bytes, char* buff);
	char* test_valid();
	char* test_bad_xml();
	char* test_invalid_packet_element();
	char* test_without_upstream();
	char* test_invalid_missions();
	char* test_many_elements();
	char* runTests();
};

#endif /* XMLVALIDATORTESTS_HPP_ */
