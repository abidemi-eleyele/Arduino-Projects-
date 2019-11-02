const int analogInPin = A0;
const int analogOutPin = 9;
int sensorValue = 0;
int outputValue = 0;
void setup()
{
  Serial.begin(9600); // for computer communication
  pinMode(analogOutPin, OUTPUT); // indicate analog outpin as output
  pinMode(analogInPin, INPUT);	 // indicate analog input as input
}

void loop()
{
  sensorValue = analogRead(analogInPin); //read input pin and store in sensor value
  outputValue = map(sensorValue, 0, 1023, 0, 255); // scale down the value to the proper resolution
  analogWrite(analogOutPin, outputValue); // send the value to the analogoutpin which is connected to a led
  delay(500);
  
  analogWrite(9, 0);   // completely turns off the LED on pin 11
  delay(1000);
  analogWrite(9, 90);  // lights up the LED on pin 11 a little bit
  delay(1000);
  analogWrite(9, 255); // puts the LED on pin 11 to full brightness
  
  // display the information on a computer
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t output = ");      
  Serial.println(outputValue);
}
  
