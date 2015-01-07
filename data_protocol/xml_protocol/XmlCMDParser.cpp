/*
 * XmlCMDParser.cpp
 *
 *  Created on: 6 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/xml_protocol/XmlCMDParser.hpp>
#include "third_party/rapidxml.hpp"
#include "third_party/rapidxml_print.hpp"
#include "logics/NegevSatConstants.hpp"
#include <vector>
#include "utils/timeutils.hpp"
using namespace timeutils;


bool XmlCMDParser::parsePacket(char* packet,int size,WorkDescription& result){
	string strpacket(packet,size);
	XMLValidator validator;
	validator.buildPacket(strpacket);
	if(!validator.validate())
		return false;

	xml_node<>* root_element = ((xml_document<>*)validator.getRoot() )->first_node(PACKET_STR);
	//cout << "root node is " << root_element->name() << endl;
	xml_node<>* upstream = root_element->first_node(UP_PACKET_STR);
	unsigned long long timestamp = convert_time_chars_to_long(upstream->first_attribute(TIME_STR)->value());
	//int timestamp = atoi(upstream->first_attribute(TIME_STR)->value());
	//cout << "upstream node is " << upstream->name() << endl;
	for (xml_node<>* mission_node = upstream->first_node(MISSION_STR); mission_node; mission_node = mission_node->next_sibling()){
		//cout << "opcode is " << mission_node->first_attribute("opcode")->value() << endl;
		result.setCode(atoi(mission_node->first_attribute(OPCODE_STR)->value()));
		//cout << "priority is " << mission_node->first_attribute("priority")->value() << endl;
		result.setPriority(atoi(mission_node->first_attribute(PRIORITY_STR)->value()));
		//cout << "time is " << mission_node->first_attribute("time")->value() << endl;
		//work.setTimeStamp(atoi(mission_node->first_attribute(TIME_STR)->value()));
		result.setTimeStamp(convert_time_chars_to_long(mission_node->first_attribute(TIME_STR)->value()));

	}
	return true;
}

XmlCMDParser::~XmlCMDParser() {
	// TODO Auto-generated destructor stub
}

XmlCMDParser::XmlCMDParser() {
	// TODO Auto-generated constructor stub

}

