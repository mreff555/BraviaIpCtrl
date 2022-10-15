#ifndef braviaCommands_hpp
#define braviaCommands_hpp

#include <braviaMessage.hpp>

class BraviaCommands
{
  public:

  virtual ~BraviaCommands(){}

  virtual bool powerOn() = 0;
  
  virtual bool powerOff() = 0;
  
  virtual bool powerStatus() = 0;
  
  virtual bool setVolume(const unsigned short) = 0;
  
  virtual short getVolume() = 0;
  
  virtual bool setInput(const Input_t) = 0;
  
  virtual short getInput() = 0;
  
  virtual void wait(unsigned short) = 0;
  
  // ircc commands
  
  virtual bool display() = 0;
  
  virtual bool home() = 0;

  virtual bool up() = 0;
  
  virtual bool down() = 0;

  virtual bool right() = 0;

  virtual bool left() = 0;

  virtual bool confirm() = 0;

  virtual bool num1() = 0;

  virtual bool num2() = 0;

  virtual bool num3() = 0;

  virtual bool num4() = 0;

  virtual bool num5() = 0;

  virtual bool num6() = 0;

  virtual bool num7() = 0;

  virtual bool num8() = 0;

  virtual bool num9() = 0;

  virtual bool num0() = 0;

  virtual bool hdmi1() = 0;
  
  virtual bool hdmi2() = 0;

  virtual bool hdmi3() = 0;

  virtual bool hdmi4() = 0; 

  virtual Message getLastMessage() = 0;

};

#endif /* braviaCommands_hpp */

