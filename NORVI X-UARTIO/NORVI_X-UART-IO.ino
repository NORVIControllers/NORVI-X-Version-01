#include <Wire.h>
#include "PCA9539.h"

PCA9539 ioport(0x75);

// ================= MODE =================
uint8_t mode = 1;
uint8_t lastMode = 0;

// ================= PINS =================
#define PORT_RST 38

#define RS485_RXD 5
#define RS485_TXD 11
#define FC1 PCA_B3

#define RS232_RXD 6
#define RS232_TXD 12
#define FC2 PCA_A6

#define UARTA_RXD 7
#define UARTA_TXD 13
#define FC3 PCA_B4  

#define UARTB_RXD 10
#define UARTB_TXD 14
#define FC4 PCA_A7  

#define SDA 8     
#define SCL 9 

// ================= SETUP =================
void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin(SDA, SCL);

  pinMode(PORT_RST, OUTPUT);
  digitalWrite(PORT_RST, HIGH);
  delay(100);

  ioport.pinMode(FC1, OUTPUT);
  ioport.pinMode(FC2, OUTPUT);
  ioport.pinMode(FC3, OUTPUT);
  ioport.pinMode(FC4, OUTPUT);

  printCommands();
  I2C_SCAN();
}

// ================= LOOP =================
void loop() {

  // ----- READ COMMAND -----
  if (Serial.available()) {
    char input = Serial.read();

    if (input == '1') mode = 1;
    else if (input == '2') mode = 2;
    else if (input == '3') mode = 3;

    Serial.print("MODE SELECTED: ");
    Serial.println(mode);
  }

  // ----- MODE CHANGE -----
  if (mode != lastMode) {
    Serial.println("MODE CHANGED");

    switch (mode) {
      case 1: setupFirstCode(); break;
      case 2: setupSecondCode(); break;
      case 3: setupThirdCode(); break;
    }
    lastMode = mode;
  }

  // ----- RUN MODE -----
  switch (mode) {
    case 1: firstCode(); break;
    case 2: secondCode(); break;
    case 3: thirdCode(); break;
  }
}

// ================= MODE 1 =================
void setupFirstCode() {
  Serial.println("MODE 1: RS485-B + RS232");

  Serial1.end();
  Serial2.end();

  Serial1.begin(115200, SERIAL_8N1, RS485_RXD, RS485_TXD);
  Serial2.begin(115200, SERIAL_8N1, RS232_RXD, RS232_TXD);
}

void firstCode() {
  RS485_TEST();
  RS232_TEST();
  delay(1000);
}

// ================= MODE 2 =================
void setupSecondCode() {
  Serial.println("MODE 2: UARTA + UARTB");


  Serial1.end();
  Serial2.end();

  Serial1.begin(115200, SERIAL_8N1, UARTA_RXD, UARTA_TXD);
  Serial2.begin(115200, SERIAL_8N1, UARTB_RXD, UARTB_TXD);
}

void secondCode() {
  UARTA_TEST();
  UARTB_TEST();
  delay(1000);
}

// ================= MODE 3 =================
void setupThirdCode() {
  Serial.println("MODE 3: RS485-A");

  Serial1.end();
  Serial1.begin(115200, SERIAL_8N1, RS485_RXD, RS485_TXD);
}

void thirdCode() {
  ioport.digitalWrite(FC1, HIGH);
  delay(50);

  Serial1.println("RS485 02 SUCCESS");
  Serial1.flush();

  delay(100);
  while (Serial1.available()) {
    Serial.write(Serial1.read());
  }
  delay(1000);
}

// ================= TEST FUNCTIONS =================
void RS485_TEST() {
  
  ioport.digitalWrite(FC1, LOW);
  delay(50);

  Serial1.println("RS485 01 SUCCESS");
  Serial1.flush();

  delay(500);
  while (Serial1.available()) {
    Serial.write(Serial1.read());
  }
   delay(1000);
}

void RS232_TEST() {
  ioport.digitalWrite(FC2, LOW);
  delay(50);

  Serial2.println("RS232 01 SUCCESS");
  Serial2.flush();

  delay(50);
  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }

  ioport.digitalWrite(FC2, HIGH);
  delay(50);

  Serial2.println("RS232 02 SUCCESS");
  Serial2.flush();

  delay(50);
  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }
}

void UARTA_TEST() {
  ioport.digitalWrite(FC3, LOW);
  delay(50);

  Serial1.println("UARTA 01 SUCCESS");
  Serial1.flush();

  delay(50);
  while (Serial1.available()) {
    Serial.write(Serial1.read());
  }

  ioport.digitalWrite(FC3, HIGH);
  delay(50);

  Serial1.println("UARTA 02 SUCCESS");
  Serial1.flush();

  delay(50);
  while (Serial1.available()) {
    Serial.write(Serial1.read());
  }
}

void UARTB_TEST() {
  ioport.digitalWrite(FC4, LOW);
  delay(50);

  Serial2.println("UARTB 01 SUCCESS");
  Serial2.flush();

  delay(50);
  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }

  ioport.digitalWrite(FC4, HIGH);
  delay(50);

  Serial2.println("UARTB 02 SUCCESS");
  Serial2.flush();

  delay(50);
  while (Serial2.available()) {
    Serial.write(Serial2.read());
  }
}

// ================= I2C SCAN =================
void I2C_SCAN() {
  Serial.println("Scanning I2C...");
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found I2C: 0x");
      Serial.println(addr, HEX);
    }
  }
  Serial.println("I2C Scan Done");
}

// ================= MENU =================
void printCommands() {
  Serial.println();
  Serial.println("========= COMMAND MENU =========");
  Serial.println("1 -> RS485A / RS232 MODE");
  Serial.println("2 -> UARTA / UARTB MODE");
  Serial.println("3 -> RS485B MODE");
  Serial.println("================================");
}
