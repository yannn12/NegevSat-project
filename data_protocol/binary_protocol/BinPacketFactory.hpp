/*
 * BinPacketFactory.hpp
 *
 *  Created on: 15 αιπε 2015
 *      Author: Yaniv
 */

#ifndef BINPACKETFACTORY_HPP_
#define BINPACKETFACTORY_HPP_

#include <data_protocol/abstract_datatype/PacketFactory.hpp>

class BinPacketFactory: public PacketFactory {
public:
	virtual ~BinPacketFactory();
	virtual EnergyPacket *createEnergyPacket();
	virtual StatusPacket *createStatusPacket();
	virtual TempsPacket *createTempsPacket();
};

#endif /* BINPACKETFACTORY_HPP_ */
