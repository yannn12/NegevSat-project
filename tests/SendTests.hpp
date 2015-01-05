/*
 * SendTests.hpp
 *
 *  Created on: May 27, 2014
 *      Author: boris
 */

#ifndef SENDTESTS_HPP_
#define SENDTESTS_HPP_

#include "minunit.h"
#include "communication/SendReceiveQueue.hpp"
#include "communication/UartCommunicationHandler.hpp"

class SendTests {
private:
	ICommunicationHandler::ICommunicationHandler* comm_handler;
	int send_type;
public:
	SendTests();
	virtual ~SendTests();
	char* runTests();
};

#endif /* SENDTESTS_HPP_ */
