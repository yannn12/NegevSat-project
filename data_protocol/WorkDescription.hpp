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
	int code;
	int priority;
	unsigned long long timestamp;
	//TODO: add work params

public:
	WorkDescription ();
	WorkDescription (int _code, int _priority, unsigned long long _time);
	~WorkDescription(){}
	void setCode(int _code);
	int getCode();
	void setPriority(int _priority);
	int getPriority();
	void setTimeStamp(unsigned long long _timestamp);
	unsigned long long getTimestamp();
};


#endif /* WORKDESCRIPTION_HPP_ */
