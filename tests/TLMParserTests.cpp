/*
 * TLMParserTests.cpp
 *
 *  Created on: May 6, 2014
 *      Author: dariaz
 */

#include <tests/TLMParserTests.hpp>
#include "utils/stringutils.hpp"
#include "logics/NegevSatConstants.hpp"
#include <stdio.h>
#include <string>
#include "utils/timeutils.hpp"
#include "logics/Global.hpp"


using namespace std;
using namespace stringutils;
using namespace timeutils;

TLMParserTests::TLMParserTests() {
	// TODO Auto-generated constructor stub

}

TLMParserTests::~TLMParserTests() {
	// TODO Auto-generated destructor stub
}

void TLMParserTests::create_packets(){
	int state = REGULAR_OPS_STATE;

	unsigned long long time = 20140628123535ULL;

	sampler.setHardware(&hardware);

	hardware.setEnergy(100);
	hardware.setEnergyCurrent(3);
	hardware.setTemperature(40);
	hardware.setPayloadStatus(MODULE_ON);
	hardware.setSbandStatus(MODULE_STANDBY);

	parser.createPacket("",ENERGY_STR);
	parser.createPacket("", TEMPERATURE_STR);
	parser.createPacket(state_to_chars(state),STATIC_STR);

	Sample::Sample* energy_sample = sampler.createSample(ENERGY_STR, true, time, HW_ENERGY_MODULE);
	parser.addSampleToPacket(energy_sample,ENERGY_STR);

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
}

char* TLMParserTests::runTests(){

	string expected_static =
		"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
		"<packet>"
	        "<downstreamPacket>"
	                "<type>Static</type>"
	                "<state>OPERATIONAL_STATE</state>"
	                "<Module time=\"20140628123535\">"
	                        "<Info name=\"Sband\" status=\"STANDBY\"/>"
	                "</Module>"
	                "<Module time=\"20140628123535\">"
	                        "<Info name=\"Temperature\" status=\"ON\"/>"
	                "</Module>"
	                "<Module time=\"20140628123535\">"
	                        "<Info name=\"Energy\" status=\"ON\"/>"
	                "</Module>"
	                "<Module time=\"20140628123535\">"
	                        "<Info name=\"SolarPanels\" status=\"ON\"/>"
	                "</Module>"
	                "<Module time=\"20140628123535\">"
	                        "<Info name=\"Payload\" status=\"ON\"/>"
	                "</Module>"
	                "<Module time=\"20140628123535\">"
	                        "<Info name=\"ThermalControl\" status=\"STANDBY\"/>"
	                "</Module>"
	        "</downstreamPacket>"
	"</packet>";

		string expected_energy =
	"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	"<packet>"
	        "<downstreamPacket>"
	                "<type>Energy</type>"
	                "<EnergySample time=\"20140628123535\">"
	                        "<Battery1 current=\"3\" voltage=\"100\"/>"
	                "</EnergySample>"
	        "</downstreamPacket>"
	"</packet>";

		string expected_temp =
	"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
	"<packet>"
	        "<downstreamPacket>"
	                "<type>Temperature</type>"
	                "<TemperatureSample time=\"20140628123535\">"
	                        "<Sensor1 temp=\"40\"/>"
	                "</TemperatureSample>"
	        "</downstreamPacket>"
	"</packet>";

	create_packets();

	string static_packet = parser.getPacket(STATIC_STR)->packetToString();
	string energy_packet = parser.getPacket(ENERGY_STR)->packetToString();
	string temp_packet = parser.getPacket(TEMPERATURE_STR)->packetToString();

	static_packet = trim_spaces_tabs_newlines(static_packet);
	energy_packet = trim_spaces_tabs_newlines(energy_packet);
	temp_packet = trim_spaces_tabs_newlines(temp_packet);
	expected_static = trim_spaces_tabs_newlines(expected_static);
	expected_energy = trim_spaces_tabs_newlines(expected_energy);
	expected_temp = trim_spaces_tabs_newlines(expected_temp);

	printf("expected static packet:\n %s\n", &expected_static[0]);
	printf("expected energy packet:\n %s\n", &expected_energy[0]);
	printf("expected temp packet:\n %s\n", &expected_temp[0]);
	printf("static packet:\n %s\n", &static_packet[0]);
	printf("energy packet:\n %s\n", &energy_packet[0]);
	printf("temp packet:\n %s\n", &temp_packet[0]);

	mu_assert("error, static packet", static_packet.compare(expected_static) == 0);
	mu_assert("error, energy packet", energy_packet.compare(expected_energy) == 0);
	mu_assert("error, temperature packet", temp_packet.compare(expected_temp) == 0);

	// TODO FIX parser/sampler and add asserts to make the test fail

	return 0;
}

