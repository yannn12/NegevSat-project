/*
 * ICMDParser.h
 *
 *  Created on: 5 αιπε 2015
 *      Author: Yaniv
 */

#ifndef ICMDPARSER_HPP_
#define ICMDPARSER_HPP_

#include <vector>
#include "WorkDescription.hpp"

using namespace std;

class ICMDParser {
public:
	virtual bool parsePacket(char* packet,int size,WorkDescription& result) =0;
	virtual ~ICMDParser(){}
};

#endif /* ICMDPARSER_H_ */
