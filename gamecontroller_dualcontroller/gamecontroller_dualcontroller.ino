/* Define the pins for the keys to connect */
#define KEY_Y 2
#define KEY_B 3
#define KEY_A 4
#define KEY_X 5

/* Using macros will make the code easier to read and modify! */
#define VAL_KEY_Y digitalRead(KEY_Y)
#define VAL_KEY_B digitalRead(KEY_B)
#define VAL_KEY_A digitalRead(KEY_A)
#define VAL_KEY_X digitalRead(KEY_X)

#define KEY_UP A0
#define KEY_RIGHT A2
#define KEY_DOWN A1
#define KEY_LEFT A3

#define VAL_KEY_UP      digitalRead(KEY_UP)
#define VAL_KEY_RIGHT   digitalRead(KEY_RIGHT)
#define VAL_KEY_DOWN    digitalRead(KEY_DOWN)
#define VAL_KEY_LEFT    digitalRead(KEY_LEFT)

void setup() {
  /* Set pins as inputs with internal pullup resistors */
  pinMode(KEY_Y, INPUT_PULLUP);
  pinMode(KEY_B, INPUT_PULLUP);
  pinMode(KEY_A, INPUT_PULLUP);
  pinMode(KEY_X, INPUT_PULLUP);

  pinMode(KEY_UP, INPUT_PULLUP);
  pinMode(KEY_RIGHT, INPUT_PULLUP);
  pinMode(KEY_DOWN, INPUT_PULLUP);
  pinMode(KEY_LEFT, INPUT_PULLUP);

  /* Begin the radio module and set it up as a transmitter */
  radio_begin();
}

void loop() {
  /* Send the keys over every 10 ms */
  radio_send();
  delay(10); //Use delay to prevent overloading the buffer.
             // You could also clear the buffer manually, but it's always better to make sure it won't jam up
}
