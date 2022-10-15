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
  
  // Feeds exactly and only 24 characters into
  // the data array.
  Datagram(const char* input);
  
  // Returns the message type.  COMMAND, ENQUIRY,
  // ANSWER, or RESULT.  Void constructors or invalid
  // entries will result in a return of NO_STATEMENT.
  Type type();
  
  // returns the command catagory. Void constructors or invalid
  // entries will result in a return of NO_STATEMENT.
  Command command();
  
  // returns a value tyoe which is a union.  At minimum
  // it will contain numeric and character representations
  // of the value field.  The reason for the union is so
  // that it can be utilized to display type specific data
  // as well.
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
