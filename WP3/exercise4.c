#include <Keypad.h>


// configure the IO ports
const byte ROWS = 4; 
const byte COLS = 4; 
byte rowpins[ROWS] = {11, 10, 9, 8}; 
byte colpins[COLS] = {7, 6, 5, 4}; 
// Matrix for the keypad with each key's position
char keys[ROWS][COLS] = {{'1', '2', '3', 'A'},
                        {'4', '5', '6', 'B'},
                        {'7', '8', '9', 'C'},
                        {'*', '0', '#', 'D'}}; 
Keypad keypad = Keypad(makeKeymap(keys), rowpins, colpins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  char keypressed = keypad.getKey();
  if (keypressed != 0) {
    Serial.println(keypressed);
  }
}

