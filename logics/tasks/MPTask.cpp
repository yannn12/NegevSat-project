/*
 * MPTask.cpp
 *
 *  Created on: May 3, 2014
 *      Author: dariaz
 */

#include <logics/tasks/MPTask.hpp>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <rtems++/rtemsEvent.h>
#include "data_protocol/ValidatorFactory.hpp"

using namespace std;

MPTask::MPTask(SendReceiveQueue::SendReceiveQueue* receiveQ, WorkQueue::WorkQueue* _works) {
	receive_queue = receiveQ;
	works = _works;
	ValidatorFactory::ValidatorFactory factory;
	validator = factory.createValidator("XML");
}

MPTask::~MPTask() {
	// TODO Auto-generated destructor stub
}

bool MPTask::validateMessage(){
	return validator->validate();
}

vector<WorkDescription::WorkDescription> MPTask::parseMessage(){
	return parser.parsePacket(validator->getRoot());
}

void MPTask::enqueueToWorks(WorkDescription::WorkDescription work){
	works->enqueue(work);
}

void MPTask::body(rtems_task_argument argument){
	for (;;){
		printf(" * MP TASK! *\n");
		string packet = receive_queue->dequeue();
		if (!validator->buildPacket(packet)){
			printf(" * MP TASK:: build packet FAILED!!!*\n");
			continue;
		}
		if (validateMessage()){
			vector<WorkDescription::WorkDescription> parsed_works = parseMessage();
			for (unsigned int i=0; i<parsed_works.size(); i++){
				enqueueToWorks(parsed_works.at(i));
			}
		}
		else {
			printf(" * MP TASK:: validation of packet:\n %s \n FAILED!!!*\n", &packet[0]);
		}
	}

	exit(0);
}

