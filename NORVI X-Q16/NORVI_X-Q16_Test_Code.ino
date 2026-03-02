
//"NPD-NORVI X-DI16"
//2025.11.31

#include <Wire.h>
#include <WiFi.h>
#include <SPI.h>
#include "clsPCA9555.h"
#include "TFT_eSPI.h"
#include <CST816S.h>
#include "Free_Fonts.h" // Include the header file attached to this sketch

#define PCA_ADDR 0x27 // Base address starts at 0x74 for A0 = L and A1 = L

PCA9555 ioport(PCA_ADDR);

#define SDA   8     
#define SCL   9     

#define MISO 37
#define MOSI 35
#define SCLK 36

#define DSP_CS 45

#define TR1 0
#define TR2 1
#define TR3 2
#define TR4 3
#define TR5 4
#define TR6 5
#define TR7 6
#define TR8 7

#define TR9  15
#define TR10 14
#define TR11 13
#define TR12 12
#define TR13 11
#define TR14 10
#define TR15 9
#define TR16 8


CST816S touch(8, 9, 47, 48);  // sda, scl, rst, irq

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  delay(2000);
  
  Serial.println("NPD-NORVI X-DI16 TEST");
  delay(1000);

  Wire.begin(SDA, SCL);
  delay(100);

  I2C_SCAN();
  delay(100);

  ioport.pinMode(TR1, OUTPUT);
  ioport.pinMode(TR2, OUTPUT);
  ioport.pinMode(TR3, OUTPUT);
  ioport.pinMode(TR4, OUTPUT);
  ioport.pinMode(TR5, OUTPUT);
  ioport.pinMode(TR6, OUTPUT);
  ioport.pinMode(TR7, OUTPUT);
  ioport.pinMode(TR8, OUTPUT);
  ioport.pinMode(TR9, OUTPUT);
  ioport.pinMode(TR10, OUTPUT);
  ioport.pinMode(TR11, OUTPUT);
  ioport.pinMode(TR12, OUTPUT);
  ioport.pinMode(TR13, OUTPUT);
  ioport.pinMode(TR14, OUTPUT);
  ioport.pinMode(TR15, OUTPUT);
  ioport.pinMode(TR16, OUTPUT);

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
  tft.print("x-DI16 TEST");
}

