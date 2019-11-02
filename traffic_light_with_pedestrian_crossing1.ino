/*
  This program is for Arduino Traffic Light with pedestrian crossing features
  by Abidemi Eleyele a rookie
  
 */

#include <Servo.h>
Servo myservo;
int pos = 0;

const int buttonPin = 2; // pin 2 connected to the button pin
const int ledPin  = 8;  // pin 8 connected to pedestrian green light
int buttonState = 0;    // This variable 'buttonState' will be used to store the state of the button
void setup()
{
  Serial.begin(9600);
  
  pinMode(9,  OUTPUT);  // red light for pede
  pinMode(10, OUTPUT); // pin 10 connected to green declared as output
  pinMode(11, OUTPUT); // pin 11 connected to orange declared as output
  pinMode(12, OUTPUT); // pin 12 connected to red declared as output
  pinMode(buttonPin, INPUT); // button declared as input
  pinMode(ledPin, OUTPUT); // Pedestrian green light
}

void loop()
{
  buttonState = digitalRead(buttonPin); // read the button state whe
  digitalWrite(10, HIGH);   // GREEN light turns on first
  //delay(100);
   if (buttonState==HIGH){
    digitalWrite(ledPin, HIGH); 
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    delay(5000);
    }
    else {
    digitalWrite(9, HIGH);
    }
  
  delay(3000);
  digitalWrite(10, LOW);  // GREEN is off   
  digitalWrite(11, HIGH);   // ORANGE is on
  delay(1000);        // Wait for 1000 millisecond(s)
  digitalWrite(11, LOW);  // ORANGE is off
  digitalWrite(12, HIGH); // RED is on 
  delay(3000);        // Wait for 3000 millisecond(s)
  digitalWrite(12, LOW);  // RED is off

 
  }
 