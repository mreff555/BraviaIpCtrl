//
//  braviaIpCtl.cpp
//  Bravia IP Control
//
//  Created by Dan Feerst on 3/1/20.
//  Copyright © 2020 Dan Feerst. All rights reserved.
//
#include "braviaIpCtrl.hpp"
#include "log.hpp"
#include <algorithm>
#include <chrono>
#include <cstring>
#include <ctime>
#include <string>
#include <thread>

BraviaIpCtrl::BraviaIpCtrl(const char *addr) {
  if (addr == nullptr) {
    FILE_LOG(logERROR) << "invalid ip address " << addr;
    exit(EXIT_FAILURE);
  } else {
    init(addr);
  }
}

BraviaIpCtrl::~BraviaIpCtrl() { close(socket_fd); }

bool BraviaIpCtrl::powerOn() {
  sendMessage(bctl_power_on);
  return validateMessage(bctl_power_success);
}

bool BraviaIpCtrl::powerOff() {
  sendMessage(bctl_power_off);
  return validateMessage(bctl_power_success);
}

bool BraviaIpCtrl::powerStatus() {
  sendMessage(bctl_power_status);
  return validateMessage(bctl_power_status_on);
}

bool BraviaIpCtrl::setVolume(const unsigned short value) {
  FILE_LOG(logFUNCTION) << "Entering";
  char *command = nullptr;
  command = _setVolume(bctl_volume_set, value);
  if (command != nullptr) {
    sendMessage(command);
  }
  return validateMessage(bctl_volume_set_success);
  FILE_LOG(logFUNCTION) << "Exiting";
}

short BraviaIpCtrl::getVolume() {
  FILE_LOG(logFUNCTION) << "Entering";
  sendMessage(bctl_volume_status);
  char charNum[4];
  memcpy(&charNum, &messages.back().datagram.data + 19, 4);
  return atoi(charNum);
  FILE_LOG(logFUNCTION) << "Exiting";
}

bool BraviaIpCtrl::setInput(const Input_t value) {
  FILE_LOG(logFUNCTION) << "Entering";
  char *command = nullptr;
  command = _setInput(bctl_input_set, value);
  if (command != nullptr) {
    sendMessage(command);
  }
  return validateMessage(bctl_input_success);
  FILE_LOG(logFUNCTION) << "Exiting";
}

// TODO: Not really sure how I envisioned this working,
// but the actual TCP command doesn't seem to work correctly
// anyway.  Must further investigate.
short BraviaIpCtrl::getInput() {
  FILE_LOG(logFUNCTION) << "Entering";
  sendMessage(bctl_input_status);
  char charNum[5];
  memset(&charNum, 0, 5);
  memcpy(&charNum, &messages.back().datagram.data, 4);
  // std::cout << charNum <<std::endl;
  return atoi(charNum);
  FILE_LOG(logFUNCTION) << "Exiting";
}

bool BraviaIpCtrl::sendIircCmd(const unsigned short value) {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  if (value >= 128 && value > 0) {
    const char *tmpCmd = iircCommand(value);
    sendMessage(tmpCmd);
    FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
    validateMessage(bctl_ircc_success);
    FILE_LOG(logFUNCTION) << "Exiting";
  }
  return success;
}

void BraviaIpCtrl::wait(unsigned short seconds) {
  std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

// ircc commands

bool BraviaIpCtrl::display() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(5);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::home() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(6);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::up() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(9);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
};

bool BraviaIpCtrl::down() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(10);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
};

bool BraviaIpCtrl::right() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(11);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
};

bool BraviaIpCtrl::left() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(12);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
};

bool BraviaIpCtrl::confirm() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(13);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
};

bool BraviaIpCtrl::num1() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(18);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::num2() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(19);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::num3() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(20);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::num4() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(21);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::num5() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(22);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::num6() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(23);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::num7() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(18);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::num8() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(25);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::num9() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(26);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::num0() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(27);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::hdmi1() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(124);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::hdmi2() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(125);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::hdmi3() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(126);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::hdmi4() {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  const char *tmpCmd = iircCommand(127);
  sendMessage(tmpCmd);
  FILE_LOG(logDEBUG) << "Sent message: " << tmpCmd;
  validateMessage(bctl_ircc_success);
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

// Private

bool BraviaIpCtrl::init(const char *addr) {
  bool success = true;
  FILE_LOG(logFUNCTION) << "Entering";

  // TODO: Debugger is calling EXC_BAD_ALLOC errors
  // A known thread safety issue with gethostbyname(...)  GNU extensions
  // have a modified gethostbyname_r(...) which may fix this, but Darwin
  // does not implement this.  A local file with have to be created to
  // implement the safe code. Preprocessor logic could be used to determine
  // which one is called
  host = gethostbyname(addr);
  memset(&hostAddr, 0, sizeof(hostAddr));
  memset(&sendBuffer, 0, sizeof(sendBuffer));
  memset(&recBuffer, 0, sizeof(recBuffer));
  hostAddr.sin_family = AF_INET;
  hostAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  hostAddr.sin_addr.s_addr = ((struct in_addr *)(host->h_addr))->s_addr;
  hostAddr.sin_port = htons(bravia_port);

  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    FILE_LOG(logERROR) << "Socket failed";
    success = false;
    exit(EXIT_FAILURE);
  } else {
    if (connect(socket_fd, (struct sockaddr *)&hostAddr,
                sizeof(struct sockaddr))) {
      FILE_LOG(logERROR) << "Connection failed";
      success = false;
      exit(EXIT_FAILURE);
    }
  }
  FILE_LOG(logFUNCTION) << "Exiting";
  return success;
}

