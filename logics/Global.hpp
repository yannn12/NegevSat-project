/*
 * Global.hpp
 *
 *  Created on: May 11, 2014
 *      Author: dariaz
 */

#ifndef GLOBAL_HPP_
#define GLOBAL_HPP_

#include <rtems++/rtemsTask.h>
#include "NegevSatConstants.hpp"

extern rtemsTask::rtemsTask* task_table[NUMBER_OF_TASKS];

extern rtems_time_of_day current_time;

#endif /* GLOBAL_HPP_ */
