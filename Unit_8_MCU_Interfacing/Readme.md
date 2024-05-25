# Unit 8: MCU Interfacing
In this unit, the main goal is to learn the different Communication Protocols that are used in MCU Interfacing.
<br>It's divided into 7 lectures as follows :
<details>
<summary> Lecture 1: MCU IO Electrical Characteristics </summary>
- Logic Values based on different Technology.</br>
- Encoding Bits. <br>
- Logic Families. <br>
- MCU IO Electrical Characteristics. <br>
- AMR (Absolute Maximum Ratings).
</details>

<details>
<summary> Lecture 2: UART Protocol  </summary>
- Interfacing Main Concepts. </br>
- Communication Specs Big Picture. </br>
- Wire standard conjugation with USART Protocol. </br>
- USART Controller General Circuit. </br>
- UART General Configuration.  </br>
- USART Block Diagram on Atmega32.  </br>
- USART Block Diagram on STM32F103X.  </br>
- USART Block Diagram on TM4C123.  </br>
- Lab 1: Atmega32 UART Driver Interfacing with virtual Terminal & LCD.
</details>

<details>
<summary> Lecture 3: UART STM32 Controller  </summary>
- USART Logic Level in STM32F103xx. </br>
- NRZ (non-return-to-zero). </br>
- UART Over Sampling Mechanism. </br>
- How to read the USART Chapter from TRM for X SoC. </br>
- How to write UART Driver.  </br>
- Lab 1: STM32 UART using polling mechanism.  </br>
- Lab 2: STM32 UART using Interrupt mechanism.
</details>


<details>
<summary> Lecture 4: SPI Protocol  </summary>
- SPI (Serial Peripheral Interface) Protocol Characteristics. </br>
- How SPI works. </br>
- SPI Bus Configuration. </br>
- Multiple slave cascaded. </br>
- SPI with Flash Memories.  </br>
- SPI Bus 3-Wire.  </br>
- QUAD SPI.  </br>
- Lab 1: SPI Communication Between 2 Atmega32. </br>
- Lab 2: Atmega32 SPI Communication with MAX7221.
</details>

<details>
<summary> Lecture 5: SPI STM32 Controller  </summary>
- SPI Controller in STM32F103xx. </br>
- How to read the SPI Chapter from TRM for X SoC. </br>
- How to write SPI Driver.  </br>
- Lab 1: STM32 Terminal UART ---> SPI Communication.  </br>
- Lab 2: STM32 SPI & UART communication between Master and Slave.
</details>

<details>
<summary> Lecture 6: I2C Protocol  </summary>
- I2C Characteristics. </br>
- I2C Evolution. </br>
- I2C Speed Categories. </br>
- I2C Pins and open-drain usage. </br>
- I2C Bus troubleshooting.  </br>
- I2C Bus Characteristics.  </br>
- How I2C work.  </br>
- I2C data sampling.  </br>
- I2C ACK, NACK, No ACK.  </br>
- I2C Arbitration.  </br>
- I2C Clock Stretching.  </br>
- Multibyte burst W/R.  </br>
- I2C Clock Synchronization.  </br>
- UART vs I2C vs SPI.  </br>
- Lab 1: Atmega32 TWI Master Transimetter --> Slave Reciever.  </br>
- Lab 2: Atmega32 TWI Slave Transimetter --> Master Reciever.
</details>

<details>
<summary> Lecture 7: SPI STM32 Controller  </summary>
- I2C Protocol for (7Bit vs 10Bit Addressing). </br>
- Sending data to I2C Slave via polling mechanism. </br>
- Transferring data via DMA on I2C Master.  </br>
- I2C Programmable Timings.  </br>
- Interfacing with serial digital TC74 Temperature sensor.  </br>
- I2C Controller in STM32F103xx.  </br>
- How to read the I2C Chapter from TRM for X SoC. </br>
- EEPROM I2C Slave Driver.  </br>
- Lab 1: STM32 I2C Master ---> EEPROM Slave.  
</details>
