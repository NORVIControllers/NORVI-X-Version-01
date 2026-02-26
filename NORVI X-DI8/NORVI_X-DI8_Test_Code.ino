
//"NPD-NORVI X-DI8"

#include <Wire.h>
#include <WiFi.h>
#include <SPI.h>
#include <PCA9538.h>
#include "TFT_eSPI.h"
#include <CST816S.h>
#include "Free_Fonts.h" // Include the header file attached to this sketch

// I2C address of PCA9538
#define PCA9538_ADDR 0x73

#define SDA   8     
#define SCL   9     

#define MISO 37
#define MOSI 35
#define SCLK 36

#define DSP_CS 45

#define PCA_RESET 21

#define INPUT1   1 
#define INPUT2   2
#define INPUT3   3
#define INPUT4   4
#define INPUT5   5
#define INPUT6   6
#define INPUT7   7
#define INPUT8   8

PCA9538 io(PCA9538_ADDR);

CST816S touch(8, 9, 47, 48);  // sda, scl, rst, irq

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  delay(2000);
  
  Serial.println("NPD-NORVI X-DI8 TEST");
  delay(1000);

  pinMode(PCA_RESET, OUTPUT);
  delay(100);
  digitalWrite(PCA_RESET, HIGH);

  Wire.begin(SDA, SCL);
  delay(100);

  I2C_SCAN();
  delay(1000);

  io.pinMode(INPUT1, INPUT);
  io.pinMode(INPUT2, INPUT);
  io.pinMode(INPUT3, INPUT);
  io.pinMode(INPUT4, INPUT);
  io.pinMode(INPUT5, INPUT);
  io.pinMode(INPUT6, INPUT);
  io.pinMode(INPUT7, INPUT);
  io.pinMode(INPUT8, INPUT);

  SPI.begin(SCLK, MISO, MOSI); // Ensure these pin numbers are correct 
  delay(1000);

  tft.init();
  tft.begin();
  tft.setRotation(0);

  tft.fillScreen(TFT_BLACK);            // Clear screen
  tft.setTextColor(TFT_YELLOW);
  tft.setFreeFont(FSB12);
  
  tft.setCursor(60, 20);      //xpos, ypos
  tft.print("NORVI");

  tft.setCursor(20, 40);      //xpos, ypos
  tft.print("X-DI8 TEST");
}

void loop() {

  tft.fillScreen(TFT_BLACK);            // Clear screen
  tft.setTextColor(TFT_YELLOW);
  tft.setFreeFont(FSB12);
  
  tft.setCursor(60, 20);      //xpos, ypos
  tft.print("NORVI");

  tft.setCursor(20, 40);      //xpos, ypos
  tft.print("X-DI8 TEST");

  tft.setTextColor(TFT_RED);
  tft.setCursor(10, 70);      //xpos, ypos
  tft.setFreeFont(FSB9);
  tft.print("I1");

  tft.setCursor(30, 70);      //xpos, ypos
  tft.print("I2");

  tft.setCursor(50, 70);      //xpos, ypos
  tft.print("I3");

  tft.setCursor(70, 70);      //xpos, ypos
  tft.print("I4");

  tft.setCursor(90, 70);      //xpos, ypos
  tft.print("I5");

  tft.setCursor(110, 70);      //xpos, ypos
  tft.print("I6");

  tft.setCursor(130, 70);      //xpos, ypos
  tft.print("I7");

  tft.setCursor(150, 70);      //xpos, ypos
  tft.print("I8");

  tft.setTextColor(TFT_WHITE);
  tft.setCursor(10, 90);      //xpos, ypos
  tft.print(io.digitalRead(INPUT1));
  Serial.printf("Input1: %d\n",io.digitalRead(INPUT1));

  tft.setCursor(30, 90);      //xpos, ypos
  tft.print(io.digitalRead(INPUT2));
  Serial.printf("Input2: %d\n",io.digitalRead(INPUT2));

  tft.setCursor(50, 90);      //xpos, ypos
  tft.print(io.digitalRead(INPUT3));
  Serial.printf("Input3: %d\n",io.digitalRead(INPUT3));

  tft.setCursor(70, 90);      //xpos, ypos
  tft.print(io.digitalRead(INPUT4));
  Serial.printf("Input4: %d\n",io.digitalRead(INPUT4));

  tft.setCursor(90, 90);      //xpos, ypos
  tft.print(io.digitalRead(INPUT5));
  Serial.printf("Input5: %d\n",io.digitalRead(INPUT5));

  tft.setCursor(110, 90);      //xpos, ypos
  tft.print(io.digitalRead(INPUT6));
  Serial.printf("Input6: %d\n",io.digitalRead(INPUT6));

  tft.setCursor(130, 90);      //xpos, ypos
  tft.print(io.digitalRead(INPUT7));
  Serial.printf("Input7: %d\n",io.digitalRead(INPUT7));

  tft.setCursor(150, 90);      //xpos, ypos
  tft.print(io.digitalRead(INPUT8));
  Serial.printf("Input8: %d\n",io.digitalRead(INPUT8));
  Serial.println("........................................................................");

  delay(1000);
}


void I2C_SCAN() {
  byte error, address;
  int deviceCount = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.print(address, HEX);
      Serial.println("  !");

      deviceCount++;
      delay(1);  // Wait for a moment to avoid overloading the I2C bus
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }

  if (deviceCount == 0) {
    Serial.println("No I2C devices found\n");
  }
  else {
    Serial.println("Scanning complete\n");
  }
}
