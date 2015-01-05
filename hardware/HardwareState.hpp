/*
 * HardwareState.hpp
 *
 *  Created on: May 8, 2014
 *      Author: dariaz
 */

#ifndef HARDWARESTATE_HPP_
#define HARDWARESTATE_HPP_

#include "EnergyModule.hpp"
#include "PayloadModule.hpp"
#include "SbandModule.hpp"
#include "TemperatureModule.hpp"
#include "SolarPanelsModule.hpp"
#include "ThermalControlModule.hpp"
#include <string>
#include "logics/NegevSatConstants.hpp"

#define HW_ENERGY_MODULE				0
#define HW_PAYLOAD_MODULE				1
#define HW_SBAND_MODULE					2
#define HW_TEMP_MODULE					3
#define HW_SOLARP_MODULE				4
#define HW_TERMAL_CTRL_MODULE			5

#define TEMP_COEFFICIENT				5
#define MIN_PROPER_TEMPERATURE			0
#define MAX_PROPER_TEMPERATURE			40
#define MIN_PROPER_VOLTAGE				3
#define MAX_PROPER_VOLTAGE				5
#define MIN_PROPER_CURRENT				1
#define MAX_PROPER_CURRENT				2

using namespace std;

class HardwareState {
private:
	//TODO change static type to HWModule
	TemperatureModule::TemperatureModule temperature;
	EnergyModule::EnergyModule energy;
	SbandModule::SbandModule sband;
	SolarPanelsModule::SolarPanelsModule solar_panels;
	PayloadModule::PayloadModule payload;
	ThermalControlModule::ThermalControlModule thermal_control;

public:
	HardwareState();
	virtual ~HardwareState();
	int getStatus(int module);
	int getValue(int module, bool i2c);
	string getName(int module);
	// getters and setters to value
	void setTemperature(int value){
		temperature.setValue(value);
	}

	int getTemperature(bool useI2C){
		return temperature.getValue(useI2C);
	}

	void setEnergy(int value){
		energy.setValue(value);
	}

	int getEnergy(bool useI2C){
		return energy.getValue(useI2C);
	}

	int getEnergyCurrent(bool useI2C){
		return energy.getCurrent(useI2C);
	}

	void setEnergyCurrent(int current){
		energy.setCurrent(current);
	}

	void setSband(int value){
		sband.setValue(value);
	}

	int getSband(bool useI2C){
		return sband.getValue(useI2C);
	}

	void setSolarPanels(int value){
		solar_panels.setValue(value);
	}

	int getSolarPanels(bool useI2C){
		return solar_panels.getValue(useI2C);
	}

	void setPayload(int value){
		payload.setValue(value);
	}

	int getPayload(bool useI2C){
		return payload.getValue(useI2C);
	}

	void setThermalControl(int value){
		thermal_control.setValue(value);
	}

	int getThermalControl(bool useI2C){
		return thermal_control.getValue(useI2C);
	}

	// end of getters and setters to value

	// getters and setters to status
	void setTemperatureStatus(int status){
		temperature.setStatus(status);
	}

	int getTemperatureStatus(){
		return temperature.getStatus();
	}

	void setEnergyStatus(int status){
		energy.setStatus(status);
	}

	int getEnergyStatus(){
		return energy.getStatus();
	}

	void setSbandStatus(int status){
		sband.setStatus(status);
	}

	int getSbandStatus(){
		return sband.getStatus();
	}

	void setSolarPanelsStatus(int status){
		solar_panels.setStatus(status);
	}

	int getSolarPanelsStatus(){
		return solar_panels.getStatus();
	}

	void setPayloadStatus(int status){
		payload.setStatus(status);
	}

	int getPayloadStatus(){
		return payload.getStatus();
	}

	void setThermalControlStatus(int status){
		thermal_control.setStatus(status);
	}

	int getThermalControlStatus(){
		return thermal_control.getStatus();
	}
	// end of getters and setters to status

	//getters of names

	string getTemperatureName(){
		return temperature.getName();
	}

	string getEnergyName(){
		return energy.getName();
	}

	string getSbandName(){
		return sband.getName();
	}

	string getSolarPanelsName(){
		return solar_panels.getName();
	}

	string getPayloadName(){
		return payload.getName();
	}

	string getThermalControlName(){
		return thermal_control.getName();
	}
};

#endif /* HARDWARESTATE_HPP_ */
