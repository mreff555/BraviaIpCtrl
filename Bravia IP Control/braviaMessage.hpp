//
//  braviaMessage.hpp
//  Bravia IP Control
//
//  Created by Dan Feerst on 3/15/20.
//  Copyright © 2020 Dan Feerst. All rights reserved.
//

#ifndef braviaMessage_hpp
#define braviaMessage_hpp
#include "braviaTypes.hpp"

union Datagram
{
  char data[24];
  Datagram();
  ~Datagram();
  Datagram(const char* input);
  Type type();
  Command command();
  Value value();
};

struct Message
{
  time_t timestamp;
  Datagram datagram;
  
  Message();
  Message(const char *);
  ~Message();
};

#endif /* braviaMessage_hpp */
