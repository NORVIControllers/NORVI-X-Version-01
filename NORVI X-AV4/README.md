# NORVI X-AV4
## 4-Channel Analog Input Expansion Module

The NORVI X modular controller platform. It provides four high-precision channels designed to monitor 0-10V DC signals, making it ideal for industrial sensing and measurement. The module utilizes precision signal amplifiers to condition incoming field signals, which are then digitized through an ADS1115 I²C ADC. This architecture ensures high-resolution, accurate data acquisition while minimizing the use of local MCU I/O pins.

System management and addressing are handled via the PCA9555 I/O expander, which integrates the module into the host controller’s $I^2C$ bus. This setup allows for seamless scalability within the modular environment without exhausting native processor resources. Field wiring is simplified through a dedicated terminal block, while the 16-bit resolution of the ADS1115 provides the sensitivity required for precise automation and monitoring tasks.
