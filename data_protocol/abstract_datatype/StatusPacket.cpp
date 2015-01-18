/*
 * StatusPacket.cpp
 *
 *  Created on: 11 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/abstract_datatype/StatusPacket.hpp>
#include <utils/timeutils.hpp>
#include <utils/stringutils.hpp>

StatusPacket::~StatusPacket() {
	// TODO Auto-generated destructor stub
}

StatusPacket::StatusPacket() {
	// TODO Auto-generated constructor stub

}

vector<ComponentInfo>& StatusPacket::getComponentsInfo() {
	return componentsInfo;
}

void StatusPacket::setComponentsInfo(
		const vector<ComponentInfo>& componentsInfo) {
	this->componentsInfo = componentsInfo;
}

