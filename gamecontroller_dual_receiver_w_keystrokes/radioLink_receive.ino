#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

RF24 radio(7, 8); //CE,CSN

const uint64_t address[2] = {0xEEFAFDFDEELL, 0xEEFDFAF50DFLL};

/******************** Set the radio up *********************/

void radio_begin() {
  radio.begin();

  radio.enableDynamicPayloads();
  radio.setCRCLength(RF24_CRC_16);

  radio.setRetries(15, 5) ;
  radio.setAutoAck(true) ;

  radio.setPALevel(RF24_PA_MIN);

  radio.openReadingPipe(0, address[0]);
  radio.openReadingPipe(1, address[1]);

  radio.powerUp();
  radio.startListening();
}

/******************** Receive the keys *********************/

void radio_receive() {
  uint8_t pipeNum;
  if (radio.available(&pipeNum)) {
    radio.read(&gamepad, sizeof(gamepad));

    sendKeystrokes(pipeNum);
  }
}

void sendKeystrokes(uint8_t controllerID) {
  if (controllerID == 0) {

    old_controller_1 = millis();

    for (uint8_t x = 0; x < 8; x++) {
      if (mapping[x] != '-') {
        if (gamepad[x] == 0) {
          Keyboard.press(mapping[x]);
        } else {
          Keyboard.release(mapping[x]);
        }
      }
    }

  }

  if (controllerID == 1) {

    old_controller_2 = millis();

    for (uint8_t x = 0; x < 8; x++) {
      if (mapping2[x] != '-') {
        if (gamepad[x] == 0) {
          Keyboard.press(mapping2[x]);
        } else {
          Keyboard.release(mapping2[x]);
        }
      }
    }

  }
}
