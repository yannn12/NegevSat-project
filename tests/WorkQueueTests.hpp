/*
 * WorkQueueTests.hpp
 *
 *  Created on: Jun 5, 2014
 *      Author: boris
 */

#ifndef WORKQUEUETESTS_HPP_
#define WORKQUEUETESTS_HPP_

#include "minunit.h"
#include "data_protocol/WorkQueue.hpp"

class WorkQueueTests {

private:
	WorkQueue::WorkQueue works;
public:
	WorkQueueTests();
	virtual ~WorkQueueTests();
	char* test_basic();
	char* test_overflow();
	char* runTests();
};

#endif /* WORKQUEUETESTS_HPP_ */
