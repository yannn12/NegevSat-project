/*
 * Packet.hpp
 *
 *  Created on: 11 αιπε 2015
 *      Author: Yaniv
 */

#ifndef PACKET_HPP_
#define PACKET_HPP_

#include <vector>
using namespace std;

class Packet {
public:
	virtual void toBytes(vector<char> &result) =0;
	virtual ~Packet(){};
};

#endif /* PACKET_HPP_ */
