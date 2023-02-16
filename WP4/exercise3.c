// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 (2023)
// Work package 4
// Exercise 3
// Submission code: 5384557753

/*
This program measures the temperature and displays different colors on a NeoPixel ring depending on the temperature.
- If the temperature is less than 0 the LEDs on the NeoPixel ring will turn blue, 
- temperature between 0-50 LEDs will turn green, 
- temperature more than 50 LEDs will turn red.
When all of the LEDs on the NeoPixel ring are on, an additional LED will turn on and a speaker will make a sound.
*/

//Included libraries
#include <Adafruit_NeoPixel.h>

//Constants
#define ringPin 2 
#define tempPin A0 
#define numPixels 24 //number of neopixels 
#define LED 9 
#define sound 12 


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, ringPin, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600); //initialize the serial
  pinMode(ringPin, OUTPUT); //initialize NeoPixel Ring as output
  pinMode(tempPin, INPUT); //initialize temperature sensor as input
  pinMode(LED, OUTPUT); //initialize red LED as output
  pinMode(sound, OUTPUT); //initialize speaker as output
  pixels.begin(); // Initialize the NeoPixel library.
  
}

void loop()
{
  int temp = analogRead(tempPin); //read temperature
  temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125); //convert temperature to celsius
  Serial.println(temp); //print temperature
  
  //loop through all pixels 
  for (int i=0; i < numPixels; i++) {
    
    //if temperature is less than 0, pixel color blue
    if (temp < 0){
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    }
    
    //if temperature is more than 50, pixel color red
    else if(temp > 50){
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    }
    
    //if temperature is between 0-50, pixel color green
    else {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    }
    
    //send updated pixel color to hardware
    pixels.show();
    delay(100);
  }
  //turn on LED when all pixels are on
  digitalWrite(LED, HIGH);
  
  //speaker makes sound when all pixels are on
  tone(sound, 100, 1000);
  delay(100);
}