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
  
  const char *bctl_ircc_set               = "*SCIRCCXXXXXXXXXXXXXXXX\n";
  
  const char *bctl_ircc_success           = "*SCIRCC0000000000000000\n";
  
  const char *bctl_ircc_fail              = "*SCIRCCFFFFFFFFFFFFFFFF\n";
    
  const char *bctl_power_on               = "*SCPOWR0000000000000001\n";
  
  const char *bctl_power_off              = "*SCPOWR0000000000000000\n";
  
  const char *bctl_power_on_act           = "*SNPOWR0000000000000001\n";
  
  const char *bctl_power_off_act          = "*SNPOWR0000000000000000\n";

  const char *bctl_power_success          = "*SAPOWR0000000000000000\n";
  
  const char *bctl_power_status_off       = "*SAPOWR0000000000000000\n";
  
  const char *bctl_power_status_on        = "*SAPOWR0000000000000001\n";
  
  const char *bctl_power_fail             = "*SAPOWRFFFFFFFFFFFFFFFF\n";

  const char *bctl_power_status           = "*SEPOWR################\n";

  const char *bctl_power_toggle           = "*STPOWR################\n";
  
  const char *bctl_volume_set             = "*SCVOLU0000000000000000\n";
  
  const char *bctl_volume_set_success     = "*SAVOLU0000000000000000\n";
  
  const char *bctl_volume_set_fail        = "*SAVOLUFFFFFFFFFFFFFFFF\n";
  
  const char *bctl_volume_status          = "*SEVOLU################\n";
  
  const char *bctl_input_set              = "*SCINPT0000000000000000\n";

  const char *bctl_input_status           = "*SEINPT################\n";

  const char *bctl_input_success          = "*SAINPT0000000000000000\n";
  
   // Display
  const char *bctl_ircc_display           = "*SCIRCC0000000000000005\n";
   
   // Home
  const char *bctl_ircc_home              = "*SCIRCC0000000000000006\n";
   
   // Options
  const char *bctl_ircc_options           = "*SCIRCC0000000000000007\n";
   
   // Return
  const char *bctl_ircc_return            = "*SCIRCC0000000000000008\n";
   
   // Up
  const char *bctl_ircc_up                = "*SCIRCC0000000000000009\n";
   
   // Down
  const char *bctl_ircc_down              = "*SCIRCC0000000000000010\n";
   
   // Right
  const char *bctl_ircc_right             = "*SCIRCC0000000000000011\n";
   
   // Left
  const char *bctl_ircc_left              = "*SCIRCC0000000000000012\n";
   
   // Confirm
  const char *bctl_ircc_confirm           = "*SCIRCC0000000000000013\n";
   
   // Red
  const char *bctl_ircc_red               = "*SCIRCC0000000000000014\n";
   
   // Green
  const char *bctl_ircc_green             = "*SCIRCC0000000000000015\n";
   
   // Yellow
  const char *bctl_ircc_yellow            = "*SCIRCC0000000000000016\n";
   
   // Blue
  const char *bctl_ircc_blue              = "*SCIRCC0000000000000017\n";
   
   // Num1
  const char *bctl_ircc_num1              = "*SCIRCC0000000000000018\n";
   
   // Num2
  const char *bctl_ircc_num2              = "*SCIRCC0000000000000019\n";
   
   // Num3
  const char *bctl_ircc_num3              = "*SCIRCC0000000000000020\n";
   
   // Num4
  const char *bctl_ircc_num4              = "*SCIRCC0000000000000021\n";
   
   // Num5
  const char *bctl_ircc_num5              = "*SCIRCC0000000000000022\n";
   
   // Num6
  const char *bctl_ircc_num6              = "*SCIRCC0000000000000023\n";
   
   // Num7
  const char *bctl_ircc_num7              = "*SCIRCC0000000000000024\n";
   
   // Num8
  const char *bctl_ircc_num8              = "*SCIRCC0000000000000025\n";
   
   // Num9
  const char *bctl_ircc_num9              = "*SCIRCC0000000000000026\n";
   
   // Num0
  const char *bctl_ircc_num0              = "*SCIRCC0000000000000027\n";
   
   // Volume Up
  const char *bctl_ircc_volume_up         = "*SCIRCC0000000000000030\n";
   
   // Volume Down
  const char *bctl_ircc_volume_down       = "*SCIRCC0000000000000031\n";
   
   // Mute
  const char *bctl_ircc_mute              = "*SCIRCC0000000000000032\n";
   
   // Channel Up
  const char *bctl_ircc_channel_up        = "*SCIRCC0000000000000033\n";
   
   // Channel Down
  const char *bctl_ircc_channel_down      = "*SCIRCC0000000000000034\n";
   
   // Subtitle
  const char *bctl_ircc_subtitle          = "*SCIRCC0000000000000035\n";
   
   // DOT
  const char *bctl_ircc_dot               = "*SCIRCC0000000000000038\n";
   
   // Picture Off
  const char *bctl_ircc_picture_off       = "*SCIRCC0000000000000050\n";
   
   // Wide
  const char *bctl_ircc_wide              = "*SCIRCC0000000000000061\n";
   
   // Jump
  const char *bctl_ircc_jump              = "*SCIRCC0000000000000062\n";
   
   // Sync Menu
  const char *bctl_ircc_sync_menu         = "*SCIRCC0000000000000076\n";
   
   // Forward
  const char *bctl_ircc_forward           = "*SCIRCC0000000000000077\n";
   
   // Play
  const char *bctl_ircc_play              = "*SCIRCC0000000000000078\n";
   
   // Rewind
  const char *bctl_ircc_rewind            = "*SCIRCC0000000000000079\n";
   
   // Prev
  const char *bctl_ircc_prev              = "*SCIRCC0000000000000080\n";
   
   // Stop
  const char *bctl_ircc_stop              = "*SCIRCC0000000000000081\n";
   
   // Next
  const char *bctl_ircc_next              = "*SCIRCC0000000000000082\n";
   
   // Pause
  const char *bctl_ircc_pause             = "*SCIRCC0000000000000084\n";
   
   // Flash Plus
  const char *bctl_ircc_flash_plus        = "*SCIRCC0000000000000086\n";
   
   // Flash Minus
  const char *bctl_ircc_flash_minus       = "*SCIRCC0000000000000087\n";
   
   // TV Power
  const char *bctl_ircc_tv_minus          = "*SCIRCC0000000000000098\n";
   
   // Audio
  const char *bctl_ircc_audio             = "*SCIRCC0000000000000099\n";
   
   // Input
  const char *bctl_ircc_input             = "*SCIRCC0000000000000101\n";
   
   // Sleep
  const char *bctl_ircc_sleep             = "*SCIRCC0000000000000104\n";
   
   // Sleep Timer
  const char *bctl_ircc_sleep_timer       = "*SCIRCC0000000000000105\n";
   
   // Video 2
  const char *bctl_ircc_video2            = "*SCIRCC0000000000000108\n";
   
   // Picture Mode
  const char *bctl_ircc_picture_mode      = "*SCIRCC0000000000000110\n";
   
   // Demo Surround
  const char *bctl_ircc_demo_surround     = "*SCIRCC0000000000000121\n";
   
   // HDMI 1
  const char *bctl_ircc_hdmi1             = "*SCIRCC0000000000000124\n";
   
   // HDMI 2
  const char *bctl_ircc_hdmi2             = "*SCIRCC0000000000000125\n";
   
   // HDMI 3
  const char *bctl_ircc_hdmi3             = "*SCIRCC0000000000000126\n";
   
   // HDMI 4
  const char *bctl_ircc_hdmi4             = "*SCIRCC0000000000000127\n";
   
   // Action Menu
  const char *bctl_ircc_action_menu       = "*SCIRCC0000000000000129\n";
   
   // Help
  const char *bctl_ircc_help              = "*SCIRCC0000000000000130\n";
  
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
