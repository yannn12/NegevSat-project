/*
 * BinPacketFactory.cpp
 *
 *  Created on: 15 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/binary_protocol/BinEnergyPacket.hpp>
#include <data_protocol/binary_protocol/BinPacketFactory.hpp>
#include <data_protocol/binary_protocol/BinStatusPacket.hpp>
#include <data_protocol/binary_protocol/BinTempsPacket.hpp>

BinPacketFactory::~BinPacketFactory() {
	// TODO Auto-generated destructor stub
}

EnergyPacket* BinPacketFactory::createEnergyPacket() {
	return new BinEnergyPacket();
}

StatusPacket* BinPacketFactory::createStatusPacket() {
	return new BinStatusPacket();
}

TempsPacket* BinPacketFactory::createTempsPacket() {
	return new BinTempsPacket();
}
