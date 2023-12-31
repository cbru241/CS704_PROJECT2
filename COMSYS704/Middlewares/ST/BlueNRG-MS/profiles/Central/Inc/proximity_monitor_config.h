/**
  ******************************************************************************
  * @file    proximity_monitor_config.h
  * @author  AMS - VMA, RF Application Team
  * @brief   Proximity Monitor Central Configuration parameters
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2015 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PROXIMITY_MONITOR_CONFIG_H
#define __PROXIMITY_MONITOR_CONFIG_H

/******************** PTS PERIPHERAL ADDRESS *******************/
#define PTS_PERIPHERAL_ADDRESS {0x44, 0x06, 0x06, 0xdc, 0x1b, 0x00} // {0x33, 0x33, 0x07, 0xdc, 0x1b, 0x00} 

/******************** Device Init Parameters *******************/

#define PM_PUBLIC_ADDRESS          {0x88, 0x55, 0x44, 0x33, 0x22, 0x11}
#define PM_DEVICE_NAME             {'P', 'X', 'M'}
#define PM_TX_POWER_LEVEL          4
#define PM_ALERT_PATH_LOSS_ENABLED TRUE
#define PM_PATH_LOSS_THRESHOLD     0x17
#define PM_PATH_LOSS_TIMEOUT       2000 // 2 sec

/******************** Device Security Parameters *******************/   

#define PM_IO_CAPABILITY    IO_CAP_KEYBOARD_DISPLAY
#define PM_MITM_MODE        MITM_PROTECTION_REQUIRED
#define PM_OOB_ENABLE       OOB_AUTH_DATA_ABSENT
#define PM_USE_FIXED_PIN    USE_FIXED_PIN_FOR_PAIRING
#define PM_FIXED_PIN        123456
#define PM_BONDING_MODE     BONDING

/******************** Device Discovery Procedure Parameters *******************/
   
#define PM_LIM_DISC_SCAN_INT  0x30 // 30 ms 
#define PM_LIM_DISC_SCAN_WIND 0x30 // 30 ms 


/******************** Device Connection Parameters *******************/

#define PM_FAST_SCAN_DURATION 30000           // 30 sec
#define PM_FAST_SCAN_INTERVAL 48              // 30 ms
#define PM_FAST_SCAN_WINDOW   48              // 30 ms
#define PM_REDUCED_POWER_SCAN_INTERVAL 4096   // 2.56 sec
#define PM_REDUCED_POWER_SCAN_WINDOW   18     // 11.25 ms
#define PM_FAST_MIN_CONNECTION_INTERVAL 40    // 50 ms
#define PM_FAST_MAX_CONNECTION_INTERVAL 56    // 70 ms
#define PM_FAST_CONNECTION_LATENCY 0
#define PM_SUPERVISION_TIMEOUT 20             // 200 ms
#define PM_MIN_CONN_LENGTH 5                  // 3.125 ms
#define PM_MAX_CONN_LENGTH 5                  // 3.125 ms


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 

#endif /*__PROXIMITY_MONITOR_CONFIG_H */
