/*
 * BinCMDParser.hpp
 *
 *  Created on: 6 αιπε 2015
 *      Author: Yaniv
 */

#ifndef BINCMDPARSER_HPP_
#define BINCMDPARSER_HPP_

#include <data_protocol/ICMDParser.hpp>


class BinCMDParser: public ICMDParser {
public:
	virtual bool parsePacket(char* packet,int size,WorkDescription& result);
	bool IsParameterValid(unsigned long long ,char code,int priority,unsigned long long missionTime);
	virtual ~BinCMDParser();
	BinCMDParser();
};

#endif /* BINCMDPARSER_HPP_ */
