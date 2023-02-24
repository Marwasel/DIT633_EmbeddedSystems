// Jonna Johansson, Nazli Moghaddam, Marwa Selwaye: Group 16 (2023)
// Work package 5
// Exercise 2
// Submission code: ZsW0_2i

// install DHTLIB

#include "dht.h";
dht DHT;

#define gLED 13
#define yLED 12
#define wLED 11
#define bLED 10
#define rLED 8
#define tempPin A0

// Initialize the temperatures ranges
const float temp1 = 25.60;
const float temp2 = 25.90;
const float temp3 = 26.00;
const float temp4 = 26.30;
const float temp5 = 26.60;

void setup()
{
 // Start the serial port
    Serial.begin(9600);
 // Set the led pins to output
    pinMode(gLED, OUTPUT);// set green led to OUTPUT,which will generate an elecatrical signal.
    pinMode(yLED, OUTPUT);// set yellow led to OUTPUT,which will generate an elecatrical signal.
    pinMode(wLED, OUTPUT);// set white led to OUTPUT,which will generate an elecatrical signal.
    pinMode(bLED, OUTPUT);// set blue led to OUTPUT,which will generate an elecatrical signal.
    pinMode(rLED, OUTPUT);// set red led to OUTPUT,which will generate an elecatrical signal.
  
  pinMode(tempPin, INPUT);//Set the temp Pin as an input, which will detect an incoming electrical signal
  
   // Set interrupt for temperature sensor,that triggers when there is a change in temp
  attachInterrupt(digitalPinToInterrupt(tempPin), TemperatureRange, CHANGE);

  // Periodically check temperature every 2 seconds
  setInterval();
  
}

void loop(){
//The loop is left empty to allow the 
//program to run uninterrupted.
}

void TemperatureRange()
{
 /* // Read the value from the temperature sensor pin
    int reading = analogRead(tempPin);
    // 1024 analogue if we have 5V. Hence, we do (analogReading * 5) / 1024. (ratios)
    // Convert the value into voltage by multiplying by 5 Volts
    float voltage = reading * 5.0;
    // Divide by the range of the value of temperature sensor (0-1023)
    voltage /= 1023;
    // Convert to degrees and consider the offset
    float tempInCelcius = (voltage - 0.5) * 100; // percentage max is because 10mV / 1degrees. Hence, 100 =  1/0.01. Voltage * (1 degrees / 0.01V) = Temp in celcius.
    Serial.print(tempInCelcius); Serial.println(" degrees C");*/
int readData = DHT.read22(tempPin);
   float tempInCelcius = DHT.temperature;
Serial.print(tempInCelcius); Serial.println("in degrees C");
  
  
//if temperature lower than 0 all leds are off
if(tempInCelcius<temp1){
    digitalWrite(gLED, LOW);//LED 1 off
    digitalWrite(yLED, LOW);//LED 2 off
    digitalWrite(wLED, LOW);//LED 3 off
    digitalWrite(bLED, LOW);//LED 4 off
    digitalWrite(rLED, LOW);//LED 5 off
} //if temperature between 0 and 19, 1 led on
else if(tempInCelcius>=temp1&&tempInCelcius<temp2){
    digitalWrite(gLED, HIGH);//LED 1 on
    digitalWrite(yLED, LOW);//LED 2 off
    digitalWrite(wLED, LOW);//LED 3 off
    digitalWrite(bLED, LOW);//LED 4 off
    digitalWrite(rLED, LOW);//LED 5 off
}//if temperature between 20 and 49, 2 leds on
else if(tempInCelcius>=temp2&&tempInCelcius<temp3){
    digitalWrite(gLED, HIGH);//LED 1 on
    digitalWrite(yLED, HIGH);//LED 2 on
    digitalWrite(wLED, LOW);//LED 3 off
    digitalWrite(bLED, LOW);//LED 4 off
    digitalWrite(rLED, LOW);//LED 5 off
} //if temperature betwwen 50 and 69, 3 leds on
else if(tempInCelcius>=temp3&&tempInCelcius<temp4){
    digitalWrite(gLED, HIGH);//LED 1 on
    digitalWrite(yLED, HIGH);//LED 2 on
    digitalWrite(wLED, HIGH);//LED 3 on
    digitalWrite(bLED, LOW);//LED 4 off
    digitalWrite(rLED, LOW);//LED 5 off
}//if temperature betwwen 70 and 99, 4 leds on
else if(tempInCelcius>=temp4&&tempInCelcius<temp5){
   digitalWrite(gLED, HIGH);//LED 1 on
    digitalWrite(yLED, HIGH);//LED 2 on
    digitalWrite(wLED, HIGH);//LED 3 on
    digitalWrite(bLED, HIGH);//LED 4 on
    digitalWrite(rLED, LOW);//LED 5 off
}//if temperature is higher than 100, all leds are on
else {
    digitalWrite(gLED, HIGH);//LED 1 on
    digitalWrite(yLED, HIGH);//LED 2 on
    digitalWrite(wLED, HIGH);//LED 3 on
    digitalWrite(bLED, HIGH);//LED 4 on
    digitalWrite(rLED, HIGH);//LED 5 on
}
}

//https://www.instructables.com/id/Arduino-Timer-Interrupts/
// Function to set interrupt interval
void setInterval() {
  //set timer1 interrupt at 1Hz
  cli(); //stop interrupts
  TCCR1A = 0; // set entire TCCR0A register A to 0, to set timer to normal mode
  TCCR1B = 0; // set entire TCCR0B register B to 0, to set timer to normal mode
  TCNT1 = 0; //initialize the timer counter to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  
  TCCR1B |= (1 << WGM12); //turn on ctc mode on the register B,
  //which stops the timer when the timer reaches OCR1A (15624).
  
  TCCR1B |= (1 << CS12) | (1 << CS10);// Set CS10 and CS12 bits for 1024 prescaler
  // which divides the clock frequency by 1024 and increases the interrupt period.
 
  TIMSK1 |= (1 << OCIE1A); //enable timer1 compare interrupt
  sei(); //allow interrupts to go back to normal
}

// Interrupt service routine for interrupt interval
ISR(TIMER1_COMPA_vect) {
  // Call Temperature Range function
  TemperatureRange();
}

