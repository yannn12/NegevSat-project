/*
 * XmlPacketFactory.cpp
 *
 *  Created on: 15 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/xml_protocol/XmlEnergyPacket.hpp>
#include <data_protocol/xml_protocol/XmlPacketFactory.hpp>
#include <data_protocol/xml_protocol/XmlStatusPacket.hpp>
#include <data_protocol/xml_protocol/XmlTempsPacket.hpp>

XmlPacketFactory::~XmlPacketFactory() {
	// TODO Auto-generated destructor stub
}

EnergyPacket* XmlPacketFactory::createEnergyPacket() {
	return new XmlEnergyPacket();
}

StatusPacket* XmlPacketFactory::createStatusPacket() {
	return new XmlStatusPacket();
}

TempsPacket* XmlPacketFactory::createTempsPacket() {
	return new XmlTempsPacket();
}
