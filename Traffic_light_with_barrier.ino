/*
Traffic lights with a barrier.
When the button is pressed the closed barrier opens
and the red traffic light turns green for five seconds.
*/

#include <Servo.h>
Servo myservo; // create an object called myservo using the Servo library

// Declaring the constants :
const int buttonPin = 2; // Number of the pin connected to the push-button
const int ledRed = 3; // Number of the pin connected to the red LED
const int ledGreen = 4; // Number of the pin connected to the green LED
const int Servo = 9; // Number of the pin connected to the servor motor LED

// Declaring the variables :
int buttonState = LOW; // This variable 'buttonState' will be used to store the state of the button
int pos = 0; // declare a variable for storing the position of the servo arm

// This code is executed once on boot-up
void setup()
{
Serial.begin(9600); // Initialise communication with the computer
myservo.attach(9); //Attach the object myservo to the servo on pin 9
myservo.write(0); //Initializing the original state of servo i.e. at 0°
pinMode(3, OUTPUT); //Red LED pin is OUTPUT
pinMode(4, OUTPUT); //Green LED pin is OUTPUT
pinMode(2, INPUT); //Button pin is an INPUT
}

// This code is executed over and over again as a loop
void loop()
{
digitalWrite(3,HIGH); //Red light supposed to remain on till button is pressed
buttonState = digitalRead(buttonPin);//Read the state of the button and store in buttonState
if (buttonState == HIGH) //Check to see if buttonPin is HIGH (5V), i.e. if the button is pressed
{
Serial.println("Button Pressed"); //Serial monitor will display the message i.e. Button Pressed
digitalWrite(3, LOW); //Red light to switch off
digitalWrite(4, HIGH); //Green light to switch on
for(pos = 0; pos <= 90; pos += 1) // go from 0° to 90°
{ // one step at a time
myservo.write(pos); // go to the position stored in 'pos'
delay(15); // wait 15ms for the servo to move to position
}
delay(5000); //Wait for 5s for the servo to remain open
digitalWrite(4,LOW); //Green light to switch off
digitalWrite(3,HIGH); //Red light to switch on
for(pos = 90; pos >= 0; pos-=1) // go from 90° to 0°
{
myservo.write(pos); // go to the position stored in 'pos'
delay(15); // wait 15ms for the servo to move to position
}
}
}
