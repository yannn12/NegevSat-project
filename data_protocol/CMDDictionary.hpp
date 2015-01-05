/*
 * CMDDictionary.hpp
 *
 *  Created on: May 6, 2014
 *      Author: dariaz
 */

#ifndef CMDDICTIONARY_HPP_
#define CMDDICTIONARY_HPP_

#define NULL_WORK				0

#define MOVE_TO_SAFE			1
#define MOVE_TO_STANDBY			2
#define MOVE_TO_OP				3
#define FORMAT_ENERGY			4
#define FORMAT_TEMP				5
#define FORMAT_STATIC			6
#define FORMAT_MIXED			7
#define SBAND_ON				8
#define SBAND_STANDBY			9
#define PAYLOAD_ON				10
#define PAYLOAD_STANDBY			11
#define THERMAL_CTRL_ON			12
#define THERMAL_CTRL_STANDBY	13

// simulation commands
#define SET_TEMPERATURE			100
#define SET_ENERGY				101
#define CONNECTED				102
#define DISCONNECTED			103

#endif /* CMDDICTIONARY_HPP_ */
