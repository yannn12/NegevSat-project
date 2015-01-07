/*
 * SendReceiveQueue.hpp
 *
 *  Created on: Apr 8, 2014
 *      Author: Genzel
 */

#ifndef SENDRECEIVEQUEUE_HPP_
#define SENDRECEIVEQUEUE_HPP_

#include <deque>
#include <queue>
#include <string>
#include <rtems.h>
#include <rtems++/rtemsSemaphore.h>

using namespace std;

#define SEND_RECEIVE_QUEUE_SIZE				2048

class SendReceiveQueue {

private:
	int size;
	deque<vector<char> > pending_messages;
	rtems_id mutex_id;
	rtems_id produced_count_id;

public:
	SendReceiveQueue ();
	~SendReceiveQueue(){}
	void enqueue(vector<char> message);
	vector<char> dequeue();
	void enqueue(string message);
	string dequeuestr();

};


#endif /* SENDRECEIVEQUEUE_HPP_ */
