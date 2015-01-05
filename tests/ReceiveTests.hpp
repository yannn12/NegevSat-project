/*
 * ReceiveTests.hpp
 *
 *  Created on: May 28, 2014
 *      Author: boris
 */

#ifndef RECEIVETESTS_HPP_
#define RECEIVETESTS_HPP_

#include "minunit.h"
#include "communication/SendReceiveQueue.hpp"
#include "communication/UartCommunicationHandler.hpp"

class ReceiveTests {
private:
	ICommunicationHandler::ICommunicationHandler* comm_handler;
public:
	ReceiveTests();
	virtual ~ReceiveTests();
	char* runTests();
};

#endif /* RECEIVETESTS_HPP_ */
