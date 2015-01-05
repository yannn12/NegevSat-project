/*
 * CommandExecutor.hpp
 *
 *  Created on: May 10, 2014
 *      Author: dariaz
 */

#ifndef COMMANDEXECUTOR_HPP_
#define COMMANDEXECUTOR_HPP_

#include "data_protocol/CMDDictionary.hpp"
#include "data_protocol/WorkDescription.hpp"
#include "logics/NegevSatConstants.hpp"
#include "logics/Global.hpp"
#include "logics/ModulesOperationRequest.hpp"

class CommandExecutor {
private:
	ModulesOperationRequest::ModulesOperationRequest* modules_request;
public:
	CommandExecutor();
	virtual ~CommandExecutor();
	void execute(WorkDescription::WorkDescription work);
	void setModulesRequest(ModulesOperationRequest::ModulesOperationRequest* _modules_request);
};

#endif /* COMMANDEXECUTOR_HPP_ */
