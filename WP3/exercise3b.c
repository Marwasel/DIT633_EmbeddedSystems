// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 (2023)
// Work package 3
// Exercise 3b
// Submission code: RG0456-v


// Matrix for the keypad with each key's position
// A 2D char array named `keys` is defined to store the values of the keys 
char keys[4][4] = {{'1', '2', '3', 'A'},
                   {'4', '5', '6', 'B'},
                   {'7', '8', '9', 'C'},
                   {'*', '0', '#', 'D'}}; 

// Constants for the IO ports
const int Cols[4]={7,6,5,4};
const int Rows[4]={11,10,9,8};


void setup() {
 // initialize the serial communication. 
  Serial.begin(9600);
  
  // configure rows as outputs and initialize them to high state
  // The `digitalWrite` function is used to set the output pin to the high state.
  for (int i = 0; i < 4; i++) {
    pinMode(Rows[i], OUTPUT);
    digitalWrite(Rows[i], HIGH);
  }
  
  // configure columns as inputs with pull-up resistors
  // For each column, the `pinMode` function is used to set the mode of the pin as an input.
  // The `INPUT_PULLUP` argument is used to enable the internal pull-up resistor.
  for (int i = 0; i < 4; i++) {
    pinMode(Cols[i], INPUT_PULLUP);
  }
}

// `readKey` function is used to read the keypad
int readKey() {
  // loop through each row
  // For each row, the row is set to low by calling `digitalWrite(Rows[r], LOW)`
  // and the state of each column is checked to see if it's low or not.
  for (int r = 0; r < 4; r++) {
    digitalWrite(Rows[r], LOW);  // set current row low

    // check each column for a low signal
    for (int c = 0; c < 4; c++) {
      if (digitalRead(Cols[c]) == LOW) {
        
        // if a low signal is detected, the row is set to high and the index of the key
        digitalWrite(Rows[r], HIGH);
          // key index is returned by calculating `r * 4 + c`.
        return (r * 4 + c); 
      }
    }
    digitalWrite(Rows[r], HIGH);  // set current row high
  }
 

  return -1;  // return -1 if no key is pressed
}

void loop() {

 // call readKey function
  int keyIndex = readKey();

 // if a key is pressed
  if (keyIndex != -1) { 
    // print the key value based on position in matrix keys
    Serial.println(keys[keyIndex / 4][keyIndex % 4]); 
     // delay for 1 second
    delay(1000);
  }
}