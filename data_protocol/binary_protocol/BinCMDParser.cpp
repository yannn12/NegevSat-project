/*
 * BinCMDParser.cpp
 *
 *  Created on: 6 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/binary_protocol/BinCMDParser.hpp>
#include <stdio.h>

bool BinCMDParser::parsePacket(char* packet,int size,WorkDescription& result){
	bool valid =false;

	WorkDescription* work=(WorkDescription*)packet;

//	unsigned long long * timestamp =(unsigned long long *)p;
	printf("timestam is %lld \n", (unsigned long long)work->getTimestamp()); ///theis fucke in the prinf
//	p=p+8;
//
//	int code=(*p)-'0';
	printf("code is %d \n",work->getCode());
//	p=p+1;
//
//	int* priority=(int*)p;
	printf("priority is %d \n",work->getPriority());
//
//	p=p+4;
//	unsigned long long * missionTime=(unsigned long long *)p;
	printf("missionTime is %lld \n", (unsigned long long)work->getMissionTime());


	return false;
}

BinCMDParser::~BinCMDParser() {
	// TODO Auto-generated destructor stub
}

BinCMDParser::BinCMDParser() {
	// TODO Auto-generated constructor stub

}

