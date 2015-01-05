/*
 * timeutils.hpp
 *
 *  Created on: May 31, 2014
 *      Author: boris
 */

#ifndef TIMEUTILS_HPP_
#define TIMEUTILS_HPP_

#include <rtems.h>

using namespace std;

namespace timeutils {

unsigned long long time_to_long();
unsigned long long convert_time_chars_to_long(const char*);
void print_time(char* _s1, rtems_time_of_day* _tb, char * _s2);


} /* namespace timeutlils */

#endif /* TIMEUTILS_HPP_ */
