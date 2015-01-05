/*
 * Sample.cpp
 *
 *  Created on: Apr 19, 2014
 *      Author: Genzel
 */

#include "Sample.hpp"


using namespace std;

Sample::Sample(string _name, string _time){
	name = _name;
	time = _time;
}

void Sample::addMeasure(string name, map<string,string> values){
	measures.insert(pair<string,map<string,string> >(name,values));
}

string Sample::getName(){
	return name;
}

string Sample::getTime(){
	return time;
}

map<string,map<string,string> > Sample::getMeasures(){
	return measures;
}
