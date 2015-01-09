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
#include "data_protocol/xml_protocol/XMLValidator.hpp"
#include "data_protocol/CMDParser.hpp"
#include "data_protocol/ICMDParser.hpp"
#include "data_protocol/WorkDescription.hpp"
#include "data_protocol/WorkQueue.hpp"
#include <string>
#include <vector>

using namespace std;

class MPTask : public rtemsTask  {

private:
	SendReceiveQueue::SendReceiveQueue* receive_queue;
	WorkQueue::WorkQueue* works;
	ICMDParser *parser;

protected:
	virtual void body(rtems_task_argument argument);

public:
	MPTask(SendReceiveQueue::SendReceiveQueue* receiveQ, WorkQueue::WorkQueue* _works);
	void enqueueToWorks(WorkDescription::WorkDescription work);
	virtual ~MPTask();
};

#endif /* MPTASK_HPP_ */
