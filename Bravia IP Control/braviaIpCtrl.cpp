//
//  braviaIpCtl.cpp
//  Bravia IP Control
//
//  Created by Dan Feerst on 3/1/20.
//  Copyright © 2020 Dan Feerst. All rights reserved.
//
#include "braviaIpCtrl.hpp"
#include "braviaMessage.hpp"
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <thread>
#include <chrono>
 
BraviaIpCtrl::BraviaIpCtrl(const char* ip)
{
  host = gethostbyname(ip);
  if(host == nullptr)
  {
    perror("Invalid IP");
    exit(EXIT_FAILURE);
  }
  memset(&hostAddr, 0, sizeof(hostAddr));
  memset(&sendBuffer, 0, sizeof(sendBuffer));
  memset(&recBuffer, 0, sizeof(recBuffer));
  hostAddr.sin_family = AF_INET;
  hostAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  hostAddr.sin_addr.s_addr = ((struct in_addr*)(host->h_addr))->s_addr;
  hostAddr.sin_port = htons(bravia_port);
   
  if((socket_fd = socket(AF_INET,SOCK_STREAM, 0)) < 0)
  {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }
  else
  {
    if(connect(socket_fd, (struct sockaddr *)&hostAddr, sizeof(struct sockaddr)))
    {
      perror("connection failed failed");
      exit(EXIT_FAILURE);
    }
  }
}
 
BraviaIpCtrl::~BraviaIpCtrl()
{
  close(socket_fd);
}
 
bool BraviaIpCtrl::powerOn()
{
  sendMessage(bctl_power_on);
  return validateMessage(bctl_power_on_act);
}
 
bool BraviaIpCtrl::powerOff()
{
  sendMessage(bctl_power_off);
  return validateMessage(bctl_power_off_act);
}
 
bool BraviaIpCtrl::powerStatus()
{
  sendMessage(bctl_power_status);
  return validateMessage(bctl_power_status_on);
}
 
bool BraviaIpCtrl::setVolume(const unsigned short value)
{
  char *command = nullptr;
  command = _setVolume(bctl_volume_set, value);
  if(command != nullptr)
  {
    sendMessage(command);
  }
  return validateMessage(bctl_volume_set_success);
}
 
short BraviaIpCtrl::getVolume()
{
  sendMessage(bctl_volume_status);
  char charNum[4];
  memcpy(&charNum, &messages.back().datagram.data + 19, 4);
  return atoi(charNum);
}
 
bool BraviaIpCtrl::setInput(const Input_t value)
{
  char *command = nullptr;
  command = _setInput(bctl_input_set, value);
  if(command != nullptr)
  {
    sendMessage(command);
  }
  return validateMessage(bctl_input_success);
}
 
// TODO: Not really sure how I envisioned this working,
// but the actual TCP command doesn't seem to work correctly
// anywaay.  Must further investigate.
short BraviaIpCtrl::getInput()
{
  sendMessage(bctl_input_status);
  char charNum[5];
  memset(&charNum, 0, 5);
  memcpy(&charNum, &messages.back().datagram.data, 4);
  //std::cout << charNum <<std::endl;
  return atoi(charNum);
}
 
void BraviaIpCtrl::wait(unsigned short seconds)
{
  std::this_thread::sleep_for(std::chrono::seconds(seconds));
}
 
// Private
 
