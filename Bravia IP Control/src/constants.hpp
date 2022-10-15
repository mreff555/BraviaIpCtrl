/**
 * @file constants.hpp
 * @author Dan Feerst (feerstd@gmail.com)
 * @brief Device configuration constants
 * @version 0.1
 * @date 2020-04-01
 * 
 * @copyright Copyright © 2020 Dan Feerst. All rights reserved.
 * 
 */

#ifndef constants_h
#define constants_h

// The default communications port
static const short bravia_port             = 20060;

// expected length of all messages.  
// This is very unlikely to change.
static const short message_length          = 24;

// When searching received messages 
// for confirmations this is the 
// maximum age in seconds to 
// consider a valid response
static const float msg_expire_age          = 5.0;

// This is the maximum amount of time
// in seconds to wait for a response 
// after the initial request
// or receiving an initial respose
static const float msg_wait_timeout        = 3.0;

// Units are in seconds and 
// microseconds.
static struct timeval select_timeout       = {2, 500000};

static const short max_hdmi_ports          = 4;
  
static const short max_component_ports     = 1;
  
static const short max_scr_mirror          = 1;

static const short max_volume              = 100;

#endif /* constants_h */
