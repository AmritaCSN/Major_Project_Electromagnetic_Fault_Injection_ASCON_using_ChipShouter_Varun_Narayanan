# Major_Project_Electromagnetic_Fault_Injection_ASCON_using_ChipShouter_Varun_Narayanan
This project is based on hardware security, We implement the ASCON cipher onto a M5STACK ESP32 module which contains a PSRAM. and use the ChipShouter to inject electromagnetic pulses onto the PSRAM of target module to inject faults into the ASCON algorithm. This will prove that ASCON is vulnerable to EMFI attacks. 

This repository contains an src folder where the ASCON code is implemented for the M5STACK ESP32 along with the ASCON library which is required in the code that calls the encryption and decryption functions. 
The M5STACK ESP32 module is required for the code to operate, The code may also be executed on other ESP32 family modules containing a PSRAM.


SPECIFICATION OF DEVICE:
PSRAM -	8MB,
Flash	 - 4MB,
Image Sensor	- OV3660,
Maximum resolution	- 3M pixels,
Output format	-  8-/10-Bit RAW, RGB and YCbCr output, compression,
DFOV	-  66.5°,
Battery Interface Specifications -	SH1.0-2P,
Net Weight -	6g,
Gross Weight -	17g,
Product Size -	45*20*12mm,
Package Size -	60*60*15mm,

Below image shows the M5STACK ESP32 Module 

![image](https://github.com/AmritaCSN/Major_Project_Electromagnetic_Fault_Injection_ASCON_using_ChipShouter_Varun_Narayanan/assets/123752463/9557e066-0516-4b37-82fe-6bbf1f9ca690)

![250](https://github.com/AmritaCSN/Major_Project_Electromagnetic_Fault_Injection_ASCON_using_ChipShouter_Varun_Narayanan/assets/123752463/e3c0e622-a5fd-488f-8873-7c3a29f3e4d4)
This image shows Fault Occurrence for Encryption & Decryption Processes for a 250 Kb String Value

![500](https://github.com/AmritaCSN/Major_Project_Electromagnetic_Fault_Injection_ASCON_using_ChipShouter_Varun_Narayanan/assets/123752463/f34a3441-55ed-4496-9249-b5abf4b358ad)
This image shows Fault Occurrence for Encryption & Decryption Processes for a 500 Kb String Value

![1MB](https://github.com/AmritaCSN/Major_Project_Electromagnetic_Fault_Injection_ASCON_using_ChipShouter_Varun_Narayanan/assets/123752463/1ef110d9-cda7-491c-a60c-179d7cf33ff5)

This image shows Fault Occurrence for Encryption & Decryption Processes for 1Mb String Value





REFERENCES:
1. https://ascon.iaik.tugraz.at/ - this site contains the details about ASCON cipher.
2. https://ascon.iaik.tugraz.at/implementations.html - this site shows the implementation of ASCON on different microcontrollers and other languages such as C, java, Rust, C assemble, etc.
3. https://docs.m5stack.com/en/quick_start/timer_cam/arduino - this link provides the library and necessary files reuqired for running the M5STACK ESP32 Mdoule