bool BraviaIpCtrl::sendMessage(const char *command)
{
  // std::cout << "sending: " << command << std::endl;
  bool success = false;
  struct timeval tv;
  fd_set sockRead;
  int selectStatus;
   
  memcpy(&sendBuffer, command, sizeof(sendBuffer));
  if((write(socket_fd, sendBuffer, strlen(sendBuffer))) > 0)
  {
    do
    {
      FD_ZERO(&sockRead);
      FD_SET(socket_fd, &sockRead);
      tv.tv_sec = 2;
      tv.tv_usec = 500000;
      selectStatus = select(socket_fd + 1, &sockRead, NULL, NULL, &tv);
       
      switch(selectStatus)
      {
        case -1:
          perror("select()");
          exit(EXIT_FAILURE);
          break;
          
        case 0:
          break;
 
        default:
         // printf("Ready for Reading\n");
          read(socket_fd, recBuffer, sizeof(recBuffer));
          
          struct Message msg;
          msg.timestamp = time(nullptr);
          memcpy(&msg.datagram.data, &recBuffer, sizeof(recBuffer));
          messages.push_back(msg);
          // std::cout << "Received: " << msg.data << std::endl;
      }
    }while (selectStatus > 0);
    success = true;
  }
  return success;
}
 
int BraviaIpCtrl::validateMessage(const char* expected_result)
{
  bool result = 0;
  std::vector<Message>::reverse_iterator it;
  for(it = messages.rbegin(); it != messages.rend(); ++it)
  {
    double diffTime = std::difftime(time(nullptr), it->timestamp);
    
    Message expected(expected_result);
    
    // found a matching type and command within the alotted time.
    if(expected.datagram.type() == it->datagram.type()
       && expected.datagram.command() == it->datagram.command()
       && diffTime < msg_expire_age)
    {
      //if(!memcmp(expected_result, ))
      result = 1;
      // std::cout << "Reveived messgage " << it->data << " at " << ts << ", " << diffTime << " seconds ago." << std::endl;
      continue;
    }
    
    // found a matching command after timeout had expired.
    else if(strcmp(it->datagram.data, bctl_volume_set_success) == 0 && diffTime >= msg_expire_age)
    {
      result = -1;
      // std::cout << "Reveived expired messgage " << it->data << " at " << ts << ", " << diffTime << " seconds ago." << std::endl;
      continue;
    }
    else
    {
      result = -2;
      // std::cout << "No match:\n" << it->data << "\n" << expected_result << "\n";
    }
  }
  return result;
}
 
 
char *BraviaIpCtrl::_setVolume(const char *input, unsigned short value)
{
   char *output = nullptr;
  if(value <= max_volume)
  {
    int msgLen = message_length;
    output = new char[msgLen];
    memset(output, 0, sizeof(*output));
    std::string numbers = std::to_string(value).c_str();
    size_t len = numbers.length();
    memcpy(output, input, msgLen);
    memcpy(output + (msgLen - 1) - len, numbers.c_str(), len);
  }
  return output;
}
 
Message BraviaIpCtrl::getLastMessage()
{
  // Replacing the last character of
  // the message, which is a carrige return
  // with a null terminator for printing purposes
  Message m = messages.back();
  m.datagram.data[23] = '\0';
  return m;
}


char *BraviaIpCtrl::_setInput(const char *input, Input_t type)
{
   char *output = nullptr;
    int msgLen = 24;
    output = new char[msgLen];
    memset(output, 0, sizeof(*output));
    memcpy(output, input, msgLen);
    switch (type)
    {
      case INPUT_HDMI_1:
        memset(output + 14, '1', sizeof(char));
        memset(output + 22, '1', sizeof(char));
      break;
      case INPUT_HDMI_2:
        memset(output + 14, '1', sizeof(char));
        memset(output + 22, '2', sizeof(char));
        break;
      case INPUT_HDMI_3:
        memset(output + 14, '1', sizeof(char));
        memset(output + 22, '3', sizeof(char));
        break;
      case INPUT_HDMI_4:
        memset(output + 14, '1', sizeof(char));
        memset(output + 22, '4', sizeof(char));
        break;
      case INPUT_COMPONENT_1:
        memset(output + 14, '4', sizeof(char));
        memset(output + 22, '1', sizeof(char));
      break;
      case INPUT_SCR_MIRROR_1:
        memset(output + 14, '5', sizeof(char));
        memset(output + 22, '1', sizeof(char));
        break;
    }
  return output;
}
