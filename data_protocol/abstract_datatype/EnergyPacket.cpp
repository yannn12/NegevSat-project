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

vector<BattaryInfo>& EnergyPacket::getSamples() {
	return samples;
}

void EnergyPacket::setSamples(const vector<BattaryInfo>& samples) {
	this->samples = samples;
}

