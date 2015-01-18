/*
 * PacketFactory.hpp
 *
 *  Created on: 15 αιπε 2015
 *      Author: Yaniv
 */

#ifndef PACKETFACTORY_HPP_
#define PACKETFACTORY_HPP_
#include <data_protocol/abstract_datatype/EnergyPacket.hpp>
#include <data_protocol/abstract_datatype/StatusPacket.hpp>
#include <data_protocol/abstract_datatype/TempsPacket.hpp>

class PacketFactory {
public:
	static PacketFactory *factory;
	virtual EnergyPacket *createEnergyPacket() = 0;
	virtual StatusPacket *createStatusPacket() = 0;
	virtual TempsPacket *createTempsPacket() = 0;
	virtual ~PacketFactory(){}
};


//PacketFactory * PacketFactory::factory = 0;


#endif /* PACKETFACTORY_HPP_ */
