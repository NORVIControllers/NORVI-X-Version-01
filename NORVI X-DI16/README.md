# NORVI X-DI16

## An 16-Channel Digital Input Expansion Module

NORVI is always about connectivity and expandability, and the NORVI X-DI16 is designed to make full use of the Expansion port on NORVI Controllers. 
The series of expansion modules connect to NORVI IoT controllers via its I2C connections. This module provides 16-channels of digital inputs rated 
for 24 V DC, offering a robust solution for industrial sensing and monitoring.

At its core, the module integrates a PCA9555 I²C port expander, allowing the NORVI X CPU to read input states efficiently via the internal 
expansion bus. With four selectable I²C addresses, up to four DI16 modules can be connected on the same bus, providing a total of 64 digital 
inputs per controller.

## Address Selection Table

The following table defines the DIP switch configurations required to set the unique I²C address for each module.

| DIP 3 | DIP 2 | DIP 1 | I²C Address (Hex) |
| :---: | :---: | :---: | :---: |
| OFF | OFF | OFF | `0x27` |
| OFF | OFF | ON  | `0x26` |
| OFF | ON  | OFF | `0x25` |
| OFF | ON  | ON  | `0x24` |
| ON  | OFF | OFF | `0x23` |
| ON  | OFF | ON  | `0x22` |
| ON  | ON  | OFF | `0x21` |
| ON  | ON  | ON  | `0x20` |