void loop() {

  tft.fillScreen(TFT_BLACK);            // Clear screen
  tft.setTextColor(TFT_GREEN);
  tft.setFreeFont(FSB12);
  
  tft.setCursor(60, 20);      //xpos, ypos
  tft.print("NORVI");

  tft.setCursor(10, 40);      //xpos, ypos
  tft.print("EXPE-Q16 TEST");

  tft.setTextColor(TFT_YELLOW);
  tft.setCursor(10, 70);      //xpos, ypos
  tft.setFreeFont(FSB9);
  tft.print("TR1     :");

  tft.setCursor(10, 85);      //xpos, ypos
  tft.print("TR2     :");

  tft.setCursor(10, 100);      //xpos, ypos
  tft.print("TR3     :");

  tft.setCursor(10, 115);      //xpos, ypos
  tft.print("TR4     :");

  tft.setCursor(10, 130);      //xpos, ypos
  tft.print("TR5     :");

  tft.setCursor(10, 145);      //xpos, ypos
  tft.print("TR6     :");

  tft.setCursor(10, 160);      //xpos, ypos
  tft.print("TR7     :");

  tft.setCursor(10, 175);      //xpos, ypos
  tft.print("TR8     :");

  tft.setCursor(10, 190);      //xpos, ypos
  tft.print("TR9     :");

  tft.setCursor(10, 205);      //xpos, ypos
  tft.print("TR10   :");

  tft.setCursor(10, 220);      //xpos, ypos
  tft.print("TR11   :");

  tft.setCursor(10, 235);      //xpos, ypos
  tft.print("TR12   :");

  tft.setCursor(10, 250);      //xpos, ypos
  tft.print("TR13   :");

  tft.setCursor(10, 265);      //xpos, ypos
  tft.print("TR14   :");

  tft.setCursor(10, 280);      //xpos, ypos
  tft.print("TR15   :");

  tft.setCursor(10, 295);      //xpos, ypos
  tft.print("TR16   :");

 //---------------------------------------------------
  tft.setTextColor(TFT_WHITE);

  
  tft.setCursor(120, 70);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 1 : ON");
  ioport.digitalWrite(TR1,HIGH);
  delay(500);
  tft.setCursor(170, 70);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 1 : OFF");
  ioport.digitalWrite(TR1,LOW);
  delay(500);
  
  tft.setCursor(120, 85);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 2 : ON");
  ioport.digitalWrite(TR2,HIGH);
  delay(500);
  tft.setCursor(170, 85);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 2 : OFF");
  ioport.digitalWrite(TR2,LOW);
  delay(500);

  tft.setCursor(120, 100);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 3 : ON");
  ioport.digitalWrite(TR3,HIGH);
  delay(500);
  tft.setCursor(170, 100);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 3 : OFF");
  ioport.digitalWrite(TR3,LOW);
  delay(500);
  
  tft.setCursor(120, 115);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 4 : ON");
  ioport.digitalWrite(TR4,HIGH);
  delay(500);
  tft.setCursor(170, 115);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 4 : OFF");
  ioport.digitalWrite(TR4,LOW);
  delay(500);
  
 tft.setCursor(120, 130);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 5 : ON");
  ioport.digitalWrite(TR5,HIGH);
  delay(500);
  tft.setCursor(170, 130);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 5 : OFF");
  ioport.digitalWrite(TR5,LOW);
  delay(500);
  
  tft.setCursor(120, 145);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 6 : ON");
  ioport.digitalWrite(TR6,HIGH);
  delay(500);
  tft.setCursor(170, 145);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 6 : OFF");
  ioport.digitalWrite(TR6,LOW);
  delay(500);

  tft.setCursor(120, 160);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 7 : ON");
  ioport.digitalWrite(TR7,HIGH);
  delay(500);
  tft.setCursor(170, 160);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 7 : OFF");
  ioport.digitalWrite(TR7,LOW);
  delay(500);

  tft.setCursor(120, 175);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 8 : ON");
  ioport.digitalWrite(TR8,HIGH);
  delay(500);
  tft.setCursor(170, 175);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 8 : OFF");
  ioport.digitalWrite(TR8,LOW);
  delay(500);

  tft.setCursor(120, 190);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 9 : ON");
  ioport.digitalWrite(TR9,HIGH);
  delay(500);
  tft.setCursor(170, 190);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 9 : OFF");
  ioport.digitalWrite(TR9,LOW);
  delay(500);
  
  tft.setCursor(120, 205);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 10 : ON");
  ioport.digitalWrite(TR10,HIGH);
  delay(500);
  tft.setCursor(170, 205);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 10 : OFF");
  ioport.digitalWrite(TR10,LOW);
  delay(500);

  tft.setCursor(120, 220);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 11 : ON");
  ioport.digitalWrite(TR11,HIGH);
  delay(500);
  tft.setCursor(170, 220);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 11 : OFF");
  ioport.digitalWrite(TR11,LOW);
  delay(500);

  tft.setCursor(120, 235);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 12 : ON");
  ioport.digitalWrite(TR12,HIGH);
  delay(500);
  tft.setCursor(170, 235);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 12 : OFF");
  ioport.digitalWrite(TR12,LOW);
  delay(500);
  
  tft.setCursor(120, 250);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 13 : ON");
  ioport.digitalWrite(TR13,HIGH);
  delay(500);
  tft.setCursor(170, 250);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 13 : OFF");
  ioport.digitalWrite(TR13,LOW);
  delay(500);

  tft.setCursor(120, 265);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 14 : ON");
  ioport.digitalWrite(TR14,HIGH);
  delay(500);
  tft.setCursor(170, 265);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 14 : OFF");
  ioport.digitalWrite(TR14,LOW);
  delay(500);

  tft.setCursor(120, 280);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 15 : ON");
  ioport.digitalWrite(TR15,HIGH);
  delay(500);
  tft.setCursor(170, 280);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 15 : OFF");
  ioport.digitalWrite(TR15,LOW);
  delay(500);

  tft.setCursor(120, 295);      //xpos, ypos
  tft.print("ON");
  Serial.println("TR 16 : ON");
  ioport.digitalWrite(TR16,HIGH);
  delay(500);
  tft.setCursor(170, 295);      //xpos, ypos
  tft.print("OFF");
  Serial.println("TR 16 : OFF");
  ioport.digitalWrite(TR16,LOW);
  delay(500);

 
                              
  Serial.println("........................................................................");

  delay(10);
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
