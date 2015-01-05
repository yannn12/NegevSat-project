/*
 * CMDParser.hpp
 *
 *  Created on: Apr 18, 2014
 *      Author: Genzel
 */

#ifndef CMDPARSER_HPP_
#define CMDPARSER_HPP_

#include <vector>
#include "WorkDescription.hpp"

using namespace std;

class CMDParser {
private:

public:
	CMDParser ();
	~CMDParser(){}
	vector<WorkDescription::WorkDescription> parsePacket(void* packet);
};

#endif /* CMDPARSER_HPP_ */
