
## <b>Virtual_COM_Port Application Description</b>
  
This application is an example to be loaded in order to use the BlueNRG GUI with BlueNRG-2 
development platforms.

Example Description:

Virtual_COM_Port is the application to be used with the BlueNRG GUI SW package 
(the STSW-BNRGUI available on st.com). 
The BlueNRG GUI is a PC application that can be used to interact and evaluate the 
capabilities of the BlueNRG-2 device both in master and slave role. 
The BlueNRG GUI allows standard and vendor-specific HCI commands to be sent to the 
device controller and events to be received from.
To establish the serial connection between the GUI on the PC and the Nucleo board the
Serial Port Baud Rate must be set to 115200 baud/sec.

Known limitations:

- When starting the project from Example Selector in STM32CubeMX and regenerating 
  it from ioc file, you may face a build issue. To solve it, remove from the IDE project 
  the file stm32l4xx_nucleo.c in Application/User virtual folder and delete from Src and 
  Inc folders the files: stm32l4xx_nucleo.c, stm32l4xx_nucleo.h and stm32l4xx_nucleo_errno.h.

### <b>Keywords</b>

BLE, SPI, USART

### <b>Directory contents</b>

 - app_bluenrg_2.c        Virtual_COM_Port initialization and applicative code
  
 - hci_tl_interface.c     Interface to the BlueNRG HCI Transport Layer 
 
 - main.c                 Main program body
  
 - stm32**xx_hal_msp.c    Source code for MSP Initialization and de-Initialization

 - stm32**xx_it.c         Source code for interrupt Service Routines

 - stm32**xx_nucleo.c     Source file for the BSP Common driver 
						
 - stm32**xx_nucleo_bus.c Source file for the BSP BUS IO driver
 
 - system_stm32**xx.c     CMSIS Cortex-Mx Device Peripheral Access Layer
                          System Source File
  
### <b>Hardware and Software environment</b>

  - This example runs on STM32 Nucleo devices with BlueNRG-2 STM32 expansion board
    (X-NUCLEO-BNRG2A1)
  - This example has been tested with STMicroelectronics:
    - NUCLEO-L476RG RevC board

ADDITIONAL_BOARD : X-NUCLEO-BNRG2A1 https://www.st.com/content/st_com/en/products/ecosystems/stm32-open-development-environment/stm32-nucleo-expansion-boards/stm32-ode-connect-hw/x-nucleo-bnrg2a1.html
ADDITIONAL_COMP : BlueNRG-M2SP https://www.st.com/content/st_com/en/products/wireless-connectivity/short-range/bluetooth-low-energy-application-processors/bluenrg-m2.html
  
### <b>How to use it?</b>

In order to make the program work, you must do the following:
 - WARNING: before opening the project with any toolchain be sure your folder
   installation path is not too in-depth since the toolchain may report errors
   after building.
 - Open STM32CubeIDE (this firmware has been successfully tested with Version 1.6.1).
   Alternatively you can use the Keil uVision toolchain (this firmware
   has been successfully tested with V5.32.0) or the IAR toolchain (this firmware has 
   been successfully tested with Embedded Workbench V8.50.9).
 - Rebuild all files and load your image into target memory.
 - Run the example.
 - Alternatively, you can download the pre-built binaries in "Binary" 
   folder included in the distributed package.

### <b>Author</b>

SRA Application Team

### <b>License</b>

Copyright (c) 2021 STMicroelectronics.
All rights reserved.

This software is licensed under terms that can be found in the LICENSE file
in the root directory of this software component.
If no LICENSE file comes with this software, it is provided AS-IS.
