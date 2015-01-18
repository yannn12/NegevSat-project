/*
 * XmlTempsPacket.cpp
 *
 *  Created on: 14 αιπε 2015
 *      Author: Yaniv
 */

#include <data_protocol/xml_protocol/XmlTempsPacket.hpp>

#include "third_party/rapidxml.hpp"

#include "utils/stringutils.hpp"

#include "third_party/rapidxml_print.hpp"

using namespace stringutils;

using  namespace rapidxml;

XmlTempsPacket::XmlTempsPacket() {
	// TODO Auto-generated constructor stub

}

XmlTempsPacket::~XmlTempsPacket() {
	// TODO Auto-generated destructor stub
}

void XmlTempsPacket::toBytes(vector<char>& result) {
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
	type_node->value("Temperature");
	downstreamPacket_node->append_node(type_node);
	string* strTimeArr = new string[this->getTempSamples().size()];
	string* strTempArr = new string[this->getTempSamples().size()];

	for(unsigned int i=0;i<this->getTempSamples().size();i++){
		TempSample tempSamples = this->getTempSamples()[i];
		xml_node<>* sampleNode = root.allocate_node(node_element,"TemperatureSample");
		string temp = "";
		sampleNode->append_attribute(root.allocate_attribute("time",unsigned_long_to_string(tempSamples.time,strTimeArr[i]).c_str()));
		xml_node<>* sampleNode2 = root.allocate_node(node_element,"Sensor1");
		sampleNode2->append_attribute(root.allocate_attribute("temp",int_to_string(tempSamples.temperature,strTempArr[i]).c_str()));
		sampleNode->append_node(sampleNode2);
		downstreamPacket_node->append_node(sampleNode);


	}
	string xml_as_string = "";
	print(back_inserter(xml_as_string),root);
	vector<char> data(xml_as_string.begin(), xml_as_string.end());
	data.push_back('\0');
	delete[] strTimeArr;
	delete[] strTempArr;
	result = data;
}
