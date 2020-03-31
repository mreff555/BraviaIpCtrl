//
//  braviaIpCtl.hpp
//  Bravia IP Control
//
//  Created by Dan Feerst on 3/1/20.
//  Copyright © 2020 Dan Feerst. All rights reserved.
//

#ifndef braviaIpCtl_hpp
#define braviaIpCtl_hpp

#include "braviaMessage.hpp"
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

class BraviaIpCtrl
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
  
  Message getLastMessage();
  
  private:
  
  bool sendMessage(const char*);
  
  int validateMessage(const char*);
  
  // Functions requireing extra processing go
  // here.  The function referenced in the interface
  // should have the same title without the underscore.
  char *_setVolume(const char*, unsigned short);
  
  char *_setInput(const char*, Input_t);
  
  // ** CONSTANTS **
  
  const int bravia_port = 20060;
  
  // expected length of all messages.  This is very
  // unlikely to change.
  const short message_length          = 24;
  
  // When searching received messages for confirmations
  // This is the maximum age to consider a valid response
  const float msg_expire_age          = 5.0;
  
  // This is the maximum amount of time in seconds
  // to wait for a response after the initial request
  // or recieving an initial respose
  const float msg_wait_timeout        = 3.0;
  
  // Units are in seconds and microseconds.
  struct timeval select_timeout         = {2, 500000};
  
  const short max_hdmi_ports          = 4;
    
  const short max_component_ports     = 1;
    
  const short max_scr_mirror          = 1;
  
  const short max_volume              = 100;
  
  struct sockaddr_in hostAddr;
  struct hostent *host;

  char sendBuffer[24];
  char recBuffer[24];

  int socket_fd;
  
  std::vector<Message> messages;
  
  BraviaIpCtrl *bc;
  
};

#endif /* braviaIpCtl_hpp */
