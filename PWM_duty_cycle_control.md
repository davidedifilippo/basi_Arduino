## PWM_duty_cycle_control

Board's pin we intend to use in the project:

    const int ledPin = 9;      // LED is connected to PWM capable pin 9
    const int analogPin = 3;   // potentiometer isnconnected to analog pin 3

We need a variable to store the analog ddp values read on AN3 input:

     int vin = 0;   

if analog_Vin = 0 V we know that:

     const int minV = 0;

if analog_Vin = 5V we know that:

     const int maxV = 1023; 
      

## Setup module

In this code section we have to initialize the Asynchronous Serial communication interface:

     Serial.begin(9600);
     Serial.println("LED brightness control start....");

## Loop module

Read the ddp value on AN0 pin:

    vin = analogRead(analogPin);  

AnalogRead values go from 0 to 1023, needed analogWrite dutyCyle values from 0 to 255:
   
    int dutyCycle= map(vin, minV, maxV, 0, 255); //mapping vin = 0 -> dutyCycle = 0 ... vin = 1023 -> dutyCycle = 255 
  
Set PWM signal dutyCycle to chosen value:

    analogWrite(ledPin, dutyCycle); 
    
Print debug info:
  
    Serial.print("duty cycle: ");
    Serial.println(dutyCycle);
  
Wait 200 milliseconds:

  delay(200);
 
