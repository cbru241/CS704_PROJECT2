/**
  ******************************************************************************
  * @file    phone_alert_status_server_config.h
  * @author  AMS - VMA, RF Application Team
  * @brief   Configuration file for phone alert status server profile
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
#ifndef __PHONE_ALERT_STATUS_SERVER_CONFIG_H
#define __PHONE_ALERT_STATUS_SERVER_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "master_basic_profile.h"

/******************** PTS PERIPHERAL ADDRESS *******************/

#define PTS_PERIPHERAL_ADDRESS {0x44, 0x06, 0x06, 0xdc, 0x1b, 0x00} //{0x00, 0x1B, 0xDC, 0x06, 0x06, 0x44} 

/* Expected Peer Address if any */
#define PEER_ADDRESS {0xfd, 0x00, 0x25, 0xec, 0x02, 0x04} //TBR

/******************** Device Init Parameters *******************/

#define PASS_PUBLIC_ADDRESS          {0x22, 0x02, 0x00, 0xE1, 0x80, 0x02}
#define PASS_DEVICE_NAME             {'P', 'A', 'S', 'S', '_', 'C'}
#define PASS_TX_POWER_LEVEL          4

/******************** Device Security Parameters *******************/   

#define PASS_IO_CAPABILITY    IO_CAP_KEYBOARD_DISPLAY
#define PASS_MITM_MODE        MITM_PROTECTION_REQUIRED
#define PASS_OOB_ENABLE       OOB_AUTH_DATA_ABSENT
#define PASS_USE_FIXED_PIN    USE_FIXED_PIN_FOR_PAIRING
#define PASS_FIXED_PIN        111111 
#define PASS_BONDING_MODE     BONDING

/******************** Device Discovery Procedure Parameters *******************/
   
#define PASS_LIM_DISC_SCAN_INT  0x30 // 30 ms 
#define PASS_LIM_DISC_SCAN_WIND 0x30 // 30 ms 


/******************** Device Connection Parameters *******************/

#define PASS_FAST_SCAN_DURATION 30000           // 30 sec
#define PASS_FAST_SCAN_INTERVAL 48              // 30 ms
#define PASS_FAST_SCAN_WINDOW   48              // 30 ms
#define PASS_REDUCED_POWER_SCAN_INTERVAL 4096   // 2.56 sec
#define PASS_REDUCED_POWER_SCAN_WINDOW   18     // 11.25 ms
#define PASS_FAST_MIN_CONNECTION_INTERVAL 40    // 50 ms
#define PASS_FAST_MAX_CONNECTION_INTERVAL 56    // 70 ms
#define PASS_FAST_CONNECTION_LATENCY 0
#define PASS_SUPERVISION_TIMEOUT 20             // 200 ms
#define PASS_MIN_CONN_LENGTH 5                  // 3.125 ms
#define PASS_MAX_CONN_LENGTH 5                  // 3.125 ms


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 

#endif /*__PHONE_ALERT_STATUS_SERVER_CONFIG_H */
