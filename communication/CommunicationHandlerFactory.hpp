/*
 * CommunicationHandlerFactory.hpp
 *
 *  Created on: Apr 26, 2014
 *      Author: dariaz
 */

#ifndef COMMUNICATIONHANDLERFACTORY_HPP_
#define COMMUNICATIONHANDLERFACTORY_HPP_

#include <string>
#include "ICommunicationHandler.hpp"
using namespace std;

class CommunicationHandlerFactory {
public:
	CommunicationHandlerFactory();
	ICommunicationHandler::ICommunicationHandler* createHandler(string type);
	virtual ~CommunicationHandlerFactory();
};

#endif /* COMMUNICATIONHANDLERFACTORY_HPP_ */
