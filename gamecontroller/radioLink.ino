#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7,8); //CE,CSN

const byte address[6] = "00001";

void radio_begin() {
  radio.begin();
  radio.setChannel(1);
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN); //Set this to RF24_PA_MAX for maximum distance.
                                 //You might require a bit beefier 3.3 v regulator
  radio.stopListening();
}

void radio_send() {
  const uint16_t val[8] = {VAL_KEY_UP,VAL_KEY_RIGHT,VAL_KEY_DOWN,VAL_KEY_LEFT,VAL_KEY_Y,VAL_KEY_B,VAL_KEY_A,VAL_KEY_X};
  radio.write(&val, sizeof(val));
}
