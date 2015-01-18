/*
 * StatusPacket.hpp
 *
 *  Created on: 11 αιπε 2015
 *      Author: Yaniv
 */

#ifndef STATUSPACKET_HPP_
#define STATUSPACKET_HPP_

#include <data_protocol/abstract_datatype/Packet.hpp>
namespace Status {

enum Status {ON,MALFUNCTION,NON_OPERATIONAL,STANDBY};

}  // namespace Status


namespace Component {
enum Component {Energy,Payload,Sband,Temperature,SolarPanels,ThermalControl};


}  // namespace Component




static const char * ComponentStrings[] = { "Energy", "Payload", "Sband", "Temperature", "SolarPanels","ThermalControl"};

static const char * StatusStrings[] = { "ON","MALFUNCTION","NON_OPERATIONAL", "STANDBY"};

typedef struct
{
	unsigned char componentCode;
	unsigned long long time;
	unsigned char status;
} __attribute__((packed)) ComponentInfo;




class StatusPacket: public Packet {
public:

	virtual void toBytes(vector<char> &result) =0;
	virtual ~StatusPacket();
	StatusPacket();
	vector<ComponentInfo>& getComponentsInfo();
	void setComponentsInfo(const vector<ComponentInfo>& componentsInfo);

private:

	vector<ComponentInfo> componentsInfo;

};


#endif /* STATUSPACKET_HPP_ */
