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

vector<TempSample>& TempsPacket::getTempSamples(){
	return tempSamples;
}

void TempsPacket::setTempSamples(const vector<TempSample>& tempSamples) {
	this->tempSamples = tempSamples;
}



