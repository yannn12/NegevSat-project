/*
 * StatusPacket.cpp
 *
 *  Created on: 11 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/abstract_datatype/StatusPacket.hpp>
#include <utils/timeutils.hpp>
#include <utils/stringutils.hpp>

StatusPacket::~StatusPacket() {
	// TODO Auto-generated destructor stub
}

StatusPacket::StatusPacket() {
	// TODO Auto-generated constructor stub

}

const vector<ComponentInfo>& StatusPacket::getComponentsInfo() const {
	return componentsInfo;
}

void StatusPacket::setComponentsInfo(
		const vector<ComponentInfo>& componentsInfo) {
	this->componentsInfo = componentsInfo;
}
void StatusPacket::toBytes(vector<char> &result){
	vector<char>::iterator it;
	it = result.begin();

	it =result.insert(it,'0');

	int numberOfSamples =componentsInfo.size();
	char numberOfSamplesChar=(char)numberOfSamples;
	it =result.insert(it,numberOfSamplesChar);

	for(int  i=0;i<numberOfSamples;i++){
		ComponentInfo component=componentsInfo.at(i);
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
