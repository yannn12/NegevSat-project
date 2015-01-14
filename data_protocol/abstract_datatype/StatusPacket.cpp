/*
 * StatusPacket.cpp
 *
 *  Created on: 11 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/abstract_datatype/StatusPacket.hpp>

StatusPacket::~StatusPacket() {
	// TODO Auto-generated destructor stub
}

StatusPacket::StatusPacket() {
	// TODO Auto-generated constructor stub

}

const vector<ComponentInfo>& StatusPacket::getComponentsInfo() const {
	return componentsInfo;
}

void StatusPacket::setComponentsInfo(
		const vector<ComponentInfo>& componentsInfo) {
	this->componentsInfo = componentsInfo;
}
