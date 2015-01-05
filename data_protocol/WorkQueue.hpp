/*
 * WorkQueue.hpp
 *
 *  Created on: Apr 19, 2014
 *      Author: Genzel
 */

#ifndef WORKQUEUE_HPP_
#define WORKQUEUE_HPP_

using namespace std;

#include <vector>
#include <string>
#include <rtems.h>
#include "WorkDescription.hpp"

using namespace std;

#define QUEUE_SIZE			512

class WorkQueue {

private:
	// TODO change implmentation to NOT vector
	vector<WorkDescription::WorkDescription> works;
	rtems_id mutex_id;
	rtems_id produced_count_id;
	int size;

public:
	WorkQueue();
	~WorkQueue(){}
	void enqueue(WorkDescription::WorkDescription work);
	WorkDescription::WorkDescription dequeue(bool block);
	void sortWorks();
};


#endif /* WORKQUEUE_HPP_ */
