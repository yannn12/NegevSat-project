/*
 * TempsPacket.hpp
 *
 *  Created on: 12 αιπε 2015
 *      Author: Yaniv
 */

#ifndef TEMPSPACKET_HPP_
#define TEMPSPACKET_HPP_

#include <data_protocol/abstract_datatype/Packet.hpp>


typedef struct
{
	unsigned long long time;
 	int temperature;
} __attribute__((packed)) TempSample;



class TempsPacket: public Packet {
public:
	TempsPacket();
	virtual ~TempsPacket();
	virtual void toBytes(vector<char> &result) =0;
	vector<TempSample>& getTempSamples();
	void setTempSamples(const vector<TempSample>& tempSamples);

private:

	vector<TempSample> tempSamples;

};

#endif /* TEMPSPACKET_HPP_ */
