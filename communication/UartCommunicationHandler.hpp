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
	int restoreDelimiter(char * msg,int length);
	vector<char> hideDelimiter(char * msg,int length);
public:
	UartCommunicationHandler ();
	~UartCommunicationHandler(){}
	bool send(char* buffer, int length);
	vector<char> receive();
	bool verifyBytes(vector<char> msg);
};


#endif /* UARTCOMMUNICATIONHANDLER_HPP_ */
