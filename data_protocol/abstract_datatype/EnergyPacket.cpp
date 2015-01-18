/*
 * EnergyPacket.cpp
 *
 *  Created on: 12 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/abstract_datatype/EnergyPacket.hpp>

EnergyPacket::~EnergyPacket() {
	// TODO Auto-generated destructor stub
}

const vector<BattaryInfo>& EnergyPacket::getSamples() const {
	return samples;
}

void EnergyPacket::setSamples(const vector<BattaryInfo>& samples) {
	this->samples = samples;
}
void EnergyPacket::toBytes(vector<char> &result){
	vector<char>::iterator it;
	it = result.begin();

	it =result.insert(it,'1');

	int numberOfSamples =samples.size();
	char numberOfSamplesChar=(char)numberOfSamples;
	it =result.insert(it,numberOfSamplesChar);

	for(int  i=0;i<numberOfSamples;i++){
		BattaryInfo component=samples.at(i);
		char* p=(char*)&component;
//		char component[10];
//		char* p=&component;
//		(*p)=this->componentsInfo.at(i).componentCode;
//		p++;
//		(*p)=this->componentsInfo.at(i).time;
//		p=p+8;
//		(*p)=this->componentsInfo.at(i).status;


		for(unsigned j=0;j<10;j++){
			it =result.insert(it,(*p));
			p++;
		}
	}

}
