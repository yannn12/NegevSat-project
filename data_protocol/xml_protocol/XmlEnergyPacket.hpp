/*
 * XmlEnergyPacket.hpp
 *
 *  Created on: 14 αιπε 2015
 *      Author: Yaniv
 */

#ifndef XMLENERGYPACKET_HPP_
#define XMLENERGYPACKET_HPP_

#include <data_protocol/abstract_datatype/EnergyPacket.hpp>

class XmlEnergyPacket : public EnergyPacket {
public:
	XmlEnergyPacket();
	virtual ~XmlEnergyPacket();
	virtual void toBytes(vector<char> &result);
};

#endif /* XMLENERGYPACKET_HPP_ */
