/*
 * XmlStatusPacket.cpp
 *
 *  Created on: 14 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/xml_protocol/XmlStatusPacket.hpp>

#include "utils/stringutils.hpp"

#include "third_party/rapidxml.hpp"

#include "third_party/rapidxml_print.hpp"

using namespace stringutils;

using  namespace rapidxml;

XmlStatusPacket::XmlStatusPacket() {
	// TODO Auto-generated constructor stub

}

XmlStatusPacket::~XmlStatusPacket() {
	// TODO Auto-generated destructor stub
}

void XmlStatusPacket::toBytes(vector<char>& result) {
	xml_document<> root;
	// xml declaration
	xml_node<>* dec = root.allocate_node(node_declaration);
	dec->append_attribute(root.allocate_attribute(XML_VERSION, XML_VERSION_NUM));
	dec->append_attribute(root.allocate_attribute(XML_ENCODING, XML_ENCODING_TYPE));
	root.append_node(dec);
	// packet node
	xml_node<>* first_node = root.allocate_node(node_element,PACKET_STR);
	root.append_node(first_node);
	// downstreamPacket node
	xml_node<>* downstreamPacket_node = root.allocate_node(node_element,DOWN_PACKET_STR);
	first_node->append_node(downstreamPacket_node);

	xml_node<>* type_node = root.allocate_node(node_element,TYPE_STR);
	type_node->value("Static");
	downstreamPacket_node->append_node(type_node);
	xml_node<>* state_node = root.allocate_node(node_element,STATE_STR);
	state_node->value("INIT_STATE");
	downstreamPacket_node->append_node(state_node);
	string* strArr = new string[this->getComponentsInfo().size()];
	for(unsigned int i=0;i<this->getComponentsInfo().size();i++){
		ComponentInfo compInfo = this->getComponentsInfo()[i];
		xml_node<>* sampleNode = root.allocate_node(node_element,"Module");
		string temp = "";
		sampleNode->append_attribute(root.allocate_attribute("time",unsigned_long_to_string(compInfo.time,strArr[i]).c_str()));


		xml_node<>* sampleNode2 = root.allocate_node(node_element,"Info");
		sampleNode2->append_attribute(root.allocate_attribute("name",ComponentStrings[compInfo.componentCode]));
		sampleNode2->append_attribute(root.allocate_attribute("status",StatusStrings[compInfo.status]));
		sampleNode->append_node(sampleNode2);
		downstreamPacket_node->append_node(sampleNode);

	}
	string xml_as_string = "";
	print(back_inserter(xml_as_string),root);
	vector<char> data(xml_as_string.begin(), xml_as_string.end());
	data.push_back('\0');
	delete[] strArr;
	result = data;
}
