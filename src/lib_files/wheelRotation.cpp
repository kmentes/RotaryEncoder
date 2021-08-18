#include "wheelRotation.h"
void handle_encoder(RotaryEncoder *);

RotaryEncoder::RotaryEncoder(uint16_t pinA, uint16_t pinB)
{
  _pinA = pinA;
  _pinB = pinB;
}

void RotaryEncoder::begin(void (*callback)(void))
{
  pinMode(_pinA, INPUT_PULLUP);
  pinMode(_pinB, INPUT_PULLUP);
  attachInterrupt(_pinA, callback, RISING);
  attachInterrupt(_pinB, callback, RISING);
}

uint8_t RotaryEncoder::handle_encoder()
{
  uint8_t flag = 0;
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();

  delayMicroseconds(125);
  static unsigned char oldstate;
  uint8_t state = digitalRead(_pinA) | digitalRead(_pinB) << 1;
  if(digitalRead(_pinA) == 1){
    flag = 1;
  }
  else if(digitalRead(_pinB) == 1){
    flag = 2;
  }
  else{
    flag = 0;
  }
  oldstate = state;
  return flag;
}
