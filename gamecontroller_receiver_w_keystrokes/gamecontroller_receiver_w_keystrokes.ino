/* Coded by Teukka on 9.11.2018 */

#include <Keyboard.h>

/*

Check this site for the keystrokes:
https://www.arduino.cc/en/Reference/KeyboardModifiers

*/


uint16_t gamepad[8]; //up, right, down, left, yellow, red, green, blue

// This array defines the mapping for the keystrokes

char mapping[8] = {'q', 'd', 's', 'a', '8', '9', 'w', ' '};   //Sports Heads Football 2 (two players, player 2)
//char mapping[8] = {'q', KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, '8', '9', KEY_UP_ARROW, 'p'};   //Sports Heads Football 2 (two players, player 1)

void setup() {
  Keyboard.begin(); //Configure the usb connection as HID-keyboad

  radio_begin(); //Set the radio up
}

void loop() {
  radio_receive();  // Receive button presses
  updateKeyboard(); // Convert them to keystrokes
}

void updateKeyboard() {
  for(int x=0; x<8; x++) {
    if(gamepad[x] == 0) {
      Keyboard.press(mapping[x]);
    }else{
      Keyboard.release(mapping[x]);
    }
  }
  
}
