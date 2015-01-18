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
#include "data_protocol/xml_protocol/XmlCMDParser.hpp"
#include <data_protocol/binary_protocol/BinCMDParser.hpp>


using namespace std;

MPTask::MPTask(SendReceiveQueue::SendReceiveQueue* receiveQ, WorkQueue::WorkQueue* _works) {
	receive_queue = receiveQ;
	works = _works;
	parser = new BinCMDParser();
}

MPTask::~MPTask() {
	// TODO Auto-generated destructor stub
}



void MPTask::enqueueToWorks(WorkDescription::WorkDescription work){
	works->enqueue(work);
}

void MPTask::body(rtems_task_argument argument){
	for (;;){
		printf(" * MP TASK! *\n");
		vector<char> packet = receive_queue->dequeue();
		WorkDescription work;

		if(!parser->parsePacket(&packet[0],packet.size(),work)){
			printf(" * MP TASK:: validation of packet:\n %s \n FAILED!!!*\n", &packet[0]);
		}
		enqueueToWorks(work);
	}

	exit(0);
}

