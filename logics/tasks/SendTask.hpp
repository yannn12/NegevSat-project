/*
 * SendTask.hpp
 *
 *  Created on: Apr 26, 2014
 *      Author: dariaz
 */

#ifndef SENDTASK_HPP_
#define SENDTASK_HPP_

#include "communication/SendReceiveQueue.hpp"
#include "communication/UartCommunicationHandler.hpp"
#include <rtems++/rtemsTask.h>

#define PACKET_COUNTER_LIMIT	10

class SendTask : public rtemsTask
{
private:
	ICommunicationHandler::ICommunicationHandler* comm_handler;
	SendReceiveQueue::SendReceiveQueue** sendQueues;
	int send_type;
	int packet_counter;
	bool connected;

protected:
	virtual void body(rtems_task_argument argument);

public:
	SendTask(SendReceiveQueue::SendReceiveQueue** sendQ);
	void obtain_state();
	void obtain_send_type();
	void send(string packet);
	string dequeueMessage(int index);
};
#endif /* SENDTASK_HPP_ */


