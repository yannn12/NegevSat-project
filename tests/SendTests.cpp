/*
 * SendTests.cpp
 *
 *  Created on: May 27, 2014
 *      Author: boris
 */

#include <tests/SendTests.hpp>
#include "communication/CommunicationHandlerFactory.hpp"
#include "logics/SendReceiveConf.hpp"
#include "logics/NegevSatConstants.hpp"
#include <stdio.h>
#include <string>

using namespace std;

SendTests::SendTests() {
	CommunicationHandlerFactory::CommunicationHandlerFactory factory;
	comm_handler = factory.createHandler("uart");
	send_type = STATIC_SEND;
}

SendTests::~SendTests() {
	delete(comm_handler);
	comm_handler = NULL;
}

char* SendTests::runTests(){
	string packet = "<?xml version='1.0'?>"
			"<packet>"
	"<downstreamPacket>"
	"<type>Energy</type>"
	"<EnergySample time='2002-05-30T09:00:00'>"
	"<Battery1 voltage='12' current='1'/>"
	"</Energy>"
	"<EnergySample time='2002-05-30T09:00:00'>"
	"<Battery1 voltage='12' current='1'/>"
	"</Energy>"
	"</downstreamPacket>"
	"</packet>";

	printf("1. Please verify your UART cable is connected and TSIM is configured to read from COM1 port using this prop: -uart2 //./com1\n");
	printf("2. Please make sure your com1 port is opened\n");
	bool success = true;
	success = comm_handler->send(&packet[0],packet.length());
	mu_assert("error, sending packet", success);
	return 0;
}
