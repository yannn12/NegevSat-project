/*
 * SendReceiveQueueTests.cpp
 *
 *  Created on: Jun 5, 2014
 *      Author: boris
 */

#include <tests/SendReceiveQueueTests.hpp>
#include <string>

using namespace std;

SendReceiveQueueTests::SendReceiveQueueTests() {
	// TODO Auto-generated constructor stub

}

SendReceiveQueueTests::~SendReceiveQueueTests() {
	// TODO Auto-generated destructor stub
}

char* SendReceiveQueueTests::test_basic(){
	string m1 = "hello";
	string m2 = "world";
	string m3 = "how";
	string m4 = "are";
	string m5 = "you";

	queue.enqueue(m1);
	queue.enqueue(m2);
	queue.enqueue(m3);
	queue.enqueue(m4);
	queue.enqueue(m5);

	string d1 = queue.dequeue();
	string d2 = queue.dequeue();
	string d3 = queue.dequeue();
	string d4 = queue.dequeue();
	string d5 = queue.dequeue();

	mu_assert("error, dequeue order incorrect", d1.compare(m1) == 0);
	mu_assert("error, dequeue order incorrect", d2.compare(m2) == 0);
	mu_assert("error, dequeue order incorrect", d3.compare(m3) == 0);
	mu_assert("error, dequeue order incorrect", d4.compare(m4) == 0);
	mu_assert("error, dequeue order incorrect", d5.compare(m5) == 0);

	return 0;

}

char* SendReceiveQueueTests::test_overflow() {
	string first = "first";
	string middle = "middle";
	string last = "last";

	for (int i =0 ;i< SEND_RECEIVE_QUEUE_SIZE + 1; i++){
		if (i == 0){
			queue.enqueue(first);
		}
		else if (i != SEND_RECEIVE_QUEUE_SIZE ){
			queue.enqueue(middle);
		}
		else {
			queue.enqueue(last);
		}
	}
	string d = queue.dequeue();
	mu_assert("error, dequeue order incorrect", d.compare(middle) == 0);

	for (int i=0; i<SEND_RECEIVE_QUEUE_SIZE - 1; i++){
		string dq = queue.dequeue();
		mu_assert("error, dequeue order incorrect", dq.compare(first) != 0);
	}

	return 0;
}

char* SendReceiveQueueTests::runTests() {
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
