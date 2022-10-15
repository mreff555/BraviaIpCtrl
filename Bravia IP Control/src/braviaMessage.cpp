//
//  braviaMessage.cpp
//  Bravia IP Control
//
//  Created by Dan Feerst on 3/15/20.
//  Copyright © 2020 Dan Feerst. All rights reserved.
//

#include "braviaMessage.hpp"
#include "log.hpp"
#include <cstring>

Datagram::Datagram(){}
Datagram::~Datagram(){}

Datagram::Datagram(const char* input)
{
  if(input)
  {
    memset(data, 0, 24);
    memcpy(data, input, 24);
  }
}

Type Datagram::type()
{
  Type output = Type::NO_STATEMENT;

  if(this->data[2] == 'C')
  {
    output = Type::COMMAND;
  }
  else if(this->data[2] == 'E')
  {
    output = Type::ENQUIRY;
  }
  else if (this->data[2] == 'A')
  {
    output = Type::ANSWER;
  }
  else if(this->data[2] == 'N')
  {
    output = Type::RESULT;
  }
  else
  {
    output = Type::NO_STATEMENT;
    FILE_LOG(logWARNING) << "Output type returned NO_STATEMENT";

  }
  return output;
}

Command Datagram::command()
{
  Command output = Command::NO_STATEMENT;
  if(!memcmp(&this->data + 3, "IRCC", 4))
  {
    output = Command::IRCC;
  }
  else if(!memcmp(&this->data + 3, "POWR", 4))
  {
    output = Command::POWR;
  }
  else if(!memcmp(&this->data + 3, "TPOW", 4))
  {
    output = Command::TPOW;
  }
  else if(!memcmp(&this->data + 3, "VOLU", 4))
  {
    output = Command::VOLU;
  }
  else if(!memcmp(&this->data + 3, "AMUT", 4))
  {
    output = Command::AMUT;
  }
  else if(!memcmp(&this->data + 3, "INPT", 4))
  {
    output = Command::INPT;
  }
  else if(!memcmp(&this->data + 3, "TPMU", 4))
  {
    output = Command::TPMU;
  }
  else if(!memcmp(&this->data + 3, "BADR", 4))
  {
    output = Command::BADR;
  }
  else if(!memcmp(&this->data + 3, "MADR", 4))
  {
    output = Command::MADR;
  }
  else if(!memcmp(&this->data + 3, "SCEN", 4))
  {
    output = Command::SCEN;
    FILE_LOG(logWARNING) << "Output command returned NO_STATEMENT";
  }
  return output;
}

Value Datagram::value()
{
  Value output;
  memset(&output.string, 0, 17);
  memcpy(&output.string, data + 7, 16);
  return output;
}

Message::Message()
{
  
}

Message::Message(const char *input)
{
  this->datagram = Datagram(input);
  this->timestamp = time(NULL);
}

Message::~Message()
{
  
}
