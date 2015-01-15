/*
 * XmlPacketFactory.hpp
 *
 *  Created on: 15 αιπε 2015
 *      Author: Yaniv
 */

#ifndef XMLPACKETFACTORY_HPP_
#define XMLPACKETFACTORY_HPP_

#include <data_protocol/abstract_datatype/PacketFactory.hpp>

class XmlPacketFactory: public PacketFactory {
public:
	virtual ~XmlPacketFactory();
	virtual EnergyPacket *createEnergyPacket();
	virtual StatusPacket *createStatusPacket();
	virtual TempsPacket *createTempsPacket();
};

#endif /* XMLPACKETFACTORY_HPP_ */
