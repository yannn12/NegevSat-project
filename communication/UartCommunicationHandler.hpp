/*
 * CommunicationHandler.hpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Genzel
 */

#ifndef UARTCOMMUNICATIONHANDLER_HPP_
#define UARTCOMMUNICATIONHANDLER_HPP_

#include <vector>
#include <string>
#include "communication/ICommunicationHandler.hpp"

using namespace std;
#define BUFF_SIZE 1024

class UartCommunicationHandler : public ICommunicationHandler {

private:
	vector<string> input;
public:
	UartCommunicationHandler ();
	~UartCommunicationHandler(){}
	bool send(char* buffer, int length);
	string receive();
	bool verifyBytes(string msg);
};


#endif /* UARTCOMMUNICATIONHANDLER_HPP_ */
