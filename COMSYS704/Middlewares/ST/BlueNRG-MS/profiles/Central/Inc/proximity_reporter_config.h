/**
  ******************************************************************************
  * @file    proximity_reporter_config.h
  * @author  AMS - VMA, RF Application Team
  * @brief   Configuration file for the proximity reporter profile central role
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
#ifndef __PROXIMITY_REPORTER_CONFIG_H
#define __PROXIMITY_REPORTER_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "master_basic_profile.h"

/******************** PTS PERIPHERAL ADDRESS *******************/

#define PTS_PERIPHERAL_ADDRESS {0x44, 0x06, 0x06, 0xdc, 0x1b, 0x00} //{0x00, 0x1B, 0xDC, 0x06, 0x06, 0x44} 

/* Expected Peer Address if any */
#define PEER_ADDRESS {0xfd, 0x00, 0x25, 0xec, 0x02, 0x04} //TBR

/******************** Device Init Parameters *******************/

#define PR_PUBLIC_ADDRESS          {0x22, 0x02, 0x00, 0xE1, 0x80, 0x02}
#define PR_DEVICE_NAME             {'P', 'X', 'R', '_', 'C'}
#define PR_TX_POWER_LEVEL          4

/******************** Device Security Parameters *******************/   

#define PR_IO_CAPABILITY    IO_CAP_KEYBOARD_DISPLAY
#define PR_MITM_MODE        MITM_PROTECTION_REQUIRED
#define PR_OOB_ENABLE       OOB_AUTH_DATA_ABSENT
#define PR_USE_FIXED_PIN    USE_FIXED_PIN_FOR_PAIRING
#define PR_FIXED_PIN        111111 
#define PR_BONDING_MODE     BONDING

/******************** Device Discovery Procedure Parameters *******************/
   
#define PR_LIM_DISC_SCAN_INT  0x30 // 30 ms 
#define PR_LIM_DISC_SCAN_WIND 0x30 // 30 ms 


/******************** Device Connection Parameters *******************/

#define PR_FAST_SCAN_DURATION 30000           // 30 sec
#define PR_FAST_SCAN_INTERVAL 48              // 30 ms
#define PR_FAST_SCAN_WINDOW   48              // 30 ms
#define PR_REDUCED_POWER_SCAN_INTERVAL 4096   // 2.56 sec
#define PR_REDUCED_POWER_SCAN_WINDOW   18     // 11.25 ms
#define PR_FAST_MIN_CONNECTION_INTERVAL 40    // 50 ms
#define PR_FAST_MAX_CONNECTION_INTERVAL 56    // 70 ms
#define PR_FAST_CONNECTION_LATENCY 0
#define PR_SUPERVISION_TIMEOUT 20             // 200 ms
#define PR_MIN_CONN_LENGTH 5                  // 3.125 ms
#define PR_MAX_CONN_LENGTH 5                  // 3.125 ms


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 

#endif /*__PROXIMITY_REPORTER_CONFIG_H */
