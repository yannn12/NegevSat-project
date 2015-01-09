/*
 * XmlCMDParser.hpp
 *
 *  Created on: 6 αιπε 2015
 *      Author: Yaniv
 */

#ifndef XMLCMDPARSER_HPP_
#define XMLCMDPARSER_HPP_
#include <data_protocol/ICMDParser.hpp>
#include "data_protocol/IValidator.hpp"
#include "third_party/rapidxml.hpp"
#include "data_protocol/xml_protocol/XMLValidator.hpp"

using namespace std;
using namespace rapidxml;

class XmlCMDParser: public ICMDParser {
public:
	virtual bool parsePacket(char* packet,int size,WorkDescription& result);
	virtual ~XmlCMDParser();
	XmlCMDParser();
};

#endif /* XMLCMDPARSER_HPP_ */
