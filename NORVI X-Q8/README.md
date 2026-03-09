# NORVI X – Q8 Transistor Output Expansion Example

## Overview
This example demonstrates how to use the **Transistor Outputs Expansion Module (Q8)** on the **NORVI X platform**.

The purpose of this example is to show how to:

- Integrate the **Q8 Module** into the NORVI X CPU  
- Read the status of **8 transistor outputs**  
- Integrate the **PCA9538 I/O expander** to control digital outputs  
- Use the **TFT_eSPI library** to display real-time status updates  
- Implement a basic **I2C scanner** to detect connected peripherals  

This example can be used as a starting point for developers building applications with **NORVI controllers**.

---

## Product Used

**Product:** NORVI X Transistor Output Expansion Module (Q8)  
**Platform:** NORVI X CPU  

Website: [https://norvi.io](https://norvi.io)

---

## Purpose of This Example

The example demonstrates:

- **Control Outputs:** Sequentially toggle eight transistor outputs (**TR1 – TR8**) via the PCA9538 expander  
- **Visual Feedback:** Display the current "ON/OFF" status of each output on the integrated TFT screen  
- **System Diagnostics:** Print the status of each output and I2C scan results to the Serial Monitor  

The program continuously updates:

- **TR1 to TR8**  

The current output states are shown on the **built-in TFT display** and **Serial Monitor**.

---

## Running the Example

### 1. Hardware Connections

1. Connect the **NORVI X CPU** and **Q8 expansion module** correctly  
2. Connect transistor output signals to **TR1 – TR8**  
3. Ensure the signals are within the supported **input/output range**

---

### 2. Configure the Program

Ensure the **I2C pins** are correctly defined:

- **SDA → Pin 8**  
- **SCL → Pin 9**

---

### 3. I2C Address Selection

The I2C address of the module can be configured using the DIP switches:

| DIP 1 | DIP 2 | DIP 3 | DIP 4 | I2C Address |
|-------|-------|-------|-------|-------------|
| OFF   | OFF   | –     | –     | 0x73        |
| ON    | OFF   | –     | –     | 0x72        |
| OFF   | ON    | –     | –     | 0x71        |
| ON    | ON    | –     | –     | 0x70        |

> **Note:** DIP 3 and DIP 4 are not used for address selection in this setup.

---

### 4. Upload the Program

1. Open the example program in **Arduino IDE / PlatformIO**  
2. Select the correct **board** and **port**  
3. Upload the program to the **NORVI controller**

---

### 5. Open Serial Monitor

Set the **Baud Rate** to:

```
115200
```

---

### 6. Observe the Display

When the program runs successfully:

- The controller initializes the TFT display  
- The screen shows **DI16 test screen**  
- The status of each output (**TR1 – TR8**) is displayed as **ON/OFF**  
- Values update continuously as outputs change  

---

## Example Output

### Serial Monitor

```
TR1 : ON
TR1 : OFF
TR2 : ON
TR2 : OFF
...
TR8 : ON
TR8 : OFF
```

### TFT Display

```
TR1 : ON OFF
TR2 : ON OFF
...
TR8 : ON OFF
```

---

## How to Validate the Example

1. Apply a valid input signal  
2. Observe the outputs on the **TFT screen**  
3. Check the **Serial Monitor** for status updates  
4. Confirm that changing the output state reflects correctly in both TFT and Serial Monitor  

---

## Device Preparation / Configuration

Before running the example:

- Ensure the controller is **powered correctly**  
- Required signals are **connected**  
- Any necessary configuration is **completed**

---

## Required Libraries

Install the following libraries before compiling:

```
Wire
WiFi
SPI
clsPCA9555
TFT_eSPI
CST816S
```

Library download:  
[https://github.com/NORVIControllers/NORVI-X-Version-01/tree/main/libraries](https://github.com/NORVIControllers/NORVI-X-Version-01/tree/main/libraries)

**Installation Steps:**

1. Open **Arduino IDE**  
2. Go to **Library Manager**  
3. Search and install the required libraries  

---

## Limitations

- This example is provided for **demonstration purposes**  
- Additional calibration may be required for **precise operation**  
- Performance depends on **sensor accuracy and environmental conditions**  

---

## Safety Notes

- Do not exceed the **rated input/output voltage**  
- Ensure proper **grounding**  
- Incorrect wiring may **damage the controller**

---

## Test Information

**Test Date:** 2026-03-09  
**Verified By:** Kaveesha  

---

## Documentation

NORVI Documentation:  
[https://norvi.io/docs](https://norvi.io/docs)  

Datasheet:  
[https://norvi.io/docs/norvi-x-q8-datasheet/](https://norvi.io/docs/norvi-x-q8-datasheet/)

---

## Support

For additional support or inquiries, contact the **NORVI support team**.

---

## License

This example is provided for **development and educational purposes**.
