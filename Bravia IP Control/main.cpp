//
//  main.cpp
//  Bravia IP Control
//
//  Created by Dan Feerst on 3/1/20.
//  Copyright © 2020 Dan Feerst. All rights reserved.
//

#include "braviaIpCtrl.hpp"
#include <iostream>
#include <cstring>

int main(int argc, const char * argv[])
{
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
        // out of range error handling
      }
    }
    
    // ******* MODE *******

    else if(!strcmp(argv[2], "input") && !argv[3])
    {
      bc.getInput();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    // ******* END *******
    
    else
    {
      // ???
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
  
  return 0;
}
