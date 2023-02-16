// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 (2023)
// Work package 3
// Exercise 2
// Submission code 5384557753

// servo library to control the servo motor
#include <Servo.h>

// create a servo motor object
Servo servo;
// to triger the interuppts
volatile int count=0;
void setup() { 
  // initialize the port communication
  Serial.begin(9600);
  // attach the servo to pin 9 to connect it to board
   servo.attach(9);
  // attach an interrupt on the servo pin for any change happening and triger change
  // using the secTrig function 
  attachInterrupt(digitalPinToInterrupt(9),secTrig,CHANGE);
}
void loop(){ 
  // Loop from 0 to 360 in increments of 6 for i,
  // and from 0 to 60 for j
  for (int i=0,j=0;i<=360,j<=60;i+=6,j++){
     // If i is less than or equal to 180, 
     // then write the value of i to the servo.
    if(i<=180){
    servo.write(i);
    }else{
     // If i is greater than 180, subtract 180 from it 
     // and write the result to the servo. 
      servo.write(i-180);
    }
    // Increment the interrupt count
    count++;
    // when count is more the 0, print the second on serial monitor 
    if(count>0){ 
   Serial.println(j);
    }
    // wait 1 second between every itterasion
    delay(1000);
  }
  }
//trigger the count change
void secTrig() {
// when called, set the count to opposite
  count=!count;
}
