//
//  main.cpp
//  Bravia IP Control
//
//  Created by Dan Feerst on 3/1/20.
//  Copyright © 2020 Dan Feerst. All rights reserved.
//

#define MAX_LOG_LEVEL "INFO"

// TODO: The goal here is to seperate braviaIpCtrl from the UI.
// BraviaCommands is an interface created for this purpose, but I still need
// to call the constructor at some point.  Not really sure the best way to implement
// this, so for now both stay
#include "braviaIpCtrl.hpp"         // Temporary
#include "braviaCommands.hpp"       // The actual API

#include "log.hpp"
#include <iostream>
#include <cstring>
#include <iomanip>

int main(int argc, const char * argv[])
{
  FILELog::ReportingLevel() = FILELog::FromString(MAX_LOG_LEVEL);
  FILE_LOG(logTRACE) << "argc = " << argc;

  
  if(argc > 2  && argc < 5)
  {
    std::cout << argc <<std::endl;
    
    FILE_LOG(logFUNCTION) << "Entering";
    BraviaIpCtrl bc(argv[1]);
    
    // ******* Power *******
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
    
    else if(!strcmp(argv[2], "power") && argv[3] && !strcmp(argv[3], "status"))
    {
      bc.powerStatus();
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
    
    // ******* IRCC *******
    else if(!strcmp(argv[2], "display") && !argv[3])
    {
      bc.display();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }

    else if(!strcmp(argv[2], "home") && !argv[3])
    {
      bc.home();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "up") && !argv[3])
    {
      bc.up();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "down") && !argv[3])
    {
      bc.down();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "right") && !argv[3])
    {
      bc.right();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "left") && !argv[3])
    {
      bc.left();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "confirm") && !argv[3])
    {
      bc.confirm();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "num1") && !argv[3])
    {
      bc.num1();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "num2") && !argv[3])
    {
      bc.num2();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "num3") && !argv[3])
    {
      bc.num3();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "num4") && !argv[3])
    {
      bc.num4();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "num5") && !argv[3])
    {
      bc.num1();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "num1") && !argv[3])
    {
      bc.num5();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "num6") && !argv[3])
    {
      bc.num6();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "num7") && !argv[3])
    {
      bc.num7();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "num8") && !argv[3])
    {
      bc.num8();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "num9") && !argv[3])
    {
      bc.num9();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "num0") && !argv[3])
    {
      bc.num0();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "hdmi1") && !argv[3])
    {
      bc.hdmi1();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "hdmi2") && !argv[3])
    {
      bc.hdmi2();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "hdmi3") && !argv[3])
    {
      bc.hdmi3();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    else if(!strcmp(argv[2], "hdmi4") && !argv[3])
    {
      bc.hdmi4();
      Message message = bc.getLastMessage();
      std::cout << message.datagram.data <<std::endl;
    }
    
    // ******* END *******
    else
    {
      FILE_LOG(logERROR) << "Unknown parameter: " << argv[2] << " " << argv[3];
    }
      FILE_LOG(logFUNCTION) << "Exiting";
  }
  else
  {
    // TODO: There has got to be a way to use a macro to clean up the tabs and backspaces
    std::cout << "Usage: bctl [address] [command] [value]\n";
    std::cout << "\nADDRESS:\n";
    std::cout << std::setw(2) << "" << "The ip address of the device.\n";
    std::cout << "\nCOMMAND / VALUE:\n";
    std::cout << std::setw(2) << "" << "power\n";
    std::cout << std::setw(4) << "" << "<no argument>" << std::setw(33) << "Power status message\n";
    std::cout << std::setw(4) << "" <<  "status"       << std::setw(40) << "Power status message\n";
    std::cout << std::setw(4) << "" <<  "on"           << std::setw(37) << "Turn power on\n";
    std::cout << std::setw(4) << "" <<  "off"          << std::setw(37) << "Turn power off\n";
    std::cout << "\n";
    std::cout << std::setw(2) << "" << "volume\n";
    std::cout << std::setw(4) << "" << "<no argument>" << std::setw(34) << "Volume status message\n";
    std::cout << std::setw(4) << "" << "status"        << std::setw(41) << "Volume status message\n";
    std::cout << std::setw(4) << "" << "<value>"       << std::setw(42) << "Integral value, 0 - 100\n";
    std::cout << "\n";
    std::cout << "IIRC Commands (No values)\n";
    std::cout << std::setw(2) << "" << "display"       << std::setw(42) << "Description here\n";
    std::cout << std::setw(2) << "" << "home"          << std::setw(42) << "Return to the home menu\n";
    std::cout << std::setw(2) << "" << "up"            << std::setw(42) << "up\n";
    std::cout << std::setw(2) << "" << "down"          << std::setw(42) << "down\n";
    std::cout << std::setw(2) << "" << "right"         << std::setw(42) << "right\n";
    std::cout << std::setw(2) << "" << "left"          << std::setw(42) << "left\n";
    std::cout << std::setw(2) << "" << "confirm"       << std::setw(42) << "confirm / ok\n";
    std::cout << std::setw(2) << "" << "hdmi1"         << std::setw(42) << "Switch to HDMI 1\n";

    // TODO: The input values are going to need to be reworked.  They are relying on enum values.  This is fine internally
    // but does not make for a intuitive API.  Some type of string conversion will be neccessary.
    
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
