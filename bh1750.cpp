#include "bh1750.h"


bh1750::bh1750(){
  }
 
void bh1750::begin(){
  
  Wire.begin();
  uint8_t mode = m_mode;
  write8(mode);
  delay(120);
}

uint16_t bh1750::readLightLevel(){
  uint16_t lux;
  Wire.beginTransmission(bh1750_add);
  Wire.requestFrom(bh1750_add, 2);
  lux = Wire.read();
  lux <<= 8;
  lux |= Wire.read();
  Wire.endTransmission();
  
  lux = lux/1.2;
  
  return lux;
  }

void bh1750::write8(uint8_t data){
  Wire.beginTransmission(bh1750_add);
  Wire.write(data);
  Wire.endTransmission();
  }
