//============================================================================
// Name        : negevSat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : NegevSat Airborne system
//============================================================================

#define CONFIGURE_INIT
#define TEST_AMOUNT 20
/* configuration information */
#define CONFIGURE_INIT_TASK_INITIAL_MODES (RTEMS_PREEMPT | \
		RTEMS_TIMESLICE | \
		RTEMS_NO_ASR | \
		RTEMS_INTERRUPT_LEVEL(0))

#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
#define CONFIGURE_MAXIMUM_PORTS				  		TEST_AMOUNT
#define CONFIGURE_MAXIMUM_TASKS               		TEST_AMOUNT
#define CONFIGURE_MAXIMUM_TIMERS              		TEST_AMOUNT
#define CONFIGURE_MAXIMUM_SEMAPHORES          		TEST_AMOUNT
#define CONFIGURE_MAXIMUM_MESSAGE_QUEUES      		TEST_AMOUNT
#define CONFIGURE_MAXIMUM_PARTITIONS          		TEST_AMOUNT
#define CONFIGURE_MAXIMUM_REGIONS             		TEST_AMOUNT
#define CONFIGURE_MAXIMUM_PERIODS            	 	TEST_AMOUNT
#define CONFIGURE_MAXIMUM_USER_EXTENSIONS    		TEST_AMOUNT
#define CONFIGURE_MICROSECONDS_PER_TICK   			10000 /* 20 millisecond */
#define CONFIGURE_TICKS_PER_TIMESLICE       		10 /* 100 milliseconds */
#define CONFIGURE_MAXIMUM_POSIX_MUTEXES      		TEST_AMOUNT
#define CONFIGURE_LIBIO_MAXIMUM_FILE_DESCRIPTORS 	TEST_AMOUNT
#define CONFIGURE_RTEMS_INIT_TASKS_TABLE
#define CONFIGURE_INIT_TASK_STACK_SIZE      		(4 * RTEMS_MINIMUM_STACK_SIZE)
#define CONFIGURE_EXTRA_TASK_STACKS         		(13 * RTEMS_MINIMUM_STACK_SIZE)
#define CONFIGURE_DRIVER_AMBAPP_GAISLER_GPTIMER

#include <rtems/confdefs.h>
#include "logics/NegevSatConstants.hpp"
#include "logics/SendReceiveConf.hpp"
#include "communication/SendReceiveQueue.hpp"
#include "logics/tasks/SendTask.hpp"
#include "logics/tasks/ReceiveTask.hpp"
#include "logics/tasks/CMDTask.hpp"
#include "logics/tasks/MPTask.hpp"
#include "logics/tasks/StateMachineTask.hpp"
#include "logics/tasks/LifeCycleTask.hpp"
#include "data_protocol/WorkQueue.hpp"
#include <stdio.h>
#include "tests/AllTests.hpp"
#include "utils/timeutils.hpp"
#include "utils/stringutils.hpp"

using namespace stringutils;
using namespace timeutils;
using namespace std;

bool tests = false;

rtemsTask::rtemsTask* task_table[NUMBER_OF_TASKS];
rtems_time_of_day current_time;

//TODO check out automatically set those constants
#define TIME_YEAR		2014
#define TIME_MONTH		6
#define TIME_DAY		18
#define TIME_HOUR		10
#define TIME_MINUTE		22
#define TIME_SECONDS	30

void set_time(){
	current_time.day = TIME_DAY;
	current_time.month = TIME_MONTH;
	current_time.hour = TIME_HOUR;
	current_time.minute = TIME_MINUTE;
	current_time.second = TIME_SECONDS;
	current_time.year = TIME_YEAR;
	current_time.ticks = 0;
	rtems_clock_set( &current_time );
}

extern "C"
{
rtems_task Init(
		rtems_task_argument argument
);

#define CONFIGURE_APPLICATION_EXTRA_DRIVERS 	TTY1_DRIVER_TABLE_ENTRY
}

