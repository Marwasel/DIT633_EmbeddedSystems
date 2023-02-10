// C++ code
//

#define green 13
#define red 12
#define blue 11
#define temperature A0


void setup()
{
  Serial.begin(9600); //initialize the serial
  pinMode(green, OUTPUT); // green as the output pin
  pinMode(red, OUTPUT); // red as the output pin
  pinMode(blue, OUTPUT); // blue as the output pin
  pinMode(10, OUTPUT);
  
  pinMode(temperature, INPUT);
  pinMode(A1, INPUT);
  
}

void loop()
{
  //source: https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage
  
  float voltage = (analogRead(temperature) * (5.0 / 1023.0)) * 1000; // Calculates the voltage from the analogread value.
  int celsius = (voltage - 500) / 10; // minivolts to celsius formula 
  									   
  Serial.println(celsius); // Prints the calculated celsius temperature.
  
  int light = analogRead(A1); // reading the value of analog sensor connected to A1
  int lightReading = map(light, 6, 679, 0, 100); // mapping the value
  analogWrite(10, lightReading);// write the mapped value to digital pin 10
 
  Serial.println(lightReading); // print light intensity
  
  delay(1000);//make program wait one second
  
  if (lightReading == 0){ //if light intensity is 0
    if (celsius <= -12){ // if temperature is less than -12
    	digitalWrite(green, HIGH); //green light on
    	digitalWrite(red, LOW); // red light off
      	digitalWrite(blue, LOW); // blue light off
    }
    else{
    	digitalWrite(red, HIGH);// red light on 
      	digitalWrite(green, LOW); // green light off
      	digitalWrite(blue, LOW); // blue light off
    }
  }
  
  else if (lightReading >= 1 && lightReading <= 20) {// if the light intensity is more than 1 and less than 20
    if(celsius > -12 && celsius <= 0){ // if the temperature is more than -12 and less than 0
      	digitalWrite(red, LOW); // red light off
      	digitalWrite(green, HIGH); // green light on 
      	digitalWrite(blue, LOW); // blue light off
    }
    else if (celsius > 0){ // if the temperature is more than 0
        digitalWrite(red, HIGH); // red light on 
      	digitalWrite(green, LOW); // green light off
      	digitalWrite(blue, LOW); // blue light off
    }
    else{
        digitalWrite(red, LOW); // red light off
      	digitalWrite(green, LOW); // green light off
      	digitalWrite(blue, HIGH); // blue light on 
    }
  }
  else if (lightReading >= 21 && lightReading <= 60){ // if the light intensity is more than 21 or less than 60
    if (celsius >= 0 && celsius <= 20){ // if the temerature is more than 0 and less than 20
    	digitalWrite(red, LOW); // red light off
      	digitalWrite(green, HIGH); // green light on 
      	digitalWrite(blue, LOW); // blue light off
    }
    else if(celsius > 20){ // if the temperature is more than 20
        digitalWrite(red, HIGH); // red light on 
      	digitalWrite(green, LOW); // green light off
      	digitalWrite(blue, LOW); // blue light off
    }
    else{
        digitalWrite(red, LOW);// red light off
      	digitalWrite(green, LOW); // green light off
      	digitalWrite(blue, HIGH); // blue light on 
    }
  }
  else{
    if(celsius >= 21){ // if the temperature is more than 21 
    	digitalWrite(red, LOW); // red light off
      	digitalWrite(green, HIGH); // green light on 
      	digitalWrite(blue, LOW); // blue light off
    }
    else{
    	digitalWrite(red, LOW); // red light off
      	digitalWrite(green, LOW); // green light off
      	digitalWrite(blue, HIGH); // blue light on 
    }
  
  }
}