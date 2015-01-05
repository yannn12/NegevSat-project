/*
 * SendTask.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: Genzel
 */

#include "SendTask.hpp"
#include "communication/CommunicationHandlerFactory.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <rtems++/rtemsEvent.h>
#include "logics/SendReceiveConf.hpp"
#include "logics/Global.hpp"
#include "logics/NegevSatConstants.hpp"

using namespace std;

SendTask::SendTask(SendReceiveQueue::SendReceiveQueue** sendQ)
:rtemsTask()
{

	sendQueues = sendQ;
	CommunicationHandlerFactory::CommunicationHandlerFactory factory;
	comm_handler = factory.createHandler("uart");
	send_type = STATIC_SEND;
	packet_counter = 0;
	connected = false;
}

void SendTask::send(string packet){
	char start_char = 2;
	char end_char = 4;
	string to_send = "";
	to_send += start_char;
	to_send += packet;
	to_send += end_char;
	comm_handler->send(&to_send[0], to_send.length());
}

string SendTask::dequeueMessage(int index){
	return sendQueues[index]->dequeue();
}

void SendTask::obtain_state(){
	//printf(" * SendTask TASK:: obtain_state *\n");
	rtemsEvent event;
	rtems_event_set out;
	rtems_status_code status = event.receive(REGULAR_OPS_STATE_EVENT | FACING_GROUND_STATE_EVENT | STANDBY_STATE_EVENT, out, 0, rtemsEvent::no_wait, rtemsEvent::any);
	if (status == RTEMS_SUCCESSFUL){
		//printf(" * SEND TASK:: changed state to %d *\n", (int)out);
		if (out & STANDBY_STATE_EVENT){
			connected = false;
		}
		if (out & REGULAR_OPS_STATE_EVENT){
			connected = false;
		}
		if (out & FACING_GROUND_STATE_EVENT){
			connected = true;
		}
	}
}

void SendTask::obtain_send_type(){
	rtemsEvent send_type_event;
	rtems_event_set out;
	rtems_status_code status = send_type_event.receive((STATIC_SEND | ENERGY_SEND | TEMP_SEND | MIXED_SEND), out, 0, rtemsEvent::no_wait, rtemsEvent::any);
	if (status == RTEMS_SUCCESSFUL){
		//printf(" * SEND TASK:: changed send type to %d *\n", (int)out);
		send_type = out;
	}
}

rtems_task SendTask::body(rtems_task_argument argument){
	for (;;){
		//printf(" * SEND TASK! *\n");
		rtems_task_wake_after(
				1 * 2 * rtems_clock_get_ticks_per_second());
		obtain_state();
		obtain_send_type();
		if (connected){
			packet_counter++;
			string packet;
			switch (send_type) {
			case STATIC_SEND:
				//printf(" * SEND TASK:: type of send is STATIC_SEND *\n");
				packet = sendQueues[SENDQ_STATIC_INDEX]->dequeue();
				//printf("packet to send : %s\n", &packet[0]);
				send(packet);
				break;
			case ENERGY_SEND:
				//printf(" * SEND TASK:: type of send is ENERGY_SEND *\n");
				packet = sendQueues[SENDQ_ENERGY_INDEX]->dequeue();
				send(packet);
				if (packet_counter == PACKET_COUNTER_LIMIT){
					packet_counter = 0;
					packet = sendQueues[SENDQ_STATIC_INDEX]->dequeue();
					send(packet);
				}
				break;
			case TEMP_SEND:
				//printf(" * SEND TASK:: type of send is TEMP_SEND *\n");
				packet = sendQueues[SENDQ_TEMP_INDEX]->dequeue();
				send(packet);
				if (packet_counter == PACKET_COUNTER_LIMIT){
					packet_counter = 0;
					packet = sendQueues[SENDQ_STATIC_INDEX]->dequeue();
					send(packet);
				}
				break;
			case MIXED_SEND:
				//printf(" * SEND TASK:: type of send is MIXED_SEND *\n");
				packet = sendQueues[SENDQ_ENERGY_INDEX]->dequeue();
				send(packet);
				packet = sendQueues[SENDQ_TEMP_INDEX]->dequeue();
				send(packet);
				packet = sendQueues[SENDQ_STATIC_INDEX]->dequeue();
				send(packet);
				break;
			}
		}
	}
	exit(0);
}
