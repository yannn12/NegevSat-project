/*
 * BinEnergyPacket.hpp
 *
 *  Created on: 12 αιπε 2015
 *      Author: Yaniv
 */

#ifndef BINENERGYPACKET_HPP_
#define BINENERGYPACKET_HPP_

#include <data_protocol/abstract_datatype/EnergyPacket.hpp>

class BinEnergyPacket: public EnergyPacket {
public:
	virtual ~BinEnergyPacket();
	BinEnergyPacket();
	virtual void toBytes(vector<char> &result);
};

#endif /* BINENERGYPACKET_HPP_ */
