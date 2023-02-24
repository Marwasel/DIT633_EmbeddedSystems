// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 (2023)
// Work package 5
// Exercise 3
// Submission code: ZsW0_2i

#include "dht.h";
dht DHT;

#define gLED 13
#define rLED 11
#define bLED 9
#define tempPin A0
#define lightPin A1

void setup()
{
  Serial.begin(9600); //initialize the serial
  pinMode(gLED, OUTPUT); // green as the output pin, which will generate an electrical signal.
  pinMode(rLED, OUTPUT); // red as the output pin, which will generate an electrical signal.
  pinMode(bLED, OUTPUT); // blue as the output pin, which will generate an electrical signal.
 // pinMode(10, OUTPUT);
  
  pinMode(tempPin, INPUT);
  pinMode(lightPin, INPUT);
  // Initate the serial port
    Serial.begin(9600);
  
}

void loop()
{
  /*//getting the voltage reading from the value on the temperature sensor pin
 int reading = analogRead(tempPin); 
  
  // converting the reading to voltage by multiplying by 5v
 float voltage = reading * 5.0;
  //1024 analogue if we have 5V.
 voltage /= 1023.03; 
  
  //printing the voltage
 Serial.print(voltage); Serial.println(" volts");
 
 // Calculating  temperature in celcius
  float tempInCelsius = (voltage - 0.5) * 100 ;
  
  Serial.print(tempInCelsius); Serial.println(" degrees C");*/
  
 int readData = DHT.read22(tempPin);
   float tempInCelsius = DHT.temperature;
   Serial.print(tempInCelsius); Serial.println(" degrees C");


  // Read the data from the photoresistor
    int lightReading = analogRead(lightPin);
 // Serial.print(lightReading);
    // Map the data on a scale from 0% to 100%
   lightReading = map(lightReading, 11, 830, 0, 100);
    // Print the light persentage to serial
   analogWrite(10, lightReading);// write the mapped value to digital pin 10

  Serial.print(lightReading); Serial.println(" Light intensity");

  
  if (lightReading == 0){ //if light intensity value is 0
    // if temperature is less than -12C, power on the green LED
    if (tempInCelsius <= -12){ 
    	digitalWrite(gLED, HIGH); //green LED on
    	digitalWrite(rLED, LOW); // red LED off
      	digitalWrite(bLED, LOW); // blue LED off
    }
    else{// If the temperature is higher than -12
         // Power on the red LED
    	digitalWrite(rLED, HIGH);// red LED on 
      	digitalWrite(gLED, LOW); // green LED off
      	digitalWrite(bLED, LOW); // blue LED off
    }
  }
  // if the light intensity is between 1 and 20
  else if (lightReading >= 1 && lightReading <= 20) {
    // if the temperature is between -12 and 0, Power on the green LED
    if(tempInCelsius > -12 && tempInCelsius <= 0){ 
      	digitalWrite(rLED, LOW); // red LED off
      	digitalWrite(gLED, HIGH); // green LED on 
      	digitalWrite(bLED, LOW); // blue LED off
    }
    // if the temperature is more than 0, Power on the red LED
    else if (tempInCelsius > 0){ 
        digitalWrite(rLED, HIGH); // red LED on 
      	digitalWrite(gLED, LOW); // green LED off
      	digitalWrite(bLED, LOW); // blue LED off
    }
    else{ // If the temperature is lower than -12, Power on the blue led
        digitalWrite(rLED, LOW); // red LED off
      	digitalWrite(gLED, LOW); // green LED off
      	digitalWrite(bLED, HIGH); // blue LED on 
    }
  }
  // if the light intensity isbetween 21 and 60
  else if (lightReading >= 21 && lightReading <= 55){ 
    // if the temperature is betwwen 0 and 20, Power on the green LED
    if (tempInCelsius >= 0 && tempInCelsius <= 20){ 
    	digitalWrite(rLED, LOW); // red LED off
      	digitalWrite(gLED, HIGH); // green LED on 
      	digitalWrite(bLED, LOW); // blue LED off
    }
    else if(tempInCelsius > 20){ // if the temperature is more than 20, Power on the red LED
        digitalWrite(rLED, HIGH); // red LED on 
      	digitalWrite(gLED, LOW); // greenLED off
      	digitalWrite(bLED, LOW); // blue LED off
    }
    else{ // else If the temperature is lower than 0, Power on the blue LED
        digitalWrite(rLED, LOW);// red LED off
      	digitalWrite(gLED, LOW); // green light off
      	digitalWrite(bLED, HIGH); // blue LED on 
    }
  }
  // finally, if the light intensity value is between 61 and 100
  else{ 
    if(tempInCelsius >= 21){ // if the temperature is more than 21, Power on the green LED
    	digitalWrite(rLED, LOW); // red LED off
      	digitalWrite(gLED, HIGH); // green LED on 
      	digitalWrite(bLED, LOW); // blue LED off
    }
    // If the temperature is lower than 21C, Power on the blue LED
    else{
    	digitalWrite(rLED, LOW); // red LED off
      	digitalWrite(gLED, LOW); // green LED off
      	digitalWrite(bLED, HIGH); // blue LED on 
    }
  
  }
  delay(2000);//delay program by one second
}
