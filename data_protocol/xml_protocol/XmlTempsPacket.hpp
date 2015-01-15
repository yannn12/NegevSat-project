/*
 * XmlTempsPacket.hpp
 *
 *  Created on: 14 αιπε 2015
 *      Author: Yaniv
 */

#ifndef XMLTEMPSPACKET_HPP_
#define XMLTEMPSPACKET_HPP_

#include <data_protocol/abstract_datatype/TempsPacket.hpp>

class XmlTempsPacket: public TempsPacket {
public:
	XmlTempsPacket();
	virtual ~XmlTempsPacket();
	virtual void toBytes(vector<char> &result);
};

#endif /* XMLTEMPSPACKET_HPP_ */
