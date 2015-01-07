/*
 * ICommunicationHandler.hpp
 *
 *  Created on: Apr 8, 2014
 *      Author: Genzel
 */

#ifndef ICOMMUNICATIONHANDLER_HPP_
#define ICOMMUNICATIONHANDLER_HPP_

#include <string>
#include <vector>
using namespace std;

class ICommunicationHandler
{
public:
  virtual bool send(char* buffer, int length) = 0;
  virtual vector<char> receive() = 0;
  virtual bool verifyBytes(vector<char> msg) = 0;
  virtual ~ICommunicationHandler() { }
};

#endif /* ICOMMUNICATIONHANDLER_HPP_ */
