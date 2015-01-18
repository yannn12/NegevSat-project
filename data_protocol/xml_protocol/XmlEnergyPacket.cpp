/*
 * XmlEnergyPacket.cpp
 *
 *  Created on: 14 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/xml_protocol/XmlEnergyPacket.hpp>

#include "third_party/rapidxml.hpp"
#include "third_party/rapidxml_print.hpp"

#include "utils/stringutils.hpp"



using namespace rapidxml;
using namespace stringutils;
using namespace std;

XmlEnergyPacket::XmlEnergyPacket() {
	// TODO Auto-generated constructor stub

}

XmlEnergyPacket::~XmlEnergyPacket() {
	// TODO Auto-generated destructor stub
}

void XmlEnergyPacket::toBytes(vector<char>& result) {
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
	type_node->value("Energy");
	downstreamPacket_node->append_node(type_node);

	string* strTimeArr = new string[this->getSamples().size()];
	string* strCurrArr = new string[this->getSamples().size()];
	string* strVoltArr = new string[this->getSamples().size()];
	for(unsigned int i=0;i<this->getSamples().size();i++){
		BattaryInfo battary = this->getSamples()[i];
		xml_node<>* sampleNode = root.allocate_node(node_element,"EnergySample");
		sampleNode->append_attribute(root.allocate_attribute("time",unsigned_long_to_string(battary.time,strTimeArr[i]).c_str()));
		xml_node<>* sampleNode2 = root.allocate_node(node_element,"Battery1");
		sampleNode2->append_attribute(root.allocate_attribute("current",int_to_string(battary.current,strCurrArr[i]).c_str()));
		sampleNode2->append_attribute(root.allocate_attribute("voltage",int_to_string(battary.voltage,strVoltArr[i]).c_str()));
		sampleNode->append_node(sampleNode2);
		downstreamPacket_node->append_node(sampleNode);

	}
	string xml_as_string = "";
	print(back_inserter(xml_as_string),root);
	vector<char> data(xml_as_string.begin(), xml_as_string.end());
	data.push_back('\0');
	delete[] strTimeArr;
	delete[] strCurrArr;
	delete[] strVoltArr;
	result = data;
}
