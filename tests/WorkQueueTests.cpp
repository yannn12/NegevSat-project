/*
 * WorkQueueTests.cpp
 *
 *  Created on: Jun 5, 2014
 *      Author: boris
 */

#include <tests/WorkQueueTests.hpp>
#include "data_protocol/WorkDescription.hpp"
#include "logics/NegevSatConstants.hpp"
#include "data_protocol/CMDDictionary.hpp"

WorkQueueTests::WorkQueueTests() {
	// TODO Auto-generated constructor stub

}

WorkQueueTests::~WorkQueueTests() {
	// TODO Auto-generated destructor stub
}

char* WorkQueueTests::test_basic(){
	unsigned long long time = 20140628123235ULL;
	unsigned long long time2 = 20150628123235ULL;
	unsigned long long time3 = 20140627123235ULL;

	WorkDescription::WorkDescription w1(MOVE_TO_OP, 1, 0);
	WorkDescription::WorkDescription w2(MOVE_TO_SAFE, 1, time);
	WorkDescription::WorkDescription w3(FORMAT_TEMP, 1, time2);
	WorkDescription::WorkDescription w4(FORMAT_ENERGY, 1, time3);

	works.enqueue(w1);
	works.enqueue(w2);
	works.enqueue(w3);
	works.enqueue(w4);

	works.sortWorks();

	WorkDescription::WorkDescription d1 = works.dequeue(false);
	WorkDescription::WorkDescription d2 = works.dequeue(false);
	WorkDescription::WorkDescription d3 = works.dequeue(false);
	WorkDescription::WorkDescription d4 = works.dequeue(false);
	WorkDescription::WorkDescription d5 = works.dequeue(false);

	mu_assert("error, sort failed", d1.getCode() == MOVE_TO_OP);
	mu_assert("error, sort failed", d2.getCode() == FORMAT_ENERGY);
	mu_assert("error, sort failed", d3.getCode() == MOVE_TO_SAFE);
	mu_assert("error, sort failed", d4.getCode() == FORMAT_TEMP);
	mu_assert("error, sort failed", d5.getCode() == NULL_WORK);

	return 0;
}

char* WorkQueueTests::test_overflow(){
	unsigned long long time = 20140628123235ULL;
	for (int i=0; i<QUEUE_SIZE+1; i++){
		if (i ==0){
			WorkDescription::WorkDescription w(FORMAT_ENERGY, 1, time);
			works.enqueue(w);
		}
		else if (i != QUEUE_SIZE){
			WorkDescription::WorkDescription w(MOVE_TO_OP, 1, time);
			works.enqueue(w);
		}
		else {
			WorkDescription::WorkDescription w(MOVE_TO_SAFE, 1, time);
			works.enqueue(w);
		}
	}
	WorkDescription::WorkDescription d = works.dequeue(false);
	mu_assert("error, last work should be move to safe", d.getCode() == MOVE_TO_SAFE);

	for (int i=0; i<QUEUE_SIZE; i++){
		WorkDescription::WorkDescription rest = works.dequeue(false);
		mu_assert("error, first work should be deleted", rest.getCode() != FORMAT_ENERGY);
	}

	return 0;
}

char* WorkQueueTests::runTests() {
	char* test_basic_res = test_basic();
	if (test_basic_res != 0){
		return test_basic_res;
	}

	char* test_overflow_res = test_overflow();
	if (test_overflow_res != 0){
		return test_overflow_res;
	}

	return 0;
}
