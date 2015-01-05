/*
 * LifeCycleTask.cpp
 *
 *  Created on: May 8, 2014
 *      Author: dariaz
 */

#include <logics/tasks/LifeCycleTask.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "utils/stringutils.hpp"
#include "logics/NegevSatConstants.hpp"
#include "logics/SendReceiveConf.hpp"
#include <rtems++/rtemsEvent.h>
#include "utils/timeutils.hpp"

using namespace timeutils;
using namespace std;
using namespace stringutils;

LifeCycleTask::LifeCycleTask(WorkQueue::WorkQueue* _rdy_works, SendReceiveQueue::SendReceiveQueue** _send_queues) {
	rdy_works = _rdy_works;
	send_queues = _send_queues;
	samples_counter = 0;
	state = INIT_STATE;
	executor.setModulesRequest(&modules_request);
	sampler.setHardware(&hardware);
}

LifeCycleTask::~LifeCycleTask() {
	// TODO Auto-generated destructor stub
}

/**
 * Write the results of the algorithms calculation to I2C
 */
void LifeCycleTask::control_command(){
	//printf(" * LifeCycle TASK:: control_command *\n");
	if (state == SAFE_STATE){
		printf(" * LifeCycle TASK:: control_command - SUN POINTING *\n");
		// simulating charging the batter here when pointing the sun
		int voltage = hardware.getEnergy(false);
		if (voltage < MAX_PROPER_VOLTAGE){
			voltage++;
			printf(" * LifeCycle TASK:: control_command - CHARGING BATTERY %d V *\n", voltage);
			hardware.setEnergy(voltage);
		}
	}
	if (state == REGULAR_OPS_STATE || state == FACING_GROUND_STATE){
		//printf(" * LifeCycle TASK:: control_command - EARTH POINTING *\n");
	}
	//in INIT and STANDBY modes no actions to take
}

/**
 * Perform algorithm - using the samples which were read in the control_unit_samples function and
 * perform computation
 */
void LifeCycleTask::control_algorithmics(){
	//printf(" * LifeCycle TASK:: control_algorithmics *\n");
}

/**
 * check on which state the satellite is atm
 */
void LifeCycleTask::obtain_state(){
	//printf(" * LifeCycle TASK:: obtain_state *\n");
	rtemsEvent event;
	rtems_event_set out;
	rtems_status_code status = event.receive(RTEMS_ALL_EVENTS, out, 0, rtemsEvent::no_wait, rtemsEvent::any);
	if (status == RTEMS_SUCCESSFUL){
		if (out & INIT_STATE_EVENT){
			state = INIT_STATE;
		}
		if (out & STANDBY_STATE_EVENT){
			state = STANDBY_STATE;
		}
		if (out & SAFE_STATE_EVENT){
			state = SAFE_STATE;
		}
		if (out & REGULAR_OPS_STATE_EVENT){
			state = REGULAR_OPS_STATE;
		}
		if (out & FACING_GROUND_STATE_EVENT){
			printf(" * LifeCycle TASK:: FACING GROUND! *\n");
			state = FACING_GROUND_STATE;
		}
	}
}

/**
 * Samples control unit - critical samples (read using I2C)
 */