rtems_task Init(rtems_task_argument )
{
	set_time();

	if(tests){
		AllTests::AllTests tests(/*CMD_PARSER_TESTS*/ /*TLM_PARSER_TESTS*/ /*SEND_TESTS*/ /*RECEIVE_TESTS*//*VALIDATOR_TESTS*/ /*WORK_QUEUE_TESTS*/ SEND_RECEIVE_TESTS);
		tests.run_all_tests();
	}

	// create StateMachine task
	StateMachineTask::StateMachineTask state_machine_task;
	state_machine_task.create("STM ", 1, RTEMS_MINIMUM_STACK_SIZE * 2, 0, 0, 0);
	printf("%s\n", state_machine_task.last_status_string());
	state_machine_task.start(0xDEADDEAD);
	printf("%s\n", state_machine_task.last_status_string());


	// create send task
	SendReceiveQueue::SendReceiveQueue** send_queue_arr = new SendReceiveQueue::SendReceiveQueue* [SENDQ_SIZE];
	for (int i=0 ; i<SENDQ_SIZE; i++){
		send_queue_arr[i] = new SendReceiveQueue::SendReceiveQueue();
	}
	SendTask::SendTask send_task(send_queue_arr);
	send_task.create("SND ", 1, RTEMS_MINIMUM_STACK_SIZE * 2, 0, 0, 0);
	printf("%s\n", send_task.last_status_string());
	send_task.start(0xDEADDEAD);
	printf("%s\n", send_task.last_status_string());

	// create receive task
	SendReceiveQueue::SendReceiveQueue* receive_queue = new SendReceiveQueue::SendReceiveQueue();
	ReceiveTask::ReceiveTask recieve_task(receive_queue);
	recieve_task.create("RCV ", 1, RTEMS_MINIMUM_STACK_SIZE * 2, 0, 0, 0);
	printf("%s\n", recieve_task.last_status_string());
	recieve_task.start(0xDEADDEAD);
	printf("%s\n", recieve_task.last_status_string());

	// create MP task
	WorkQueue::WorkQueue* work_queue = new WorkQueue::WorkQueue();
	MPTask::MPTask mp_task(receive_queue, work_queue);
	mp_task.create("MPT ", 1, RTEMS_MINIMUM_STACK_SIZE * 2, 0, 0, 0);
	printf("%s\n", mp_task.last_status_string());
	mp_task.start(0xDEADDEAD);
	printf("%s\n", mp_task.last_status_string());

	// create CMD task
	WorkQueue::WorkQueue* rdy_work_queue = new WorkQueue::WorkQueue();
	CMDTask::CMDTask cmd_task(work_queue, rdy_work_queue);
	cmd_task.create("CMD ", 1, RTEMS_MINIMUM_STACK_SIZE * 2, 0, 0, 0);
	printf("%s\n", cmd_task.last_status_string());
	cmd_task.start(0xDEADDEAD);
	printf("%s\n", cmd_task.last_status_string());

	// create LifeCycle task
	LifeCycleTask::LifeCycleTask life_cycle_task(rdy_work_queue, send_queue_arr);
	life_cycle_task.create("LFC ", 1, RTEMS_MINIMUM_STACK_SIZE * 2, 0, 0, 0);
	printf("%s\n", life_cycle_task.last_status_string());
	life_cycle_task.start(0xDEADDEAD);
	printf("%s\n", life_cycle_task.last_status_string());

	task_table[SEND_TASK_INDEX] = &send_task;
	task_table[RECEIVE_TASK_INDEX] = &recieve_task;
	task_table[MP_TASK_INDEX] = &mp_task;
	task_table[CMD_TASK_INDEX] = &cmd_task;
	task_table[LIFE_CYCLE_TASK_INDEX] = &life_cycle_task;
	task_table[STATE_MACHINE_TASK_INDEX] = &state_machine_task;

	printf("INIT - Destroy it's self\n");
	rtems_status_code status  = rtems_task_delete( RTEMS_SELF );
	printf("rtems returned with %d\n", status);
	exit(1);
}




