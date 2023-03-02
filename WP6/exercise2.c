// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 (2023)
// Work package 6
// Exercise 2
// Submission code: ER764_i

/*
This program measures the distance of an object by using an ultrasonic distance sensor
It can detect an object that is closer than 200 cm.
The closer the object is the more leds turn on and the speaker sound increases
If the object is closer than 25 cm all the leds are on and the speaker makes an annoying sound.
*/



// Initialize variables
int distanceThreshold = 0; // Distance threshold to activate LEDs
int cm = 0; // Distance in centimeters
const int speakerPin = 9; // Pin number for the LED

// Function to read the distance from an ultrasonic sensor
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  // Clear the trigger pin
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Set the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Read the echo pin and return the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  // Set up the serial communication and pin modes
  Serial.begin(9600);
  pinMode(speakerPin, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  // Set threshold distance to activate LEDs
  distanceThreshold = 200;
  
  // Read distance in centimeters from ultrasonic sensor
  cm = 0.01723 * readUltrasonicDistance(7, 7); // Calculate distance in cm from time in microseconds
  Serial.print(cm);
  Serial.println("cm, ");
  
  // Map distance to a sound level between 200 and 2000 Hz
  int soundLevel = map(cm, 26, 200, 200, 2000);
  
  // Turn off all LEDs if distance is greater than threshold
  if (cm > distanceThreshold) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  
  // Turn on first LED and activate sound if distance is less than 200 cm
  if (cm < 200) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(speakerPin, LOW);
    tone(speakerPin, soundLevel, 10);
  }
  
  // Turn on first and second LEDs and activate sound if distance is less than 150 cm
  if (cm < 150) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(speakerPin, HIGH);
    tone(speakerPin, soundLevel, 25);
  }
  
  // Turn on first, second, and third LEDs and activate sound if distance is less than 100 cm
  if (cm < 100) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(speakerPin, HIGH);
    tone(speakerPin, soundLevel, 40);
  }
  
  // Turn on all LEDs and activate sound if distance is less than or equal to 30 cm
  if (cm <= 30) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(speakerPin, LOW);
    tone(speakerPin, soundLevel, 55);
  }
    // Turn on all LEDs, activate sound, and increase sound duration if distance is less than or equal to 25 cm
    if (cm <= 25) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(speakerPin, HIGH);
    tone(speakerPin, soundLevel, 100);
  }
  delay(100); // Wait for 100 milliseconds
}