/*
 * BinTempsPacket.cpp
 *
 *  Created on: 14 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/binary_protocol/BinTempsPacket.hpp>
#include <stdio.h>

BinTempsPacket::BinTempsPacket() {
	// TODO Auto-generated constructor stub

}

BinTempsPacket::~BinTempsPacket() {
	// TODO Auto-generated destructor stub
}

void BinTempsPacket::toBytes(vector<char>& result) {
		result.clear();
		result.push_back(2);

		int numberOfSamples =getTempSamples().size();
		char numberOfSamplesChar=(char)numberOfSamples;

		result.push_back(numberOfSamplesChar);

		for(int  i=0;i<numberOfSamples;i++){
			TempSample component=getTempSamples().at(i);
			char* p=(char*)&component;
	//		char component[10];
	//		char* p=&component;
	//		(*p)=this->componentsInfo.at(i).componentCode;
	//		p++;
	//		(*p)=this->componentsInfo.at(i).time;
	//		p=p+8;
	//		(*p)=this->componentsInfo.at(i).status;


			for(unsigned j=0;j<12;j++){
				result.push_back(p[j]);
			}
		}
		for(int i=0;i<result.size();i++){
			printf("%d,",result[i]);
		}
		printf("\n");
}
