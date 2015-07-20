#ifndef bh1750_h
#define bh1750_h

#include "Arduino.h"
#include "Wire.h"

#define bh1750_add 0x23

#define bh1750_mode 0x10

class bh1750{
  private:
  uint8_t m_mode = bh1750_mode;
  void write8(uint8_t data);
  
  public:
  bh1750();
  void begin();
  uint16_t readLightLevel();
  
  };
  
  #endif
