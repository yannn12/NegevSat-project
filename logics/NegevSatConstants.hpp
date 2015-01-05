/*
 * NegevSatStates.hpp
 *
 *  Created on: May 9, 2014
 *      Author: dariaz
 */

#ifndef NEGEVSATCONSTANTS_HPP_
#define NEGEVSATCONSTANTS_HPP_

#include <rtems++/rtemsTask.h>

//Tasks Constants
#define NUMBER_OF_TASKS					6
#define NUMBER_OF_PASSIVE_TASKS			1 // passive means not receiving events from the state machine task
#define NUMBER_OF_ACTIVE_TASKS			NUMBER_OF_TASKS - NUMBER_OF_PASSIVE_TASKS

#define SEND_TASK_INDEX					0
#define RECEIVE_TASK_INDEX				1
#define MP_TASK_INDEX					2
#define CMD_TASK_INDEX					3
#define LIFE_CYCLE_TASK_INDEX			4
#define STATE_MACHINE_TASK_INDEX		5


// satellite states enums
#define INIT_STATE				0
#define STANDBY_STATE			1
#define SAFE_STATE				2
#define REGULAR_OPS_STATE		3
#define FACING_GROUND_STATE		4

// satellite states events - these events are relevant to all tasks and should not be overwritten
// e.g when state machine moves to another state, it sends those events to all tasks to inform the new state
#define INIT_STATE_EVENT			RTEMS_EVENT_0
#define STANDBY_STATE_EVENT			RTEMS_EVENT_1
#define SAFE_STATE_EVENT			RTEMS_EVENT_2
#define REGULAR_OPS_STATE_EVENT		RTEMS_EVENT_3
#define FACING_GROUND_STATE_EVENT	RTEMS_EVENT_4

// send task events
#define STATIC_SEND 			RTEMS_EVENT_10
#define ENERGY_SEND 			RTEMS_EVENT_11
#define TEMP_SEND 				RTEMS_EVENT_12
#define MIXED_SEND 				RTEMS_EVENT_13

// state machine events (state machine receives these events)
// when tasks ask the state machine to change state to another state
#define MOVE_TO_SAFE_EVENT					RTEMS_EVENT_10
#define MOVE_TO_STANDBY_EVENT				RTEMS_EVENT_11
#define MOVE_TO_OP_EVENT					RTEMS_EVENT_12
#define RECEIVED_COMMUNICATION_EVENT		RTEMS_EVENT_13
#define LOST_COMMUNICATION_EVENT			RTEMS_EVENT_14

//satellite states as chars
static const char INIT_STATE_STR[] = "INIT_STATE";
static const char STANDBY_STATE_STR[] = "STAND_BY_STATE";
static const char SAFE_STATE_STR[] = "SAFE_STATE";
static const char REGULAR_OPS_STATE_STR[] = "OPERATIONAL_STATE";
static const char FACING_GROUND_STATE_STR[] = "OPERATIONAL_STATE";

//satellite modules states enums
#define MODULE_ON				0
#define MODULE_MALFUNCTION		1
#define MODULE_NON_OPERATIONAL	2
#define MODULE_STANDBY			3

//satellite modules states as chars
static const char MODULE_ON_STR[] = "ON";
static const char MODULE_MALFUNCTION_STR[] = "MALFUNCTION";
static const char MODULE_NON_OPERATIONAL_STR[] = "NON_OPERATIONAL";
static const char MODULE_STANDBY_STR[] = "STANDBY";

//negevSat reserved words as chars
static const char TEMPERATURE_STR[] = "Temperature";
static const char ENERGY_STR[] = "Energy";
static const char STATIC_STR[] = "Static";
static const char ENERGY_SAMPLE_STR[] = "EnergySample";
static const char VOLTAGE_STR[] = "voltage";
static const char CURRENT_STR[] = "current";
static const char BATTERY1_STR[] = "Battery1";
static const char TEMPERATURE_SAMPLE_STR[] = "TemperatureSample";
static const char TEMP_STR[] = "temp";
static const char SENSOR1_STR[] = "Sensor1";
static const char MODULE_STR[] = "Module";
static const char NAME_STR[] = "name";
static const char STATUS_STR[] = "status";
static const char PACKET_STR[] = "packet";
static const char DOWN_PACKET_STR[] = "downstreamPacket";
static const char UP_PACKET_STR[] = "upstreamPacket";
static const char STATE_STR[] = "state";
static const char TYPE_STR[] = "type";
static const char TIME_STR[] = "time";
static const char MISSION_STR[] = "mission";
static const char OPCODE_STR[] = "opcode";
static const char PRIORITY_STR[] = "priority";
static const char INFO_STR[] = "Info";

//XML Constants
static const char XML_VERSION[] = "version";
static const char XML_VERSION_NUM[] = "1.0";
static const char XML_ENCODING[] = "encoding";
static const char XML_ENCODING_TYPE[] = "utf-8";

#endif /* NEGEVSATCONSTANTS_HPP_ */

