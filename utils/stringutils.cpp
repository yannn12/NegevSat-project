/*
 * stringutils.cpp
 *
 *  Created on: May 9, 2014
 *      Author: dariaz
 */

#include <utils/stringutils.hpp>
using namespace std;

namespace stringutils{

string int_to_string(int number, string str){
	stringstream out;
	out << number;
	str = out.str();
	return str;
}

string unsigned_long_to_string(unsigned long long number, string str){
	stringstream ss;
	ss << number;
	str = ss.str();
	return str;
}

char* int_to_chars(int number, char* buf){
	sprintf(buf, "%d", number);
	return buf;
}

const char* state_to_chars (int state){
	switch (state){
	case INIT_STATE:
		return INIT_STATE_STR;
	case STANDBY_STATE:
		return STANDBY_STATE_STR;
	case SAFE_STATE:
		return SAFE_STATE_STR;
	case REGULAR_OPS_STATE:
		return REGULAR_OPS_STATE_STR;
	case FACING_GROUND_STATE:
		return FACING_GROUND_STATE_STR;
	default:
		printf("ILLEGAL STATE");
		// TODO throw exception!
		return "ILLEGAL_STATE";
	}
}

const char* module_state_to_chars(int state){
	switch (state){
	case MODULE_ON:
		return MODULE_ON_STR;
	case MODULE_MALFUNCTION:
		return MODULE_MALFUNCTION_STR;
	case MODULE_NON_OPERATIONAL:
		return MODULE_NON_OPERATIONAL_STR;
	case MODULE_STANDBY:
		return MODULE_STANDBY_STR;
	default:
		printf("ILLEGAL STATE");
		// TODO throw exception!
		return "ILLEGAL_STATE";
	}
}

string trim_spaces_tabs_newlines(string s){
	s.erase(remove(s.begin(), s.end(), '\t'), s.end());
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
	s.erase(remove(s.begin(), s.end(), '\n'), s.end());
	return s;
}

}


