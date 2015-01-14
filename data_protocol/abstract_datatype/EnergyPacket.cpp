/*
 * EnergyPacket.cpp
 *
 *  Created on: 12 ���� 2015
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
