/*
 * StateMachineTask.hpp
 *
 *  Created on: May 20, 2014
 *      Author: boris
 */

#ifndef STATEMACHINETASK_HPP_
#define STATEMACHINETASK_HPP_

#include <rtems++/rtemsTask.h>

#define NO_EVENT_RECEIVED				-1

using namespace std;

class StateMachineTask : public rtemsTask {
private:

protected:
	virtual void body(rtems_task_argument argument);

public:
	StateMachineTask();
	virtual ~StateMachineTask();
};

#endif /* STATEMACHINETASK_HPP_ */
