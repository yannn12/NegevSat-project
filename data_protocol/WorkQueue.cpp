/*
 * WorkQueue.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Genzel
 */

#include "WorkQueue.hpp"
#include <algorithm>
#include <assert.h>
#include "data_protocol/CMDDictionary.hpp"
#include <stdio.h>


using namespace std;

bool workComparator (WorkDescription::WorkDescription i,WorkDescription::WorkDescription j) {
	return (i.getTimestamp()>j.getTimestamp());
}

WorkQueue::WorkQueue(){
	works.reserve(QUEUE_SIZE);
	size = 0;

	rtems_status_code status;
	// create semaphore with 1 permit
	status = rtems_semaphore_create(
			rtems_build_name( 'W', 'K', 'Q', '1' ),
			1,
			RTEMS_DEFAULT_ATTRIBUTES,
			0,
			&mutex_id
	);
	assert( status == RTEMS_SUCCESSFUL );
	status = rtems_semaphore_create(
			rtems_build_name( 'W', 'K', 'Q', '2' ),
			0,   /*created locked*/
			RTEMS_DEFAULT_ATTRIBUTES,
			0,
			&produced_count_id
	);
	assert( status == RTEMS_SUCCESSFUL );

}

void WorkQueue::sortWorks(){
	sort (works.begin(), works.end(),workComparator);
}

void WorkQueue::enqueue(WorkDescription::WorkDescription work){
	rtems_status_code status;
	bool should_release = false;
	// Semaphore not available, ensured to block
	status = rtems_semaphore_obtain(
			mutex_id,
			RTEMS_DEFAULT_OPTIONS,
			RTEMS_NO_TIMEOUT
	);
	if (size < QUEUE_SIZE){
		works.push_back(work);
		size++;
		should_release = true;
	}
	else {
		works.erase(works.begin());
		works.push_back(work);
	}
	//sortWorks();
	if (should_release)
		status = rtems_semaphore_release( produced_count_id );
	status = rtems_semaphore_release( mutex_id );
}

WorkDescription::WorkDescription WorkQueue::dequeue(bool block){
	rtems_status_code status;
	if (block){
		status = rtems_semaphore_obtain(
				produced_count_id,
				RTEMS_DEFAULT_OPTIONS,
				RTEMS_NO_TIMEOUT
		);
		status = rtems_semaphore_obtain(
				mutex_id,
				RTEMS_DEFAULT_OPTIONS,
				RTEMS_NO_TIMEOUT
		);
	}
	else {
		status = rtems_semaphore_obtain(
				produced_count_id,
				RTEMS_WAIT,
				100
		);
		if (status != RTEMS_SUCCESSFUL){
			WorkDescription::WorkDescription null_work;
			null_work.setCode(NULL_WORK);
			return null_work;
		}
		status = rtems_semaphore_obtain(
				mutex_id,
				RTEMS_DEFAULT_OPTIONS,
				RTEMS_NO_TIMEOUT
		);
	}

	WorkDescription::WorkDescription work = works.back();
	works.pop_back();
	size--;
	status = rtems_semaphore_release( mutex_id );
	return work;
}


