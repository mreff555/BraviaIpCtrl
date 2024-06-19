/**
 * @file braviaTypes.hpp
 * @author Dan Feerst (feerstd@gmail.com)
 * @brief Enumerations and constant expressions
 * @version 0.1
 * @date 2020-03-12
 *
 * @copyright Copyright © 2020 Dan Feerst. All rights reserved.
 *
 */

#ifndef braviaTypes_h
#define braviaTypes_h
#include "log.hpp"
#include <cstdlib>
#include <cstring>
#include <ctime>

enum Input_t {
  INPUT_HDMI_1 = 11,
  INPUT_HDMI_2 = 12,
  INPUT_HDMI_3 = 13,
  INPUT_HDMI_4 = 14,
  INPUT_COMPONENT_1 = 41,
  INPUT_SCR_MIRROR_1 = 51
};

enum class Type { NO_STATEMENT, COMMAND, ENQUIRY, ANSWER, RESULT };
enum class Command {
  NO_STATEMENT,
  IRCC,
  POWR,
  TPOW,
  VOLU,
  AMUT,
  INPT,
  PMUT,
  TPMU,
  BADR,
  MADR,
  SCEN
};

enum class Status { NO_STATEMENT, FAIL, SUCCESS };

union Value {
  char string[17];
  unsigned short number;
};

static const char *bctl_ircc_default = "*SCIRCC0000000000000000\n";

static const char *bctl_ircc_success = "*SAIRCC0000000000000000\n";

static const char *bctl_ircc_fail = "*SCIRCCFFFFFFFFFFFFFFFF\n";

static const char *bctl_power_on = "*SCPOWR0000000000000001\n";

static const char *bctl_power_off = "*SCPOWR0000000000000000\n";

static const char *bctl_power_on_act = "*SNPOWR0000000000000001\n";

static const char *bctl_power_off_act = "*SNPOWR0000000000000000\n";

static const char *bctl_power_success = "*SAPOWR0000000000000000\n";

static const char *bctl_power_status_off = "*SAPOWR0000000000000000\n";

static const char *bctl_power_status_on = "*SAPOWR0000000000000001\n";

static const char *bctl_power_fail = "*SAPOWRFFFFFFFFFFFFFFFF\n";

static const char *bctl_power_status = "*SEPOWR################\n";

static const char *bctl_power_toggle = "*STPOWR################\n";

static const char *bctl_volume_set = "*SCVOLU0000000000000000\n";

static const char *bctl_volume_set_success = "*SAVOLU0000000000000000\n";

static const char *bctl_volume_set_fail = "*SAVOLUFFFFFFFFFFFFFFFF\n";

static const char *bctl_volume_status = "*SEVOLU################\n";

static const char *bctl_input_set = "*SCINPT0000000000000000\n";

static const char *bctl_input_status = "*SEINPT################\n";

static const char *bctl_input_success = "*SAINPT0000000000000000\n";

// Display
static const char *bctl_ircc_display = "*SCIRCC0000000000000005\n";

// Home
static const char *bctl_ircc_home = "*SCIRCC0000000000000006\n";

// Options
static const char *bctl_ircc_options = "*SCIRCC0000000000000007\n";

// Return
static const char *bctl_ircc_return = "*SCIRCC0000000000000008\n";

// Up
static const char *bctl_ircc_up = "*SCIRCC0000000000000009\n";

// Down
static const char *bctl_ircc_down = "*SCIRCC0000000000000010\n";

// Right
static const char *bctl_ircc_right = "*SCIRCC0000000000000011\n";

// Left
static const char *bctl_ircc_left = "*SCIRCC0000000000000012\n";

// Confirm
static const char *bctl_ircc_confirm = "*SCIRCC0000000000000013\n";

// Red
static const char *bctl_ircc_red = "*SCIRCC0000000000000014\n";

// Green
static const char *bctl_ircc_green = "*SCIRCC0000000000000015\n";

// Yellow
static const char *bctl_ircc_yellow = "*SCIRCC0000000000000016\n";

// Blue
static const char *bctl_ircc_blue = "*SCIRCC0000000000000017\n";

// Num1
static const char *bctl_ircc_num1 = "*SCIRCC0000000000000018\n";

// Num2
static const char *bctl_ircc_num2 = "*SCIRCC0000000000000019\n";

// Num3
static const char *bctl_ircc_num3 = "*SCIRCC0000000000000020\n";

// Num4
static const char *bctl_ircc_num4 = "*SCIRCC0000000000000021\n";

// Num5
static const char *bctl_ircc_num5 = "*SCIRCC0000000000000022\n";

// Num6
static const char *bctl_ircc_num6 = "*SCIRCC0000000000000023\n";

// Num7
static const char *bctl_ircc_num7 = "*SCIRCC0000000000000024\n";

