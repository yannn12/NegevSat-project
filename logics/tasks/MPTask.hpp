/*
 * MPTask.hpp
 *
 *  Created on: May 3, 2014
 *      Author: dariaz
 */

#ifndef MPTASK_HPP_
#define MPTASK_HPP_

#include <rtems++/rtemsEvent.h>
#include <rtems++/rtemsMessageQueue.h>
#include <rtems++/rtemsTask.h>
#include <rtems++/rtemsTaskMode.h>
#include "communication/SendReceiveQueue.hpp"
#include "data_protocol/XMLValidator.hpp"
#include "data_protocol/CMDParser.hpp"
#include "data_protocol/WorkDescription.hpp"
#include "data_protocol/WorkQueue.hpp"
#include <string>
#include <vector>

using namespace std;

class MPTask : public rtemsTask  {

private:
	SendReceiveQueue::SendReceiveQueue* receive_queue;
	IValidator::IValidator* validator;
	WorkQueue::WorkQueue* works;
	CMDParser::CMDParser parser;

protected:
	virtual void body(rtems_task_argument argument);

public:
	MPTask(SendReceiveQueue::SendReceiveQueue* receiveQ, WorkQueue::WorkQueue* _works);
	bool validateMessage();
	vector<WorkDescription::WorkDescription> parseMessage();
	void enqueueToWorks(WorkDescription::WorkDescription work);
	virtual ~MPTask();
};

#endif /* MPTASK_HPP_ */
