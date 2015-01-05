/*
 * CommunicationHandler.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Genzel
 */
/* configuration information */
/*
#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#define CONFIGURE_MAXIMUM_TASKS             4
#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>

#include "UartCommunicationHandler.hpp"

using namespace std;

UartCommunicationHandler::UartCommunicationHandler(){

}

bool UartCommunicationHandler::send(char* buffer, int length){

	//printf ("*** opening uart ***\n");

	int fd = open("/dev/console_b", O_RDWR | O_NOCTTY | _FNDELAY);

	if (fd == -1){
		return false;
	}

	//printf("Opened COM1, fd=%d\n\n", fd);

	int numBytes = write(fd, buffer, length);

	if (numBytes < 0) {
		printf ("\nFailed to send from COM1!\n");
		return false;
		//TODO: add exception handling
	}
	printf ("\nSending Data...\n");
	close(fd);
	return true;
}

//TODO receive until a specific char arrived
string UartCommunicationHandler::receive(){
	int numBytes = 0;
	char buffer[BUFF_SIZE];
	int fd = open("/dev/console_b", O_RDWR /*| O_NOCTTY | _FNDELAY*/);
	if (fd == -1){
		return "";
	}
	//printf ("\nOpened COM1, fd=%d\n", fd);
	numBytes = read(fd,buffer,BUFF_SIZE-1);
	if (numBytes < 0) {
		//printf ("receive error!!!\n");
		close(fd);
		return "";
		// TODO exception handling
	}
	else {
		buffer[numBytes] = 0; // terminate
	}
	printf ("\nReceiving data...\n");
	close(fd);
	string data(buffer, numBytes+1);
	return data;
}

bool UartCommunicationHandler::verifyBytes(string msg){
	// TODO add CRC or other verification in future versions
	if (msg.compare("") == 0){
		return false;
	}
	return true;
}

