# NORVI X-R4 Relay Expansion Module Example

This example demonstrates how to use the **Relay Expansion Module (R4)** on the **NORVI X platform**. The purpose of this example is to show how to integrate the R4 Module into the NORVI X CPU. This example can be used as a starting point for developers building applications with **NORVI controllers**.

**Product Used:** NORVI X Relay Expansion Module (R4)  
**Platform:** NORVI X CPU  
**Website:** https://norvi.io

## Purpose of This Example

This example demonstrates how to:

- Initialize the **PCA9538 I/O expander** at address `0x73`
- Control four relay outputs (**RELAY 1 – RELAY 4**) via **I2C**
- Display real-time relay status (**ON/OFF**) on the integrated **TFT display** and **Serial Monitor**

The program continuously reads 

- **NO1 to NO4**. 

The current input states are shown on the **built-in TFT display** and **Serial Monitor**.

## Running the Example

Follow the steps below to run the example.

### 1. Hardware Connections

Connect the **NORVI X CPU** and **R4 expansion module** correctly. 

Connect relay output signals to:

- **NO1 – NO4**

Ensure the signal is within the **supported output range**.

---

### 2. Configure the Program

Ensure the I2C pins are correctly defined:  
SDA → Pin 8  
SCL → Pin 9

#### Address Selection

| DIP 1 | DIP 2 | DIP 3 | DIP 4 | I²C Address |
|-------|-------|-------|-------|-------------|
| OFF   | OFF   | -     | -     | 0x73        |
| ON    | OFF   | -     | -     | 0x72        |
| OFF   | ON    | -     | -     | 0x71        |
| ON    | ON    | -     | -     | 0x70        |

---
### 3. Upload the Program

1. Open the example program in **Arduino IDE / PlatformIO**  
2. Select the correct **board and port**  
3. Upload the program to the **NORVI controller**

---
## Open Serial Monitor

Set the **baud rate** to `115200`.

---
### 5. Observe the Display

When the program runs successfully:

- The controller initializes the **display**  
- The **TFT screen** shows the R4 test screen  
- The status of each output (**RELAY 1 – RELAY 4**) is displayed as **ON/OFF**  
- Values update continuously as outputs change

### Example Output on the Serial Monitor
```
RELAY 1 : ON
RELAY 1 : OFF
RELAY 2 : ON
RELAY 2 : OFF
...
RELAY 4 : ON
RELAY 4 : OFF
```
### Example Output on the TFT Screen
```
RELAY 1 : ON OFF
RELAY 2 : ON OFF
RELAY 3 : ON OFF
RELAY 4 : ON OFF
```

## How to Validate the Example

To verify the example works correctly:

1. Observe the output  
2. Check the **Serial Monitor** for status updates  
3. Confirm that changing the output state is reflected correctly in both the **TFT display** and **Serial Monitor**

## Device Preparation / Configuration

Before running the example, ensure:

- The controller is **powered correctly**  
- Required signals are **connected**  
- Any required **configuration** is completed

Example:

**Power Supply:** 24V DC  

## Required Libraries

Install the following libraries before compiling:

- Wire  
- WiFi  
- SPI  
- PCA9538 Library  
- TFT_eSPI  
- CST816S  

Download Libraries:  
https://github.com/NORVIControllers/NORVI-X-Version-01/tree/main/libraries

### Installation

1. Open **Arduino IDE**  
2. Go to **Library Manager**  
3. Search and install the required libraries

## Limitations

- This example is provided for **demonstration purposes**  
- Additional calibration may be required for **precise measurements**  
- Performance may depend on **sensor accuracy** and environmental conditions

## Safety Notes

- Do **not exceed the rated input voltage**  
- Ensure **proper grounding**  
- Incorrect wiring may **damage the controller**

## Test Information

**Test Date:** 2026-03-10  
**Verified By:** Kaveesha

## Support

Documentation: https://norvi.io/docs  

Datasheet: https://norvi.io/docs/norvi-x-r4-datasheet/  

For additional support or inquiries, contact the **NORVI support team**.

## License

This example is provided for **development and educational purposes**.
