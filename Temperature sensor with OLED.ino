/* This code reads the sensor value and display it on the OLED display*/

#include "Wire.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif
    #define address 0x4a

    #define baudrate 9600
    //baudrate for communication
    byte Temp = 0;
    int temperature;
    void setup()
    {
    Wire.begin();
    Serial.begin(baudrate);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
    display.display();
    delay(2000);
  // Clear the buffer.
    display.clearDisplay();
    }

    void loop()
    {
     // display the temperature On the OLED
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("Temp. in C: ");
    display.println(temperature);
    display.display();
    display.clearDisplay();
    
    Wire.beginTransmission(address); //start the transmission

    Wire.write(Temp); //send to the OLED screen 

    Wire.requestFrom(address, 1);
    if (Wire.available()) {
    temperature = Wire.read();
    }
    delay(2000);
    }
