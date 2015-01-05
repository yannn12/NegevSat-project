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

WorkDescription::WorkDescription (int _code, int _priority, unsigned long long _time){
	code = _code;
	priority = _priority;
	timestamp = _time;
}

void WorkDescription::setCode(int _code){
	code = _code;
}

int WorkDescription::getCode(){
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
