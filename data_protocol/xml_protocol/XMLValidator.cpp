/*
 * Validator.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Genzel
 */

#include "data_protocol/IValidator.hpp"
#include "third_party/rapidxml.hpp"
#include "third_party/rapidxml_print.hpp"
#include "XMLValidator.hpp"
#include <string>
#include <vector>
#include <stdio.h>
#include "logics/NegevSatConstants.hpp"

using namespace std;
using namespace rapidxml;

XMLValidator::XMLValidator() {
	first_use = true;
}

bool XMLValidator::buildPacket(const string& packet){
	vector<char> xml_copy(packet.begin(), packet.end());
	xml_copy.push_back('\0');
	if (!first_use)
		root.clear();
	try {
		root.parse<parse_declaration_node | parse_no_data_nodes>(&xml_copy[0]);
		first_use = false;
	}
	catch(rapidxml::parse_error &e)
	{
		printf("XML build packet failed - %s\n", e.what());
		return false;
	}
	return true;
}

bool XMLValidator::validate(){
	//TODO find out how ?!?!
	xml_node<>* packet_element = root.first_node(PACKET_STR);
	if (packet_element == 0){
		printf("XMLValidator:: the xml does not contain packet first element\n");
		return false;
	}
	if( root.last_node() != packet_element){
		printf("XMLValidator:: there should be only 1 packet main element\n");
		return false;
	}
	xml_node<>* upstream = packet_element->first_node(UP_PACKET_STR);
	if (upstream == 0){
		printf("XMLValidator:: the packet does not contain upstreamPacket element\n");
		return false;
	}
	if (upstream->first_attribute(TIME_STR) == 0){
		printf("XMLValidator:: upstreamPacket element does not have time\n");
		return false;
	}
	if (packet_element->last_node() != upstream){
		printf("XMLValidator:: there should be only 1 upstream node inside packet element\n");
		return false;
	}
	int mission_count = 0;
	for (xml_node<>* mission_node = upstream->first_node(); mission_node; mission_node = mission_node->next_sibling()){
		mission_count++;
		if (strcmp(mission_node->name(), MISSION_STR)){
			printf("XMLValidator:: upstream child is not mission\n");
			return false;
		}
		if (mission_node->first_attribute(TIME_STR) == 0){
			printf("XMLValidator:: mission #%d element does not have time\n", mission_count);
			return false;
		}
		if (mission_node->first_attribute(OPCODE_STR) == 0){
			printf("XMLValidator:: mission #%d element does not have opcode\n", mission_count);
			return false;
		}
		if (mission_node->first_attribute(PRIORITY_STR) == 0){
			printf("XMLValidator:: mission #%d element does not have priority\n", mission_count);
			return false;
		}
	}
	if (mission_count == 0){
		printf("XMLValidator:: no missions\n");
		return false;
	}
	return true;
}

void* XMLValidator::getRoot(){
	return &root;
}
