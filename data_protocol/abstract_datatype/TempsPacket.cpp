/*
 * TempsPacket.cpp
 *
 *  Created on: 12 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/abstract_datatype/TempsPacket.hpp>

TempsPacket::TempsPacket() {
	// TODO Auto-generated constructor stub

}

TempsPacket::~TempsPacket() {
	// TODO Auto-generated destructor stub
}

const vector<TempSample>& TempsPacket::getTempSamples() const {
	return tempSamples;
}

void TempsPacket::setTempSamples(const vector<TempSample>& tempSamples) {
	this->tempSamples = tempSamples;
}
void TempsPacket::toBytes(vector<char> &result){
	vector<char>::iterator it;
	it = result.begin();

	it =result.insert(it,'2');

	int numberOfSamples =tempSamples.size();
	char numberOfSamplesChar=(char)numberOfSamples;
	it =result.insert(it,numberOfSamplesChar);

	for(int  i=0;i<numberOfSamples;i++){
		TempSample component=tempSamples.at(i);
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
