/*
 * CMDTask.cpp
 *
 *  Created on: May 8, 2014
 *      Author: dariaz
 */

#include <logics/tasks/CMDTask.hpp>
#include <stdio.h>
#include "utils/timeutils.hpp"
#include "logics/Global.hpp"

using namespace timeutils;

CMDTask::CMDTask(WorkQueue::WorkQueue* _works, WorkQueue::WorkQueue* _rdy_works){
	works = _works;
	rdy_works = _rdy_works;
}

CMDTask::~CMDTask() {
	// TODO Auto-generated destructor stub
}

void CMDTask::schedule_work(WorkDescription::WorkDescription work){
	rdy_works->enqueue(work);
}

bool CMDTask::time_has_come(WorkDescription::WorkDescription work){
	rtems_clock_get_tod( &current_time);
	unsigned long long curr_time = time_to_long();
	if (work.getTimestamp() == 0)
		return true;
	if (curr_time >= work.getTimestamp()){
		return true;
	}
	return false;
}

void CMDTask::body(rtems_task_argument argument){
	for (;;){
		printf(" * CMD TASK! *\n");
		works->sortWorks();
		WorkDescription::WorkDescription work = works->dequeue(true);
		if (time_has_come(work)){
			rdy_works->enqueue(work);
		}
		else {
			works->enqueue(work);
		}

	}
}
