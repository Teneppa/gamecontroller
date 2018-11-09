#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

RF24 radio(7, 8); //CE,CSN

const byte address[6] = "00001"; //This is the address for the modules.
                                 //Just make sure that the receiver and transmitter are using the same address

/******************** Set the radio up *********************/

void radio_begin() {
  radio.begin();
  radio.setChannel(1);
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  radio.printDetails();
}

/******************** Receive the keys *********************/

void radio_receive() {
  if (radio.available()) {                  //If radio has received something
    radio.read(&gamepad, sizeof(gamepad));  //Transfer the buffer to the gamepad array
  }
}
