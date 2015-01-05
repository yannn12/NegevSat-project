/*
 * TempPacket.hpp
 *
 *  Created on: May 6, 2014
 *      Author: dariaz
 */

#ifndef TEMPPACKET_HPP_
#define TEMPPACKET_HPP_

#include "third_party/rapidxml.hpp"
#include <vector>
#include "data_protocol/Sample.hpp"
#include <string>

using namespace std;
using namespace rapidxml;

class TempPacket {

private:

	string type;
	xml_document<> root;
	xml_node<>* sampling_node;
	vector<Sample::Sample*> samples;

public:
	TempPacket(string _type);

	xml_document<>* getRoot(){
		return &root;
	}

	void setSamplingNode(xml_node<>* node){
		sampling_node = node;
	}

	void addSample(Sample::Sample* s){
		samples.push_back(s);
	}

	void clearSamples(){
		for (unsigned int i=0; i<samples.size(); i++){
			delete(samples.at(i));
		}
	}

	string getType(){
		return type;
	}

	xml_node<>* getSamplingNode(){
		return sampling_node;
	}

	string packetToString();

	virtual ~TempPacket();
};

#endif /* TEMPPACKET_HPP_ */
