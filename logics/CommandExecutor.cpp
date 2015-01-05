/*
 * CommandExecutor.cpp
 *
 *  Created on: May 10, 2014
 *      Author: dariaz
 */

#include <logics/CommandExecutor.hpp>
#include <stdio.h>
#include <rtems++/rtemsEvent.h>
#include "logics/tasks/SendTask.hpp"


CommandExecutor::CommandExecutor() {
}

CommandExecutor::~CommandExecutor() {
	// TODO Auto-generated destructor stub
}

void CommandExecutor::setModulesRequest(ModulesOperationRequest::ModulesOperationRequest* _modules_request){
	modules_request = _modules_request;
}

void CommandExecutor::execute(WorkDescription::WorkDescription work){
	if (modules_request == 0){
		printf (" * LifeCycle TASK::CommandExecutor:please set the hardware! exiting... *\n");
		return;
	}
	int opcode = work.getCode();
	rtemsEvent send_event;
	rtems_event_set out;
	rtems_status_code status;
	switch (opcode){
	case MOVE_TO_SAFE:
		printf(" * LifeCycle TASK::CommandExecutor: moving to safe mode! *\n");
		out = MOVE_TO_SAFE_EVENT;
		send_event.send(*(task_table[STATE_MACHINE_TASK_INDEX]),out);
		break;
	case MOVE_TO_STANDBY:
		printf(" * LifeCycle TASK::CommandExecutor: moving to standby mode! *\n");
		out = MOVE_TO_STANDBY_EVENT;
		send_event.send(*(task_table[STATE_MACHINE_TASK_INDEX]),out);
		break;
	case MOVE_TO_OP:
		printf(" * LifeCycle TASK::CommandExecutor: moving to operational mode! *\n");
		out = MOVE_TO_OP_EVENT;
		send_event.send(*(task_table[STATE_MACHINE_TASK_INDEX]),out);
		break;
	case FORMAT_ENERGY:
		printf(" * LifeCycle TASK::CommandExecutor: changing format to ENERGY! *\n");
		out = ENERGY_SEND;
		status = send_event.send(*(task_table[SEND_TASK_INDEX]),out);
		printf(" * LifeCycle TASK::CommandExecutor:  send event returned with %d *\n", status);
		break;
	case FORMAT_TEMP:
		printf(" * LifeCycle TASK::CommandExecutor: changing format to Temperature! *\n");
		out = TEMP_SEND;
		status = send_event.send(*(task_table[SEND_TASK_INDEX]),out);
		printf(" * LifeCycle TASK::CommandExecutor:  send event returned with %d *\n", status);
		break;
	case FORMAT_STATIC:
		printf(" * LifeCycle TASK::CommandExecutor: changing format to Static! *\n");
		out = STATIC_SEND;
		status = send_event.send(*(task_table[SEND_TASK_INDEX]),out);
		printf(" * LifeCycle TASK::CommandExecutor:  send event returned with %d *\n", status);
		break;
	case FORMAT_MIXED:
		printf(" * LifeCycle TASK::CommandExecutor: changing format to Mixed! *\n");
		out = MIXED_SEND;
		status = send_event.send(*(task_table[SEND_TASK_INDEX]),out);
		printf(" * LifeCycle TASK::CommandExecutor:  send event returned with %d *\n", status);
		break;
	case SBAND_ON:
		printf(" * LifeCycle TASK::CommandExecutor: turning SBAND on! *\n");
		modules_request->request_sband(TURN_ON);
		break;
	case SBAND_STANDBY:
		printf(" * LifeCycle TASK::CommandExecutor: turning SBAND off! *\n");
		modules_request->request_sband(STANDBY);
		break;
	case PAYLOAD_ON:
		printf(" * LifeCycle TASK::CommandExecutor: turning PAYLOAD on! *\n");
		modules_request->request_payload(TURN_ON);
		break;
	case PAYLOAD_STANDBY:
		printf(" * LifeCycle TASK::CommandExecutor: turning PAYLOAD off! *\n");
		modules_request->request_payload(STANDBY);
		break;
	case THERMAL_CTRL_ON:
		printf(" * LifeCycle TASK::CommandExecutor: turning THERMAL_CTRL on! *\n");
		modules_request->request_thermal_ctrl(TURN_ON);
		break;
	case THERMAL_CTRL_STANDBY:
		printf(" * LifeCycle TASK::CommandExecutor: turning THERMAL_CTRL off! *\n");
		modules_request->request_thermal_ctrl(STANDBY);
		break;

		// XXX SIMULATOR FIELDS XXX

	case SET_TEMPERATURE:
		printf(" * LifeCycle TASK::CommandExecutor: setting temperature to high temperature! *\n");
		modules_request->request_set_temp(TURN_ON);
		break;
	case SET_ENERGY:
		printf(" * LifeCycle TASK::CommandExecutor: setting energy to low energy! *\n");
		modules_request->request_set_energy(TURN_ON);
		break;
	case CONNECTED:
		printf(" * LifeCycle TASK::CommandExecutor: connecting to ground! *\n");
		modules_request->request_connected(TURN_ON);
		break;
	case DISCONNECTED:
		printf(" * LifeCycle TASK::CommandExecutor: disconnecting from ground! *\n");
		modules_request->request_connected(STANDBY);
		break;
	default:
		printf(" * LifeCycle TASK::CommandExecutor: Illegal command in work! *\n");
	}
}
