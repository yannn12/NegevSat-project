/*
 * CMDTask.hpp
 *
 *  Created on: May 8, 2014
 *      Author: dariaz
 */

#ifndef CMDTASK_HPP_
#define CMDTASK_HPP_

#include <rtems++/rtemsTask.h>
#include "data_protocol/WorkDescription.hpp"
#include "data_protocol/WorkQueue.hpp"
#include <string>
#include <vector>

using namespace std;

class CMDTask : public rtemsTask {
private:
	WorkQueue::WorkQueue* works;
	WorkQueue::WorkQueue* rdy_works;
protected:
	virtual void body(rtems_task_argument argument);
public:
	CMDTask(WorkQueue::WorkQueue* _works, WorkQueue::WorkQueue* _rdy_works);
	void schedule_work(WorkDescription::WorkDescription work);
	bool time_has_come(WorkDescription::WorkDescription work);
	virtual ~CMDTask();
};

#endif /* CMDTASK_HPP_ */
