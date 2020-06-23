//
//  braviaIpCtl.hpp
//  Bravia IP Control
//
//  Created by Dan Feerst on 3/1/20.
//  Copyright © 2020 Dan Feerst. All rights reserved.
//

#ifndef braviaIpCtl_hpp
#define braviaIpCtl_hpp

#include "braviaCommands.hpp"
#include "braviaMessage.hpp"
#include "constants.hpp"
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

class BraviaIpCtrl : public BraviaCommands
{
  public:

  BraviaIpCtrl(const char*);

  ~BraviaIpCtrl();
  
  bool powerOn();
  
  bool powerOff();
  
  bool powerStatus();
  
  bool setVolume(const unsigned short);
  
  short getVolume();
  
  bool setInput(const Input_t);
  
  short getInput();
  
  void wait(unsigned short);
  
  // ircc commands
  
  bool display();
  
  bool home();

  bool up();

  bool down();

  bool right();

  bool left();

  bool confirm();

  bool num1();

  bool num2();

  bool num3();

  bool num4();

  bool num5();

  bool num6();

  bool num7();

  bool num8();

  bool num9();

  bool num0();

  bool hdmi1();
  
  bool hdmi2();

  bool hdmi3();

  bool hdmi4(); 

  Message getLastMessage();
  
  private:
  
  bool init(const char*);
  
  bool sendMessage(const char*);
  
  int validateMessage(const char*);
  
  char *_setVolume(const char*, unsigned short);
  
  char *_setInput(const char*, Input_t);
  
  bool sendIircCmd(const unsigned short value);

  struct sockaddr_in hostAddr;
  
  struct hostent *host;

  char sendBuffer[24];
  char recBuffer[24];

  int socket_fd;
  
  std::vector<Message> messages;
  
  BraviaIpCtrl *bc;
    
};

#endif /* braviaIpCtl_hpp */
