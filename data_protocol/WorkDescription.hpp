/*
 * WorkDescription.hpp
 *
 *  Created on: Apr 18, 2014
 *      Author: Genzel
 */

#ifndef WORKDESCRIPTION_HPP_
#define WORKDESCRIPTION_HPP_

class WorkDescription {
private:
	unsigned long long timestamp;
	char code;
	int priority;
	unsigned long long missionTime;

	//TODO: add work params

public:
	WorkDescription ();
	WorkDescription (unsigned long long _timestamp,char _code, int _priority, unsigned long long _time);
	~WorkDescription(){}
	void setCode(char _code);
	char getCode();
	void setPriority(int _priority);
	int getPriority();
	void setTimeStamp(unsigned long long _timestamp);
	unsigned long long getTimestamp();
	void setMissionTime(unsigned long long _missionTime);
	unsigned long long getMissionTime();

};


#endif /* WORKDESCRIPTION_HPP_ */
