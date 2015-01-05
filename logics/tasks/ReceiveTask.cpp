/*
 * ReceiveTask.cpp
 *
 *  Created on: May 8, 2014
 *      Author: dariaz
 */

#include <logics/tasks/ReceiveTask.hpp>
#include "communication/CommunicationHandlerFactory.hpp"
#include "logics/NegevSatConstants.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <rtems++/rtemsEvent.h>

using namespace std;

ReceiveTask::ReceiveTask(SendReceiveQueue::SendReceiveQueue* receiveQ) {
	receive_queue = receiveQ;
	CommunicationHandlerFactory::CommunicationHandlerFactory factory;
	comm_handler = factory.createHandler("uart");
	connected = false;
}

ReceiveTask::~ReceiveTask() {
	// TODO Auto-generated destructor stub
}

string ReceiveTask::receive(){
	return comm_handler->receive();
}

void ReceiveTask::enqueue_message(string msg){
	receive_queue->enqueue(msg);
}

void ReceiveTask::obtain_state(){
	//printf(" * SendTask TASK:: obtain_state *\n");
	rtemsEvent event;
	rtems_event_set out;
	rtems_status_code status = event.receive(REGULAR_OPS_STATE_EVENT | FACING_GROUND_STATE_EVENT, out, 0, rtemsEvent::no_wait, rtemsEvent::any);
	if (status == RTEMS_SUCCESSFUL){
		printf(" * SEND TASK:: changed state to %d *\n", (int)out);
		switch (out){
		case REGULAR_OPS_STATE_EVENT:
			connected = false;
			break;
		case FACING_GROUND_STATE_EVENT:
			connected = true;
		}
	}
}


rtems_task ReceiveTask::body(rtems_task_argument argument){
	for(;;) {
		printf(" * RECEIVE TASK! *\n");
		rtems_task_wake_after(
				1 * 2 * rtems_clock_get_ticks_per_second());
		//obtain_state();
		string msg = receive();
		if (comm_handler->verifyBytes(msg)){
			enqueue_message(msg);
		}
		else {
			printf(" * RECEIVE TASK:: bytes which were received are not verified *\n");
		}

	}
	printf(" * RECEIVE TASK:: exiting... *\n");
	exit(0);
}

