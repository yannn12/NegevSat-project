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
#include <string.h>
#include <unistd.h>
#include <iostream>

#include "UartCommunicationHandler.hpp"

using namespace std;

UartCommunicationHandler::UartCommunicationHandler(){

}

bool UartCommunicationHandler::send(char* buffer, int length){

	//printf ("*** opening uart ***\n");
	char temp2[1024];
	char temp3[1024];
	int fd = open("/dev/console_b", O_RDWR | O_NOCTTY | _FNDELAY);

	if (fd == -1){
		return false;
	}
	for(int i=0;i<length;i++){
		printf("%d,",buffer[i]);
	}
	printf("\n");
	//printf("Opened COM1, fd=%d\n\n", fd);
	memcpy(temp3,buffer,length);
	vector<char> fixedBuffer = hideDelimiter(buffer,length);
	fixedBuffer.push_back(10);
	if(fixedBuffer.size()<=0)
		return false;
	memcpy(temp2,&fixedBuffer[0],fixedBuffer.size());
	int numBytes = write(fd, &fixedBuffer[0], fixedBuffer.size());

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
vector<char> UartCommunicationHandler::receive(){
	int numBytes = 0;
	char buffer[BUFF_SIZE];
	int fd = open("/dev/console_b", O_RDWR /*| O_NOCTTY | _FNDELAY*/);
	if (fd == -1){
		vector<char> vec;
		return vec;
	}
	//printf ("\nOpened COM1, fd=%d\n", fd);
	numBytes = read(fd,buffer,BUFF_SIZE-1);
	numBytes = restoreDelimiter(buffer,numBytes);
	if (numBytes < 0) {
		//printf ("receive error!!!\n");
		close(fd);
		vector<char> vec;
		return vec;
		// TODO exception handling
	}
	printf ("\nReceiving data...\n");
	close(fd);
	std::vector<char> data(buffer,buffer+numBytes-1);
	return data;
}

bool UartCommunicationHandler::verifyBytes(vector<char> msg){
	// TODO add CRC or other verification in future versions
	if (msg.size()==0){
		return false;
	}
	return true;
}

int UartCommunicationHandler::restoreDelimiter(char * msg,int length){
	int i=0;
	int j=0;
	if(length<0)
		return length;

	for(i=0;i<length;i++){
		if(msg[i]== 11&&i == length-1)
			return -1;
		if(msg[i] == 11&&msg[i+1] == 12){
			msg[j] = 10;
			i++;
		}
		else if(msg[i]== 11&&msg[i+1] == 11){
			msg[j] = 11;
			i++;
		}
		else{
			msg[j] = msg[i];
		}
		j++;
	}

	return j;
}

vector<char> UartCommunicationHandler::hideDelimiter(char * msg,int length){
	vector<char> result;
	for(int i=0;i<length;i++){
		if(msg[i] == 10){
			result.push_back(11);
			result.push_back(12);
		}
		else if(msg[i] == 11){
			result.push_back(11);
			result.push_back(11);
		}
		else{
			result.push_back(msg[i]);
		}
	}
	return result;


}
