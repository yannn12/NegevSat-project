/*
 * BinStatusPacket.hpp
 *
 *  Created on: 12 αιπε 2015
 *      Author: Yaniv
 */

#ifndef BINSTATUSPACKET_HPP_
#define BINSTATUSPACKET_HPP_

#include <data_protocol/abstract_datatype/StatusPacket.hpp>

class BinStatusPacket: public StatusPacket {
public:
	BinStatusPacket();
	virtual ~BinStatusPacket();
	virtual void toBytes(vector<char> &result);
};

#endif /* BINSTATUSPACKET_HPP_ */
