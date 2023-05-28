# Major_Project_Electromagnetic_Fault_Injection_ASCON_using_ChipShouter_Varun_Narayanan
This project is based on hardware security, We implement the ASCON onto a M5STACK ESP32 module which contains a PSRAM. and use the ChipShouter to inject electromagnetic pulses onto the target module to inject faults into the ASCON algorithm. This will prove that ASCON is vulnerable to EMFI attacks. 

This repository contains an src folder where the ASCON code is implemented for the M5STACK ESP32 along with the ASCON library which is required in the code that calls the encryption and decryption functions. 
The code requires the M5STACK ESP32 module to run as it was specifically programmed for this module.





References:
1. https://ascon.iaik.tugraz.at/ - this site contains the details about ASCON cipher.
2. https://ascon.iaik.tugraz.at/implementations.html - this site shows the implementation of ASCON on different microcontrollers and other languages such as C, java, Rust, C assemble, etc.
