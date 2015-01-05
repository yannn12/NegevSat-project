/*
 * TempPacket.cpp
 *
 *  Created on: May 6, 2014
 *      Author: dariaz
 */

#include <data_protocol/TempPacket.hpp>
#include <sstream>
#include "third_party/rapidxml_print.hpp"

TempPacket::TempPacket(string _type) {
	type = _type;
}

TempPacket::~TempPacket() {
	clearSamples();
}

string TempPacket::packetToString(){
	string xml_as_string = "";
	print(back_inserter(xml_as_string),root);
	return xml_as_string;
}

