/*
 * TempsPacket.cpp
 *
 *  Created on: 12 ���� 2015
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
