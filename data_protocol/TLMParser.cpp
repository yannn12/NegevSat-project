/*
 * TLMParser.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Genzel
 */

#include "TLMParser.hpp"
#include "third_party/rapidxml.hpp"
#include "third_party/rapidxml_print.hpp"
#include "logics/NegevSatConstants.hpp"
#include "Sample.hpp"
#include <string.h>


using namespace std;
using namespace rapidxml;

TLMParser::TLMParser (){

}

TempPacket::TempPacket* TLMParser::getPacket(string type){
	TempPacket::TempPacket* packet;
	unsigned int i;
	for (i=0 ; i < packets.size(); i++){
		if (type.compare(packets.at(i)->getType()) == 0){
			packet = packets.at(i);
		}
	}
	return packet;
}

void TLMParser::createPacket(const char* state, const char* type){
	// xml declaration
	TempPacket::TempPacket* packet = new TempPacket::TempPacket (type);
	xml_document<>* root = packet->getRoot();
	xml_node<>* dec = root->allocate_node(node_declaration);
	dec->append_attribute(root->allocate_attribute(XML_VERSION, XML_VERSION_NUM));
	dec->append_attribute(root->allocate_attribute(XML_ENCODING, XML_ENCODING_TYPE));
	root->append_node(dec);

	// packet node
	xml_node<>* first_node = root->allocate_node(node_element,PACKET_STR);
	root->append_node(first_node);

	// downstreamPacket node
	xml_node<>* downstreamPacket_node = root->allocate_node(node_element,DOWN_PACKET_STR);
	first_node->append_node(downstreamPacket_node);

	// type node
	xml_node<>* type_node = root->allocate_node(node_element,TYPE_STR);
	type_node->value(type);
	downstreamPacket_node->append_node(type_node);

	// sampling data node
	packet->setSamplingNode(downstreamPacket_node);

	if (!(strcmp(type,STATIC_STR))){
		// state node
		xml_node<>* state_node = root->allocate_node(node_element,STATE_STR);
		state_node->value(state);
		downstreamPacket_node->append_node(state_node);
	}
	packets.push_back(packet);
	//cout << "printing xml: " << endl << root;
}

void TLMParser::addSampleToPacket(Sample::Sample* sample,string type){
	//find the needed packet
	TempPacket::TempPacket* packet = getPacket(type);
	xml_document<>* root = packet->getRoot();
	// create sample node
	xml_node<>* sample_node = root->allocate_node(node_element,sample->getName().c_str());
	sample_node->append_attribute(root->allocate_attribute(TIME_STR, sample->getTime().c_str()));
	map<string , map<string,string> >::iterator pos;
	map<string , map<string,string> > measures = sample->getMeasures();
	for (pos = measures.begin(); pos != measures.end(); ++pos){
		xml_node<>* node = root->allocate_node(node_element,pos->first.c_str());
		map<string , string>::iterator attr_pos;
		map<string , string>* attrs = &pos->second;
		for (attr_pos = attrs->begin(); attr_pos != attrs->end(); ++attr_pos){
			node->append_attribute(root->allocate_attribute(attr_pos->first.c_str(), attr_pos->second.c_str()));
		}
		sample_node->append_node(node);
	}
	packet->getSamplingNode()->append_node(sample_node);
	packet->addSample(sample);
	//delete(sample);
}

void TLMParser::removePacket(string type){
	unsigned int i;
	unsigned int index;
	TempPacket::TempPacket* packet;
	for (i=0; i<packets.size(); i++){
		if (packets.at(i)->getType().compare(type) == 0) {
			index = i;
			packet = packets.at(i);
			break;
		}
	}
	packets.erase(packets.begin() + index);
	delete(packet);
}

