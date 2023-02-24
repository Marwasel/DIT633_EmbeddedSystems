// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 (2023)
// Work package 5
// Exercise 1
// Submission code: ZsW0_2i

int lightSpeed = 0;
int buttonClick = 0;
int led1 = 13;
int led2 = 8;


void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
    pinMode(2, INPUT_PULLUP); // set button pin to pin2
}

void loop()
{
  // button should be read from the pin its connected to pin 2
  buttonClick = digitalRead(2);
  // Condition to check if button is clicked
  if (buttonClick == HIGH) {
    // LED should light up
    digitalWrite(led2, HIGH);
  } else {
    // LED should not light up
    digitalWrite(led2, LOW);
  }
  // the time between blinks for light set to half a second
  lightSpeed = 500;
  // Call LED to light up
  digitalWrite(led1, HIGH);
  // Wait for the time interval given
  delay(lightSpeed); 
  // Call LED to turn light off
  digitalWrite(led1, LOW);
  // Wait for time interval given
  delay(lightSpeed); 
}