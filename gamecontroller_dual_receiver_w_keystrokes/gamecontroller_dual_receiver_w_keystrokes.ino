/* Coded by Teukka on 9.11.2018 */

#include <Keyboard.h>

/*

Check this site for the keystrokes:
https://www.arduino.cc/en/Reference/KeyboardModifiers

*/


uint16_t gamepad[8]; //up, right, down, left, yellow, red, green, blue

// This array defines the mapping for the keystrokes

//char mapping[8] = {'q', 'd', 's', 'a', '0', '0', ' ', '0'};   //strike force
char mapping[8] = {'-', 'd', 's', 'a', '-', '-', 'w', ' '};   //Sports Heads Football 2 (two players, player 2)
char mapping2[8] = {'-', KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, '-', '-', KEY_UP_ARROW, 'p'};   //Sports Heads Football 2 (two players, player 1)

long old_controller_1 = 0;
long old_controller_2 = 0;

const auto controller_max_timeout = 100; //ms

void setup() {
  Keyboard.begin(); //Configure the usb connection as HID-keyboad

  pinMode(2, INPUT_PULLUP);

  /* If you want to program the Arduino Leonardo, put a cable between D2 and GND */
  
  if(digitalRead(2) == LOW) {
    while(1);
  }

  radio_begin(); //Set the radio up
}

void loop() {
  radio_receive();  // Receive button presses
  check_if_controller_timeouts();
}

void check_if_controller_timeouts() {
  
  //If controller n.1 disconnects
  if(millis()-old_controller_1>controller_max_timeout) {
    for (uint8_t x = 0; x < 8; x++) {
      Keyboard.release(mapping[x]);
    }
  }

  //If controller n.2 disconnects
  if(millis()-old_controller_2>controller_max_timeout) {
    for (uint8_t x = 0; x < 8; x++) {
      Keyboard.release(mapping2[x]);
    }
  }
  
}
