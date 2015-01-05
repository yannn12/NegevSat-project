/*
 * Sampler.cpp
 *
 *  Created on: May 12, 2014
 *      Author: boris
 */

#include <logics/Sampler.hpp>
#include "utils/stringutils.hpp"
#include "logics/NegevSatConstants.hpp"
#include "logics/SendReceiveConf.hpp"
#include <map>

using namespace std;
using namespace stringutils;

Sampler::Sampler(){
}

Sampler::~Sampler() {
	// TODO Auto-generated destructor stub
}


/*
 * OLD CODE OF CREATE SAMPLE - WAS IN LIFECYCLE BEFORE! CHECK CORRECTNESS
int energy = hardware.getEnergy(true);
	int current = hardware.getEnergyCurrent(true);
	Sample::Sample energy_sample(ENERGY_SAMPLE_STR, "122");
	map<string,string> energy_measure;
	string energy_str = "";
	string current_str = "";
	energy_str = int_to_string(energy,energy_str);
	current_str = int_to_string(current,current_str);
	energy_measure.insert(pair<string,string>(VOLTAGE_STR, energy_str));
	energy_measure.insert(pair<string,string>(CURRENT_STR, current_str));
	energy_sample.addMeasure(BATTERY1_STR, energy_measure);
	parser.addSampleToPacket(energy_sample,ENERGY_STR);


	int temp = hardware.getTemperature(true);
	Sample::Sample temp_sample(TEMPERATURE_SAMPLE_STR, "122");
	map<string,string> temp_measure;
	string temp_str = "";
	temp_str = int_to_string(temp,temp_str);
	temp_measure.insert(pair<string,string>(TEMP_STR, temp_str));
	temp_sample.addMeasure(SENSOR1_STR, temp_measure);
	parser.addSampleToPacket(temp_sample,TEMPERATURE_STR);

	// create static sample
	int sband_module  = hardware.getSbandStatus();
	int temp_module = hardware.getTemperatureStatus();
	int energy_module  = hardware.getEnergyStatus();
	int solarp_module = hardware.getSolarPanelsStatus();
	int payload_module  = hardware.getPayloadStatus();
	int thermal_ctrl_module = hardware.getThermalControlStatus();

	// sband module
	Sample::Sample sband_sample(MODULE_STR, "122");
	map<string,string> sband_measure;
	sband_measure.insert(pair<string,string>(NAME_STR, hardware.getSbandName()));
	sband_measure.insert(pair<string,string>(STATUS_STR, module_state_to_chars(sband_module)));
	sband_sample.addMeasure(INFO_STR, sband_measure);
	parser.addSampleToPacket(sband_sample,STATIC_STR);

	// temp module
	Sample::Sample temp_module_sample(MODULE_STR, "122");
	map<string,string> temp_module_measure;
	temp_module_measure.insert(pair<string,string>(NAME_STR, hardware.getTemperatureName()));
	temp_module_measure.insert(pair<string,string>(STATUS_STR, module_state_to_chars(temp_module)));
	temp_module_sample.addMeasure(INFO_STR, temp_module_measure);
	parser.addSampleToPacket(temp_module_sample,STATIC_STR);

	// energy module
	Sample::Sample energy_module_sample(MODULE_STR, "122");
	map<string,string> energy_module_measure;
	energy_module_measure.insert(pair<string,string>(NAME_STR, hardware.getEnergyName()));
	energy_module_measure.insert(pair<string,string>(STATUS_STR, module_state_to_chars(energy_module)));
	energy_module_sample.addMeasure(INFO_STR, energy_module_measure);
	parser.addSampleToPacket(energy_module_sample,STATIC_STR);

	// solarp module
	Sample::Sample solarp_sample(MODULE_STR, "122");
	map<string,string> solarp_measure;
	solarp_measure.insert(pair<string,string>(NAME_STR, hardware.getSolarPanelsName()));
	solarp_measure.insert(pair<string,string>(STATUS_STR, module_state_to_chars(solarp_module)));
	solarp_sample.addMeasure(INFO_STR, solarp_measure);
	parser.addSampleToPacket(solarp_sample,STATIC_STR);

	// payload module
	Sample::Sample payload_sample(MODULE_STR, "122");
	map<string,string> payload_measure;
	payload_measure.insert(pair<string,string>(NAME_STR, hardware.getPayloadName()));
	payload_measure.insert(pair<string,string>(STATUS_STR, module_state_to_chars(payload_module)));
	payload_sample.addMeasure(INFO_STR, payload_measure);
	parser.addSampleToPacket(payload_sample,STATIC_STR);

	// thermal_ctrl module
	Sample::Sample thermal_ctrl_sample(MODULE_STR, "122");
	map<string,string> thermal_ctrl_measure;
	thermal_ctrl_measure.insert(pair<string,string>(NAME_STR, hardware.getThermalControlName()));
	thermal_ctrl_measure.insert(pair<string,string>(STATUS_STR, module_state_to_chars(thermal_ctrl_module)));
	thermal_ctrl_sample.addMeasure(INFO_STR, thermal_ctrl_measure);
	parser.addSampleToPacket(thermal_ctrl_sample,STATIC_STR);
	// END of static sample
*/

Sample::Sample* Sampler::createSample(string type, bool i2c, unsigned long long time, int module){
	string time_str = "";
	time_str = unsigned_long_to_string(time,time_str);
	int value = hardware->getValue(module,i2c);
	if (!type.compare(ENERGY_STR)){
		// create energy sample
		int current = hardware->getEnergyCurrent(i2c);
		Sample::Sample* energy_sample = new Sample::Sample(ENERGY_SAMPLE_STR, time_str);
		map<string,string> energy_measure;
		string energy_str = "";
		string current_str = "";
		energy_str = int_to_string(value,energy_str);
		current_str = int_to_string(current,current_str);
		energy_measure.insert(pair<string,string>(VOLTAGE_STR, energy_str));
		energy_measure.insert(pair<string,string>(CURRENT_STR, current_str));
		energy_sample->addMeasure(BATTERY1_STR, energy_measure);
		return energy_sample;
	}
	else if (!type.compare(TEMPERATURE_STR)){
		// create temperature sample
		Sample::Sample* temp_sample = new Sample::Sample(TEMPERATURE_SAMPLE_STR, time_str);
		map<string,string> temp_measure;
		string temp_str = "";
		temp_str = int_to_string(value,temp_str);
		temp_measure.insert(pair<string,string>(TEMP_STR, temp_str));
		temp_sample->addMeasure(SENSOR1_STR, temp_measure);
		return temp_sample;
	}
	else if (!type.compare(STATIC_STR)){
		// create static sample
		int status = hardware->getStatus(module);
		Sample::Sample* sample = new Sample::Sample(MODULE_STR, time_str);
		map<string,string> measure;
		measure.insert(pair<string,string>(NAME_STR, hardware->getName(module)));
		measure.insert(pair<string,string>(STATUS_STR, module_state_to_chars(status)));
		sample->addMeasure(INFO_STR, measure);
		return sample;
	}
	else {
		// TODO throw exception here!
		printf(" * LifeCycle TASK::Sample: Illegal type of sample! *\n");
		Sample::Sample* sample = new Sample::Sample(MODULE_STR, time_str);
		return sample;
	}
}