void LifeCycleTask::control_unit_samples(){
	//printf(" * LifeCycle TASK:: control_unit_samples *\n");

	if (samples_counter == 0){
		parser.createPacket("",ENERGY_STR);
		parser.createPacket("", TEMPERATURE_STR);
	}
	parser.createPacket(state_to_chars(state),STATIC_STR);
	rtems_clock_get_tod( &current_time);
	unsigned long long time = time_to_long();
	// create energy sample
	Sample::Sample* energy_sample = sampler.createSample(ENERGY_STR, true, time, HW_ENERGY_MODULE);
	parser.addSampleToPacket(energy_sample,ENERGY_STR);
	// create temperature sample
	Sample::Sample* temp_sample = sampler.createSample(TEMPERATURE_STR, true, time, HW_TEMP_MODULE);
	parser.addSampleToPacket(temp_sample,TEMPERATURE_STR);

	// create static samples
	Sample::Sample* static_sband_sample = sampler.createSample(STATIC_STR, true, time, HW_SBAND_MODULE);
	parser.addSampleToPacket(static_sband_sample,STATIC_STR);
	Sample::Sample* static_temp_sample = sampler.createSample(STATIC_STR, true, time, HW_TEMP_MODULE);
	parser.addSampleToPacket(static_temp_sample,STATIC_STR);
	Sample::Sample* static_energy_sample = sampler.createSample(STATIC_STR, true, time, HW_ENERGY_MODULE);
	parser.addSampleToPacket(static_energy_sample,STATIC_STR);
	Sample::Sample* static_solarp_sample = sampler.createSample(STATIC_STR, true, time, HW_SOLARP_MODULE);
	parser.addSampleToPacket(static_solarp_sample,STATIC_STR);
	Sample::Sample* static_payload_sample = sampler.createSample(STATIC_STR, true, time, HW_PAYLOAD_MODULE);
	parser.addSampleToPacket(static_payload_sample,STATIC_STR);
	Sample::Sample* static_thermal_ctrl_sample = sampler.createSample(STATIC_STR, true, time, HW_TERMAL_CTRL_MODULE);
	parser.addSampleToPacket(static_thermal_ctrl_sample,STATIC_STR);

	samples_counter++;
	// when packets are filled with details push them into the send queues and remove them from
	// parser to prevent memory leak and keep the invariant that parser always keeps 3 packets ONLY!
	if (samples_counter == MAX_SAMPLES){
		send_queues[SENDQ_ENERGY_INDEX]->enqueue(parser.getPacket(ENERGY_STR)->packetToString());
		parser.removePacket(ENERGY_STR);
		send_queues[SENDQ_TEMP_INDEX]->enqueue(parser.getPacket(TEMPERATURE_STR)->packetToString());
		parser.removePacket(TEMPERATURE_STR);
		samples_counter = 0;
	}
	send_queues[SENDQ_STATIC_INDEX]->enqueue(parser.getPacket(STATIC_STR)->packetToString());
	parser.removePacket(STATIC_STR);
}

void LifeCycleTask::attitude_control(int counter){
	//printf(" * LifeCycle TASK:: attitude_control *\n");
	if (counter == 0)
		control_unit_samples();
	control_algorithmics();
	control_command();
}

void LifeCycleTask::logics(){
	//printf(" * LifeCycle TASK:: logics *\n");
	rtemsEvent event;
	rtems_event_set out;
	if (hardware.getEnergyStatus() == MODULE_MALFUNCTION){
		out = MOVE_TO_SAFE_EVENT;
		event.send(*(task_table[STATE_MACHINE_TASK_INDEX]),out);
	}
	if (state == SAFE_STATE && hardware.getEnergyStatus() == MODULE_ON){
		out = MOVE_TO_OP_EVENT;
		event.send(*(task_table[STATE_MACHINE_TASK_INDEX]),out);
	}
}

void LifeCycleTask::perform_cmd(){
	//printf(" * LifeCycle TASK:: perform_cmd *\n");
	WorkDescription::WorkDescription work = rdy_works->dequeue(false);
	if (work.getCode() != NULL_WORK)
		executor.execute(work);
}

void LifeCycleTask::monitoring(){
	//printf(" * LifeCycle TASK:: monitoring *\n");
	int voltage = hardware.getEnergy(false);
	int current = hardware.getEnergyCurrent(false);
	int temp = hardware.getTemperature(false);

	//TODO check the condition of the samples (energy,temp and so on) and if the value is wrong
	//change something in order to invoke the right handling in the logics stage
	if (voltage < MIN_PROPER_VOLTAGE || current < MIN_PROPER_CURRENT){
		hardware.setEnergyStatus(MODULE_MALFUNCTION);
	}
	if (temp > MAX_PROPER_TEMPERATURE){
		hardware.setTemperatureStatus(MODULE_MALFUNCTION);
	}
	if (voltage >= MIN_PROPER_VOLTAGE){
		hardware.setEnergyStatus(MODULE_ON);
	}
	if (temp <= MAX_PROPER_TEMPERATURE){
		hardware.setTemperatureStatus(MODULE_ON);
	}
}

