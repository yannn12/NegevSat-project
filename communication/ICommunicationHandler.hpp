/*
 * ICommunicationHandler.hpp
 *
 *  Created on: Apr 8, 2014
 *      Author: Genzel
 */

#ifndef ICOMMUNICATIONHANDLER_HPP_
#define ICOMMUNICATIONHANDLER_HPP_

#include <string>
using namespace std;

class ICommunicationHandler
{
public:
  virtual bool send(char* buffer, int length) = 0;
  virtual string receive() = 0;
  virtual bool verifyBytes(string msg) = 0;
  virtual ~ICommunicationHandler() { }
};

#endif /* ICOMMUNICATIONHANDLER_HPP_ */
