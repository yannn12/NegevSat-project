/*
 * BinCMDParser.cpp
 *
 *  Created on: 6 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/binary_protocol/BinCMDParser.hpp>
#include <stdio.h>
#include "utils/timeutils.hpp"

bool BinCMDParser::parsePacket(char* packet,int size,WorkDescription& result){
	bool valid =true;
	if(size!=21){
		printf("In BinCMDParser::parsePacket Get an packet doesn't in 21 Byte size \n");
		return false;
	}
	 try
	 {
//		WorkDescription* work=(WorkDescription*)packet;
//		int sizeofwork=sizeof(WorkDescription);
//		//unsigned long long timestamp = convert_time_chars_to_long(work->getTimestamp());
//		unsigned long long timestamp = work->getTimestamp();
//		char code=work->getCode();
//		int priority=work->getPriority();
//		unsigned long long missionTime=work->getMissionTime();
//		//unsigned long long missionTime=convert_time_chars_to_long(work->getMissionTime());
		 char* p= packet;

		unsigned long long timestamp =(unsigned long long)(*p);
		p=p+8;
		char code=*p;
		p=p+1;
		int priority=(int)(*p);
		p=p+4;
		unsigned long long missionTime=(unsigned long long)(*p);
		printf("BinCMDParser Get timestamp{%llu} code{%d} priority{%d} missionTime{%llu} \n",timestamp,code,priority,missionTime);
		if(BinCMDParser::IsParameterValid(timestamp,code,priority,missionTime)){
			result.setTimeStamp(timestamp);
			result.setCode(code);
			result.setPriority(priority);
			result.setMissionTime(missionTime);
		}
		else{
			return false;
			printf("BinCMDParser Get unvalide parameters.....drooping packets.....\n");
		}
	 }
	 catch (int e)
	   {
		 printf("In BinCMDParser::parsePacket catch e=%d exception in parsing \n",e);
		 valid=false;
	   }

//
//	printf("timestam is %lld \n", (unsigned long long)work->getTimestamp());
//	printf("code is %d \n",work->getCode());
//	printf("priority is %d \n",work->getPriority());
//	printf("missionTime is %lld \n", (unsigned long long)work->getMissionTime());


	return valid;
}
bool BinCMDParser::IsParameterValid(unsigned long long ,char code,int priority,unsigned long long missionTime){
	// TODO write an validation to the time parameter and to parameters.
	return true;
}
BinCMDParser::~BinCMDParser() {
	// TODO Auto-generated destructor stub
}

BinCMDParser::BinCMDParser() {
	// TODO Auto-generated constructor stub

}

