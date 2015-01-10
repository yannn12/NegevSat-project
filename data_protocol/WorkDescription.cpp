/*
 * WorkDescription.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Genzel
 */

using namespace std;

#include "WorkDescription.hpp"

WorkDescription::WorkDescription(){

}

WorkDescription::WorkDescription (unsigned long long _timestamp,char _code, int _priority, unsigned long long _time){
	code = _code;
	priority = _priority;
	timestamp = _timestamp;
	missionTime=_time;
}

void WorkDescription::setCode(char _code){
	code = _code;
}

char WorkDescription::getCode(){
	return code;
}

void WorkDescription::setPriority(int _priority){
	priority = _priority;
}

int WorkDescription::getPriority(){
	return priority;
}

void WorkDescription::setTimeStamp(unsigned long long _timestamp){
	timestamp = _timestamp;
}

unsigned long long WorkDescription::getTimestamp(){
	return timestamp;
}
void WorkDescription::setMissionTime(unsigned long long _missionTime){
	missionTime=_missionTime;
}
	unsigned long long WorkDescription::getMissionTime(){
		return missionTime;
}