// Num8
static const char *bctl_ircc_num8 = "*SCIRCC0000000000000025\n";

// Num9
static const char *bctl_ircc_num9 = "*SCIRCC0000000000000026\n";

// Num0
static const char *bctl_ircc_num0 = "*SCIRCC0000000000000027\n";

// Volume Up
static const char *bctl_ircc_volume_up = "*SCIRCC0000000000000030\n";

// Volume Down
static const char *bctl_ircc_volume_down = "*SCIRCC0000000000000031\n";

// Mute
static const char *bctl_ircc_mute = "*SCIRCC0000000000000032\n";

// Channel Up
static const char *bctl_ircc_channel_up = "*SCIRCC0000000000000033\n";

// Channel Down
static const char *bctl_ircc_channel_down = "*SCIRCC0000000000000034\n";

// Subtitle
static const char *bctl_ircc_subtitle = "*SCIRCC0000000000000035\n";

// DOT
static const char *bctl_ircc_dot = "*SCIRCC0000000000000038\n";

// Picture Off
static const char *bctl_ircc_picture_off = "*SCIRCC0000000000000050\n";

// Wide
static const char *bctl_ircc_wide = "*SCIRCC0000000000000061\n";

// Jump
static const char *bctl_ircc_jump = "*SCIRCC0000000000000062\n";

// Sync Menu
static const char *bctl_ircc_sync_menu = "*SCIRCC0000000000000076\n";

// Forward
static const char *bctl_ircc_forward = "*SCIRCC0000000000000077\n";

// Play
static const char *bctl_ircc_play = "*SCIRCC0000000000000078\n";

// Rewind
static const char *bctl_ircc_rewind = "*SCIRCC0000000000000079\n";

// Prev
static const char *bctl_ircc_prev = "*SCIRCC0000000000000080\n";

// Stop
static const char *bctl_ircc_stop = "*SCIRCC0000000000000081\n";

// Next
static const char *bctl_ircc_next = "*SCIRCC0000000000000082\n";

// Pause
static const char *bctl_ircc_pause = "*SCIRCC0000000000000084\n";

// Flash Plus
static const char *bctl_ircc_flash_plus = "*SCIRCC0000000000000086\n";

// Flash Minus
static const char *bctl_ircc_flash_minus = "*SCIRCC0000000000000087\n";

// TV Power
static const char *bctl_ircc_tv_minus = "*SCIRCC0000000000000098\n";

// Audio
static const char *bctl_ircc_audio = "*SCIRCC0000000000000099\n";

// Input
static const char *bctl_ircc_input = "*SCIRCC0000000000000101\n";

// Sleep
static const char *bctl_ircc_sleep = "*SCIRCC0000000000000104\n";

// Sleep Timer
static const char *bctl_ircc_sleep_timer = "*SCIRCC0000000000000105\n";

// Video 2
static const char *bctl_ircc_video2 = "*SCIRCC0000000000000108\n";

// Picture Mode
static const char *bctl_ircc_picture_mode = "*SCIRCC0000000000000110\n";

// Demo Surround
static const char *bctl_ircc_demo_surround = "*SCIRCC0000000000000121\n";

// HDMI 1
static const char *bctl_ircc_hdmi1 = "*SCIRCC0000000000000124\n";

// HDMI 2
static const char *bctl_ircc_hdmi2 = "*SCIRCC0000000000000125\n";

// HDMI 3
static const char *bctl_ircc_hdmi3 = "*SCIRCC0000000000000126\n";

// HDMI 4
static const char *bctl_ircc_hdmi4 = "*SCIRCC0000000000000127\n";

// Action Menu
static const char *bctl_ircc_action_menu = "*SCIRCC0000000000000129\n";

// Help
static const char *bctl_ircc_help = "*SCIRCC0000000000000130\n";

// Replaces the 24th character of a string with a null
// terminator.  Intended to make messages printable without
// the unwanted line feed, and possible garbage text.
static const inline char *nullterm(const char *input) {
  char *output = (char *)malloc(24);
  memcpy(output, input, 24);
  memset(output + 23, '\0', 1);
  return output;
}

static const char *iircCommand(const unsigned short num) {
  FILE_LOG(logFUNCTION) << "Entering";
  char *output = nullptr;

  if (num > 0 && num <= 130) {
    int msgLen = 24;
    output = new char[msgLen];
    memset(output, 0, sizeof(*output));
    memcpy(output, bctl_ircc_default, msgLen);
    std::string numString = std::to_string(num);
    size_t strLen = numString.length();
    memcpy(output + (msgLen - 1 - strLen), numString.c_str(), strLen);
  }
  return output;
  FILE_LOG(logFUNCTION) << "Exiting";
}

#endif /* braviaTypes_h */
