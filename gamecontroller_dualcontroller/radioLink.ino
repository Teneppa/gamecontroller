#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7,8); //CE,CSN

const uint64_t address[2] = {0xEEFAFDFDEELL, 0xEEFDFAF50DFLL};

/* This void makes sure that the nrf24 module uses the right address and data transfer protocol as the receiver */
void radio_begin() {
  radio.begin();

  radio.enableDynamicPayloads();     // This must be used if using more than one module
  radio.setCRCLength(RF24_CRC_16);   // Set packet size to 16-bits

  radio.setRetries(15, 5);           // Increase delay and retries
  radio.setAutoAck(true);            // Just a precaution

  radio.setPALevel(RF24_PA_MIN); //Set this to RF24_PA_MAX for maximum distance.
                                 //You might require a bit beefier 3.3 v regulator
  
  radio.openWritingPipe(address[0]); //for the 1st controller use [0] and for the 2nd controller use [1]
  
  radio.stopListening();  // Stop listening and start sending
}

/* This void sends the button presses over to the receiver */
void radio_send() {
  const uint16_t val[8] = {VAL_KEY_UP,VAL_KEY_RIGHT,VAL_KEY_DOWN,VAL_KEY_LEFT,VAL_KEY_Y,VAL_KEY_B,VAL_KEY_A,VAL_KEY_X};
  radio.write(&val, sizeof(val));
}
