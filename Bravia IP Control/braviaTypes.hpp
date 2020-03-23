//
//  braviaTypes.hpp
//  Bravia IP Control
//
//  Created by Dan Feerst on 3/12/20.
//  Copyright © 2020 Dan Feerst. All rights reserved.
//

#ifndef braviaTypes_h
#define braviaTypes_h
#include <ctime>

enum Input_t
{
  INPUT_HDMI_1        = 11,
  INPUT_HDMI_2        = 12,
  INPUT_HDMI_3        = 13,
  INPUT_HDMI_4        = 14,
  INPUT_COMPONENT_1   = 41,
  INPUT_SCR_MIRROR_1  = 51
};

enum class Type
{
  NO_STATEMENT,
  COMMAND,
  ENQUIRY,
  ANSWER,
  RESULT
};
enum class Command
{
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

enum class Status
{
  NO_STATEMENT,
  FAIL,
  SUCCESS
};

union Value
{
  char string[17];
  unsigned short number;
};
#endif /* braviaTypes_h */
