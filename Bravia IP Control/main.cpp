//
//  main.cpp
//  Bravia IP Control
//
//  Created by Dan Feerst on 3/1/20.
//  Copyright © 2020 Dan Feerst. All rights reserved.
//

#define MAX_LOG_LEVEL "INFO"

#include "braviaIpCtrl.hpp"
#include "log.hpp"
#include <iostream>
#include <cstring>

int main(int argc, const char * argv[])
{
  FILELog::ReportingLevel() = FILELog::FromString(MAX_LOG_LEVEL);
  FILE_LOG(logFUNCTION) << "Entering";
  if(argc < 1 || argc > 4)
  {
    std::cout << "Usage: bctl [address] [command] [value]\n";
  }
  else
  {
    // ******* Power *******
    BraviaIpCtrl bc(argv[1]);
    if(!strcmp(argv[2], "power") && !argv[3])
    {
      bc.powerStatus();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    else if(!strcmp(argv[2], "power") && argv[3] && !strcmp(argv[3], "on"))
    {
      bc.powerOn();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    else if(!strcmp(argv[2], "power") && argv[3] && !strcmp(argv[3], "off"))
    {
      bc.powerOff();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    // ******* Volume *******

    else if(!strcmp(argv[2], "volume") && !argv[3])
    {
      bc.getVolume();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    else if(!strcmp(argv[2], "volume") && argv[3])
    {
      unsigned short value = atoi(argv[3]);
      if(value >= 0 && value < 100)
      {
        bc.setVolume(value);
        Message message = bc.getLastMessage();
        std::cout << message.datagram.data <<std::endl;
      }
      else
      {
        FILE_LOG(logERROR) << "Value out of range (0 - 100), received: " << value;
      }
    }
    
    // ******* MODE *******

    else if(!strcmp(argv[2], "input") && !argv[3])
    {
      bc.getInput();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    else if(!strcmp(argv[2], "input") && argv[3])
    {
      //unsigned short value = atoi(argv[3]);
      Input_t value = (Input_t)atoi(argv[3]);
      if(value >= INPUT_HDMI_1 && value <= INPUT_SCR_MIRROR_1)
      {
        bc.setInput(value);
      }
      else
      {
        FILE_LOG(logERROR) << "Input value out of range (1-4), received " << value;
      }
      
    }
    
    // ******* END *******
    
    else
    {
      FILE_LOG(logERROR) << "Unknown parameter: " << argv[2] << " " << argv[3];
    }
  }
  
  //BraviaIpCtrl bc(tvIp);

  
  // bc.setInput(INPUT_HDMI_1);
  // bc.powerOn();
  // std::cout << bc.getVolume() << std::endl;
  // bc.wait(2);
  // std::cout << bc.getInput() << std::endl;
//  bc.setVolume(3);
  //bc.powerStatus();
//  bc.wait(2);
//  bc.powerOff();
//  bc.wait(4);
//  bc.powerStatus();
//  bc.wait(2);
//  bc.powerOn();
//  bc.wait(4);
//  bc.getVolume();
//  bc.wait(2);
//  bc.setVolume(20);
//  bc.wait(2);
  
  FILE_LOG(logFUNCTION) << "Exiting";
  return 0;
}
