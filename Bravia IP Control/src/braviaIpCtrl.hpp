/**
 * @file braviaIpCtrl.hpp
 * @author Dan Feerst (feerstd@gmail)
 * @brief Opens the connection and processes the requests
 * @version 0.1
 * @date 2020-03-01
 * 
 * @copyright Copyright © 2020 Dan Feerst. All rights reserved.
 * 
 */

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

  virtual ~BraviaIpCtrl();
  
  bool powerOn() override;
  
  bool powerOff() override;
  
  bool powerStatus() override;
  
  bool setVolume(const unsigned short) override;
  
  short getVolume() override;
  
  bool setInput(const Input_t) override;
  
  short getInput() override;
  
  void wait(unsigned short) override;
  
  // ircc commands
  
  bool display() override;
  
  bool home() override;

  bool up() override;

  bool down() override;

  bool right() override;

  bool left() override;

  bool confirm() override;

  bool num1() override;

  bool num2() override;

  bool num3() override;

  bool num4() override;

  bool num5() override;

  bool num6() override;

  bool num7() override;

  bool num8() override;

  bool num9() override;

  bool num0() override;

  bool hdmi1() override;
  
  bool hdmi2() override;

  bool hdmi3() override;

  bool hdmi4() override; 

  Message getLastMessage() override;
  
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
