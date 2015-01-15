/*
 * XmlStatusPacket.hpp
 *
 *  Created on: 14 αιπε 2015
 *      Author: Yaniv
 */

#ifndef XMLSTATUSPACKET_HPP_
#define XMLSTATUSPACKET_HPP_

#include <data_protocol/abstract_datatype/StatusPacket.hpp>

class XmlStatusPacket: public StatusPacket {
public:
	XmlStatusPacket();
	virtual ~XmlStatusPacket();
	virtual void toBytes(vector<char> &result);
};

#endif /* XMLSTATUSPACKET_HPP_ */
