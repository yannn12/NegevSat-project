/*
 * BinEnergyPacket.cpp
 *
 *  Created on: 12 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/binary_protocol/BinEnergyPacket.hpp>
#include <stdio.h>
#include <stdio.h>

BinEnergyPacket::~BinEnergyPacket() {
	// TODO Auto-generated destructor stub
}

BinEnergyPacket::BinEnergyPacket() {
	// TODO Auto-generated constructor stub

}

void BinEnergyPacket::toBytes(vector<char>& result) {
	result.clear();
	result.push_back(1);

	int numberOfSamples =getSamples().size();
	char numberOfSamplesChar=(char)numberOfSamples;
	result.push_back(numberOfSamplesChar);

	for(int  i=0;i<numberOfSamples;i++){
		BattaryInfo component=getSamples().at(i);
		char* p=(char*)&component;
//		char component[10];
//		char* p=&component;
//		(*p)=this->componentsInfo.at(i).componentCode;
//		p++;
//		(*p)=this->componentsInfo.at(i).time;
//		p=p+8;
//		(*p)=this->componentsInfo.at(i).status;


		for(unsigned j=0;j<16;j++){
			result.push_back(p[j]);
		}
	}
	for(int i=0;i<result.size();i++){
		printf("%d,",result[i]);
	}
	printf("\n");
}
