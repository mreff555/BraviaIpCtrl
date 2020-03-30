//
//  braviaIpCtrl_IF.hpp
//  Bravia IP Control
//
//  Created by Dan Feerst on 3/12/20.
//  Copyright © 2020 Dan Feerst. All rights reserved.
//

#ifndef braviaIpCtrl_IF_h
#define braviaIpCtrl_IF_h

#include "braviaTypes.hpp"

class BraviaIpCtrl_IF
{
public:
  
  virtual ~BraviaIpCtrl_IF() = 0;
  
  virtual void init(char*) = 0;
  
  virtual bool powerOn() = 0;
  
  virtual bool powerOff() = 0;
  
  virtual bool powerStatus() = 0;
  
  virtual bool setVolume(const unsigned short) = 0;
  
  virtual short getVolume() = 0;
  
  virtual bool setInput(const Input_t) = 0;
  
  virtual short getInput() = 0;
  
  virtual void wait(unsigned short) = 0;
   
  virtual Message &getLastMessage() = 0;

  
};

#endif /* braviaIpCtrl_IF_h */
