/*
 * BinTempsPacket.hpp
 *
 *  Created on: 14 αιπε 2015
 *      Author: Yaniv
 */

#ifndef BINTEMPSPACKET_HPP_
#define BINTEMPSPACKET_HPP_

#include <data_protocol/abstract_datatype/TempsPacket.hpp>

class BinTempsPacket: public TempsPacket {
public:
	BinTempsPacket();
	virtual ~BinTempsPacket();
	virtual void toBytes(vector<char> &result);
};

#endif /* BINTEMPSPACKET_HPP_ */
