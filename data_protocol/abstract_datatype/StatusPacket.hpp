/*
 * StatusPacket.hpp
 *
 *  Created on: 11 αιπε 2015
 *      Author: Yaniv
 */

#ifndef STATUSPACKET_HPP_
#define STATUSPACKET_HPP_

#include <data_protocol/abstract_datatype/Packet.hpp>

enum Component {Sband,Temperature,Energy,SolarPanels,Payload,ThermalControl};

enum Status {ON,STANDBY};

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
	const vector<ComponentInfo>& getComponentsInfo() const;
	void setComponentsInfo(const vector<ComponentInfo>& componentsInfo);

private:

	vector<ComponentInfo> componentsInfo;

};


#endif /* STATUSPACKET_HPP_ */
