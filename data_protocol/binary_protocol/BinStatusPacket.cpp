/*
 * BinStatusPacket.cpp
 *
 *  Created on: 12 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/binary_protocol/BinStatusPacket.hpp>
#include <stdio.h>

BinStatusPacket::BinStatusPacket() {
	// TODO Auto-generated constructor stub

}

BinStatusPacket::~BinStatusPacket() {
	// TODO Auto-generated destructor stub
}

void BinStatusPacket::toBytes(vector<char>& result) {
	result.clear();
	result.push_back(0);

	int numberOfSamples =getComponentsInfo().size();
	char numberOfSamplesChar=(char)numberOfSamples;
	result.push_back(numberOfSamplesChar);

	for(int  i=0;i<numberOfSamples;i++){
		ComponentInfo component=getComponentsInfo().at(i);
		char* p=(char*)&component;
//		char component[10];
//		char* p=&component;
//		(*p)=this->componentsInfo.at(i).componentCode;
//		p++;
//		(*p)=this->componentsInfo.at(i).time;
//		p=p+8;
//		(*p)=this->componentsInfo.at(i).status;


		for(unsigned j=0;j<10;j++){
			result.push_back(p[j]);
		}
	}
	for(int i=0;i<result.size();i++){
		printf("%d,",result[i]);
	}
	printf("\n");

}
