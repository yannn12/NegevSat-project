/*
 * Sample.hpp
 *
 *  Created on: Apr 19, 2014
 *      Author: Genzel
 */

#ifndef SAMPLE_HPP_
#define SAMPLE_HPP_

#include <string>
#include <map>

using namespace std;

class Sample {
private:
	string name;
	string time;
	map<string,map<string,string> > measures;

public:
	Sample(string _name, string time);
	~Sample(){}
	void addMeasure(string name, map<string,string> values);
	string getName();
	string getTime();
	map<string,map<string,string> > getMeasures();

};


#endif /* SAMPLE_HPP_ */
