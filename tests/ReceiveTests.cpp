/*
 * ReceiveTests.cpp
 *
 *  Created on: May 28, 2014
 *      Author: boris
 */

#include <tests/ReceiveTests.hpp>
#include <stdio.h>
#include <string>
#include "communication/CommunicationHandlerFactory.hpp"

using namespace std;

ReceiveTests::ReceiveTests() {
	CommunicationHandlerFactory::CommunicationHandlerFactory factory;
	comm_handler = factory.createHandler("uart");
}

ReceiveTests::~ReceiveTests() {
	// TODO Auto-generated destructor stub
}

char* ReceiveTests::runTests(){
	printf("1. Please verify your UART cable is connected and TSIM is configured to read from COM1 port using this prop: -uart2 //./com1\n");
	printf("2. Please make sure your com1 port is opened\n");
	printf("3. This test requires the user to write bytes to COM1 port\n");
	string s = comm_handler->receive();
	mu_assert("error, receive packet", comm_handler->verifyBytes(s));
	printf("received this data:\n%s\n", &s[0]);
	return 0;
}
