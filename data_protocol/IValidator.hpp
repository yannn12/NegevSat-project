/*
 * IValidator.hpp
 *
 *  Created on: Apr 18, 2014
 *      Author: Genzel
 */

#ifndef IVALIDATOR_HPP_
#define IVALIDATOR_HPP_

#include <string>

using namespace std;

class IValidator
{
public:
  virtual bool buildPacket(const string& packet) = 0;
  virtual void* getRoot() = 0;
  virtual bool validate() = 0;
  virtual ~IValidator(){}
};

#endif /* IVALIDATOR_HPP_ */
