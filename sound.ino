const int buttonPin = 6;     // Number of the pin connected to the push-button
const int ledPin =  13;      // Number of the pin connected to the LED

// Declaring the variables :
int buttonState = 0;         // This variable 'buttonState' will be used to store the state of the button

// This code is executed once on boot-up
void setup() {
  // ledPin is an output:
  pinMode(ledPin, OUTPUT);      
  // buttonPin is an input:
  pinMode(buttonPin, INPUT);     
}

// This code is executed over and over again as a loop
void loop(){
  // read the state of the button and store in buttonState
  buttonState = digitalRead(buttonPin);

  // Check to see if buttonState is HIGH (5V), i.e. if the button is pressed
  if (buttonState == HIGH) {     
    // light up the LED
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // if the button is not pressed, turn off the LED
    digitalWrite(ledPin, LOW); 
  }
}
