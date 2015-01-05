/*
 * ModulesOperationRequest.hpp
 *
 *  Created on: May 21, 2014
 *      Author: boris
 */

#ifndef MODULESOPERATIONREQUEST_HPP_
#define MODULESOPERATIONREQUEST_HPP_

#define NO_CHANGE		0
#define TURN_ON			1
#define STANDBY			2

class ModulesOperationRequest {

private:
	int payload_request;
	int sband_request;
	int thermal_ctrl_request;

	// XXX SIMULATOR FIELDS XXX
	int set_temp_request;
	int set_energy_request;
	int connected_request;

public:
	ModulesOperationRequest(){
		payload_request = NO_CHANGE;
		sband_request = NO_CHANGE;
		thermal_ctrl_request = NO_CHANGE;

		set_temp_request = NO_CHANGE;
		set_energy_request = NO_CHANGE;
		connected_request = NO_CHANGE;
	}

	void request_payload(int action){
		payload_request = action;
	}

	void request_sband(int action){
		sband_request = action;
	}

	void request_thermal_ctrl(int action){
		thermal_ctrl_request = action;
	}

	int get_payload_request(){
		return payload_request;
	}

	int get_sband_request(){
		return sband_request;
	}

	int get_thermal_ctrl_request(){
		return thermal_ctrl_request;
	}


	// XXX SIMULATOR FIELDS XXX
	void request_connected(int action){
		connected_request = action;
	}

	int get_request_connected(){
		return connected_request;
	}

	void request_set_temp(int action){
		set_temp_request = action;
	}

	int get_request_set_temp(){
		return set_temp_request;
	}

	void request_set_energy(int action){
		set_energy_request = action;
	}

	int get_request_set_energy(){
		return set_energy_request;
	}
	virtual ~ModulesOperationRequest();
};

#endif /* MODULESOPERATIONREQUEST_HPP_ */
