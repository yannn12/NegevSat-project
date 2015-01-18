/*
 * EnergyPacket.hpp
 *
 *  Created on: 12 αιπε 2015
 *      Author: Yaniv
 */

#ifndef ENERGYPACKET_HPP_
#define ENERGYPACKET_HPP_

#include <data_protocol/abstract_datatype/Packet.hpp>

typedef struct
{
	unsigned long long time;
	int current;
 	int voltage;
} __attribute__((packed)) BattaryInfo;


class EnergyPacket: public Packet {
public:
	virtual void toBytes(vector<char> &result) =0;
	virtual ~EnergyPacket();
	vector<BattaryInfo>& getSamples();
	void setSamples(const vector<BattaryInfo>& samples);

private:
	vector<BattaryInfo> samples;
};

#endif /* ENERGYPACKET_HPP_ */