void LifeCycleTask::module_ctrl(){

	//printf(" * LifeCycle TASK:: module ctrl *\n");

	if (state == SAFE_STATE){
		printf(" * LifeCycle TASK:: module ctrl - SAFE! turning off unneeded modules *\n");
		hardware.setPayloadStatus(MODULE_STANDBY);
		hardware.setSbandStatus(MODULE_STANDBY);
	}

	if(modules_request.get_payload_request() == TURN_ON
			&& (state == FACING_GROUND_STATE || state == REGULAR_OPS_STATE)
			&& hardware.getTemperatureStatus() == MODULE_ON){
		hardware.setPayloadStatus(MODULE_ON);
		modules_request.request_payload(NO_CHANGE);
	}

	if (modules_request.get_payload_request() == STANDBY){
		hardware.setPayloadStatus(MODULE_STANDBY);
		modules_request.request_payload(NO_CHANGE);
	}

	if(modules_request.get_sband_request() == TURN_ON
			&& (state == FACING_GROUND_STATE || state == REGULAR_OPS_STATE)
			&& hardware.getTemperatureStatus() == MODULE_ON){
		hardware.setSbandStatus(MODULE_ON);
		modules_request.request_sband(NO_CHANGE);
	}

	if (modules_request.get_sband_request() == STANDBY){
		hardware.setSbandStatus(MODULE_STANDBY);
		modules_request.request_sband(NO_CHANGE);
	}

	if (modules_request.get_thermal_ctrl_request() == TURN_ON){
		hardware.setThermalControlStatus(MODULE_ON);
		modules_request.request_thermal_ctrl(NO_CHANGE);
	}

	if (modules_request.get_thermal_ctrl_request() == STANDBY){
		hardware.setThermalControlStatus(MODULE_STANDBY);
		modules_request.request_thermal_ctrl(NO_CHANGE);
	}

	// XXX SIMULATOR FIELDS XXX
	rtemsEvent event;
	rtems_event_set out;

	int high_temp = 50;
	int low_en = 0;

	if (modules_request.get_request_connected() == TURN_ON){
		out = RECEIVED_COMMUNICATION_EVENT;
		event.send(*(task_table[STATE_MACHINE_TASK_INDEX]),out);
		modules_request.request_connected(NO_CHANGE);
	}
	if (modules_request.get_request_connected() == STANDBY){
		out = LOST_COMMUNICATION_EVENT;
		event.send(*(task_table[STATE_MACHINE_TASK_INDEX]),out);
		modules_request.request_connected(NO_CHANGE);
	}
	if (modules_request.get_request_set_energy() == TURN_ON){
		hardware.setEnergy(low_en);
		modules_request.request_set_energy(NO_CHANGE);
	}
	if (modules_request.get_request_set_temp() == TURN_ON){
		hardware.setTemperature(high_temp);
		modules_request.request_set_temp(NO_CHANGE);
	}
}

void LifeCycleTask::thermal_ctrl(){
	//printf(" * LifeCycle TASK:: thermal ctrl *\n");
	if (hardware.getTemperatureStatus() == MODULE_MALFUNCTION){
		printf(" * LifeCycle TASK:: thermal ctrl - module malfunction *\n");
		hardware.setThermalControlStatus(MODULE_ON);
		int temp = hardware.getTemperature(false);
		temp--;
		hardware.setTemperature(temp);
		printf(" * LifeCycle TASK:: thermal ctrl - temp is now: %d *\n", temp);
	}
	else if (hardware.getTemperatureStatus() == MODULE_ON){
		hardware.setThermalControlStatus(MODULE_STANDBY);
	}
}

void LifeCycleTask::body(rtems_task_argument argument){
	// TODO refactor each function into object
	int count = 0;
	for (;;){
		//printf(" * LifeCycle TASK! *\n");
		obtain_state();
		/*if (state != INIT_STATE){*/
		attitude_control(count);
		logics();
		perform_cmd();
		monitoring();
		module_ctrl(); // turn on or off modules
		thermal_ctrl();
		count++; // this counter can be removed/modified - used to delay to samples rate (1/3 rounds)
		count = count % 3;
		/*}*/
	}
	exit(0);
}


