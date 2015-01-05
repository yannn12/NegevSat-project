/*
 * CMDParser.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Genzel
 */

#include "CMDParser.hpp"
#include "third_party/rapidxml.hpp"
#include "third_party/rapidxml_print.hpp"
#include "WorkDescription.hpp"
#include "logics/NegevSatConstants.hpp"
#include <vector>
#include "utils/timeutils.hpp"

using namespace timeutils;
using namespace std;
using namespace rapidxml;

CMDParser::CMDParser(){

}

vector<WorkDescription::WorkDescription> CMDParser::parsePacket(void* packet){
	vector<WorkDescription::WorkDescription> works;
	xml_node<>* root_element = ((xml_document<>*)packet)->first_node(PACKET_STR);
	//cout << "root node is " << root_element->name() << endl;
	xml_node<>* upstream = root_element->first_node(UP_PACKET_STR);
	unsigned long long timestamp = convert_time_chars_to_long(upstream->first_attribute(TIME_STR)->value());
	//int timestamp = atoi(upstream->first_attribute(TIME_STR)->value());
	//cout << "upstream node is " << upstream->name() << endl;
	for (xml_node<>* mission_node = upstream->first_node(MISSION_STR); mission_node; mission_node = mission_node->next_sibling()){
		WorkDescription::WorkDescription work;
		//cout << "opcode is " << mission_node->first_attribute("opcode")->value() << endl;
		work.setCode(atoi(mission_node->first_attribute(OPCODE_STR)->value()));
		//cout << "priority is " << mission_node->first_attribute("priority")->value() << endl;
		work.setPriority(atoi(mission_node->first_attribute(PRIORITY_STR)->value()));
		//cout << "time is " << mission_node->first_attribute("time")->value() << endl;
		//work.setTimeStamp(atoi(mission_node->first_attribute(TIME_STR)->value()));
		work.setTimeStamp(convert_time_chars_to_long(mission_node->first_attribute(TIME_STR)->value()));
		works.push_back(work);
	}
	return works;
}
