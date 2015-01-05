/*
 * SendReceiveQueueTests.hpp
 *
 *  Created on: Jun 5, 2014
 *      Author: boris
 */

#ifndef SENDRECEIVEQUEUETESTS_HPP_
#define SENDRECEIVEQUEUETESTS_HPP_

#include "minunit.h"
#include "communication/SendReceiveQueue.hpp"

class SendReceiveQueueTests {

private:
	SendReceiveQueue::SendReceiveQueue queue;

public:
	SendReceiveQueueTests();
	virtual ~SendReceiveQueueTests();
	char* test_basic();
	char* test_overflow();
	char* runTests();
};

#endif /* SENDRECEIVEQUEUETESTS_HPP_ */