bool BraviaIpCtrl::sendMessage(const char *command) {
  FILE_LOG(logFUNCTION) << "Entering";
  bool success = false;
  if (!command) {
    FILE_LOG(logERROR) << "Null Message";
  } else {
    fd_set sockRead;
    int selectStatus;

    memcpy(&sendBuffer, command, sizeof(sendBuffer));
    if ((write(socket_fd, sendBuffer, strlen(sendBuffer))) > 0) {
      do {
        FD_ZERO(&sockRead);
        FD_SET(socket_fd, &sockRead);
        selectStatus =
            select(socket_fd + 1, &sockRead, NULL, NULL, &select_timeout);

        switch (selectStatus) {
        case -1:
          FILE_LOG(logERROR) << "select() returned -1";
          exit(EXIT_FAILURE);
          break;

        case 0:
          FILE_LOG(logDEBUG) << "select() returned 0";
          break;

        default:
          read(socket_fd, recBuffer, sizeof(recBuffer));

          struct Message msg;
          msg.timestamp = time(nullptr);
          memcpy(&msg.datagram.data, &recBuffer, sizeof(recBuffer));
          messages.push_back(msg);
        }
      } while (selectStatus > 0);
      success = true;
    }
  }
  FILE_LOG(logFUNCTION) << "Exiting with result " << success;
  return success;
}

int BraviaIpCtrl::validateMessage(const char *expected_result) {
  FILE_LOG(logFUNCTION) << "Entering";
  bool result = false;
  std::vector<Message>::reverse_iterator it;
  for (it = messages.rbegin(); it != messages.rend(); ++it) {
    double diffTime = std::difftime(time(nullptr), it->timestamp);

    Message expected(expected_result);

    // found a matching type and command within the alotted time.
    if (expected.datagram.type() == it->datagram.type() &&
        expected.datagram.command() == it->datagram.command() &&
        diffTime < msg_expire_age) {
      result = 1;
      FILE_LOG(logINFO) << "Reveived messgage " << nullterm(it->datagram.data)
                        << " within " << diffTime << " seconds";
      continue;
    }

    // found a matching command after timeout had expired.
    else if (strcmp(it->datagram.data, bctl_volume_set_success) == 0 &&
             diffTime >= msg_expire_age) {
      result = -1;
      FILE_LOG(logWARNING) << "Reveived Expired messgage "
                           << nullterm(it->datagram.data) << " at " << diffTime
                           << " seconds";
      continue;
    }
  }
  if (!result) {
    FILE_LOG(logERROR) << "No match: " << nullterm(it->datagram.data)
                       << " vs expected " << expected_result;
  }
  return result;
  FILE_LOG(logFUNCTION) << "Exiting";
}

char *BraviaIpCtrl::_setVolume(const char *input, unsigned short value) {
  FILE_LOG(logFUNCTION) << "Entering";
  char *output = nullptr;
  if (value <= max_volume) {
    int msgLen = message_length;
    output = new char[msgLen];
    memset(output, 0, sizeof(*output));
    std::string numbers = std::to_string(value).c_str();
    size_t len = numbers.length();
    memcpy(output, input, msgLen);
    memcpy(output + (msgLen - 1) - len, numbers.c_str(), len);
  }
  return output;
  FILE_LOG(logFUNCTION) << "Exiting";
}

Message BraviaIpCtrl::getLastMessage() {
  // Replacing the last character of
  // the message, which is a carrige return
  // with a null terminator for printing purposes

  Message m = {0};
  if (messages.size()) {
    m = messages.back();
    m.datagram.data[23] = '\0';
  }
  return m;
}

char *BraviaIpCtrl::_setInput(const char *input, Input_t type) {
  FILE_LOG(logFUNCTION) << "Entering";
  char *output = nullptr;
  int msgLen = 24;
  output = new char[msgLen];
  memset(output, 0, sizeof(*output));
  memcpy(output, input, msgLen);
  switch (type) {
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
  FILE_LOG(logFUNCTION) << "Exiting";
  return output;
}
