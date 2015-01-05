/*
 * timeutils.cpp
 *
 *  Created on: May 31, 2014
 *      Author: boris
 */

#include <utils/timeutils.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "logics/Global.hpp"

namespace timeutils {

unsigned long long time_to_long(){
	unsigned long long  l_year = (unsigned long long)current_time.year;
	unsigned long long factor = 10000000000ULL;
	unsigned long long  year = l_year * factor;
	unsigned long long  l_month = (unsigned long long )current_time.month;
	unsigned long long  month = l_month * 100000000;
	unsigned long long  l_day = (unsigned long long )current_time.day;
	unsigned long long  day = l_day * 1000000;
	unsigned long long  l_hour = (unsigned long long )current_time.hour;
	unsigned long long  hour = l_hour * 10000;
	unsigned long long  l_minute = (unsigned long long )current_time.minute;
	unsigned long long  minute = l_minute * 100;
	unsigned long long  l_seconds = (unsigned long long )current_time.second;
	unsigned long long  seconds = l_seconds;
	return year + month + day + hour + minute + seconds;
}

unsigned long long convert_time_chars_to_long(const char* chars){
	char* pEnd;
	unsigned long long time = strtoull(chars, &pEnd, 10);
	return time;
}

void print_time(char* _s1, rtems_time_of_day* _tb, char * _s2){
	printf( "%s%02d:%02d:%02d   %02d/%02d/%04d%s",_s1, (_tb)->hour, (_tb)->minute, (_tb)->second,(_tb)->month, (_tb)->day, (_tb)->year, _s2);
}
} /* namespace timeutlils */
