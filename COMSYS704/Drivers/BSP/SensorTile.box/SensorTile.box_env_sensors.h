/**
******************************************************************************
* @file    SensorTile.box_env_sensors.h
* @author  SRA - Central Labs
* @version V1.3.5
* @date    10-Feb-2022
* @brief   This file contains definitions for the BSP Motion Sensors interface
******************************************************************************
* @attention
*
* Copyright (c) 2022 STMicroelectronics.
* All rights reserved.
*
* This software is licensed under terms that can be found in the LICENSE file
* in the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
******************************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SENSORTILE_BOX_ENV_SENSORS_H__
#define __SENSORTILE_BOX_ENV_SENSORS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "SensorTile.box_conf.h"
#include "env_sensor.h"

#ifndef USE_ENV_SENSOR_HTS221_0
#define USE_ENV_SENSOR_HTS221_0          1
#endif

#ifndef USE_ENV_SENSOR_LPS22HH_0
#define USE_ENV_SENSOR_LPS22HH_0          1
#endif
  
#ifndef USE_ENV_SENSOR_STTS751_0
#define USE_ENV_SENSOR_STTS751_0          1
#endif
  
#if (USE_ENV_SENSOR_HTS221_0 == 1)
#include "hts221.h"
#endif
  
#if (USE_ENV_SENSOR_LPS22HH_0 == 1)
#include "lps22hh.h"
#endif
  
#if (USE_ENV_SENSOR_STTS751_0 == 1)
#include "stts751.h"
#endif  

#if (USE_ENV_SENSOR_HTS221_0 == 1)
#define HTS221_0 (0)
#endif

#if (USE_ENV_SENSOR_LPS22HH_0 == 1)
#define LPS22HH_0 (USE_ENV_SENSOR_HTS221_0)
#endif
  
#if (USE_ENV_SENSOR_STTS751_0 == 1)
#define STTS751_0 (USE_ENV_SENSOR_HTS221_0 + USE_ENV_SENSOR_LPS22HH_0)
#endif
  
/* Environmental Sensor instance Info */
typedef struct
{
  uint8_t Temperature;
  uint8_t Pressure;
  uint8_t Humidity;
  uint8_t LowPower;
  float   HumMaxOdr;
  float   TempMaxOdr;
  float   PressMaxOdr;
} ENV_SENSOR_Capabilities_t;

typedef struct
{
  uint32_t Functions;
} ENV_SENSOR_Ctx_t;

#define ENV_TEMPERATURE      1U
#define ENV_PRESSURE         2U
#define ENV_HUMIDITY         4U

#define ENV_FUNCTIONS_NBR    3U
#define ENV_INSTANCES_NBR    (USE_ENV_SENSOR_HTS221_0 + USE_ENV_SENSOR_LPS22HH_0 + USE_ENV_SENSOR_STTS751_0)

#if (ENV_INSTANCES_NBR == 0)
#error "No environmental sensor instance has been selected"
#endif

int32_t BSP_ENV_SENSOR_Init(uint32_t Instance, uint32_t Functions);
int32_t BSP_ENV_SENSOR_DeInit(uint32_t Instance);
int32_t BSP_ENV_SENSOR_GetCapabilities(uint32_t Instance, ENV_SENSOR_Capabilities_t *Capabilities);
int32_t BSP_ENV_SENSOR_ReadID(uint32_t Instance, uint8_t *Id);
int32_t BSP_ENV_SENSOR_Enable(uint32_t Instance, uint32_t Function);
int32_t BSP_ENV_SENSOR_Disable(uint32_t Instance, uint32_t Function);
int32_t BSP_ENV_SENSOR_GetOutputDataRate(uint32_t Instance, uint32_t Function, float *Odr);
int32_t BSP_ENV_SENSOR_SetOutputDataRate(uint32_t Instance, uint32_t Function, float Odr);
int32_t BSP_ENV_SENSOR_GetValue(uint32_t Instance, uint32_t Function, float *Value);

#ifdef __cplusplus
}
#endif

#endif /* __SENSORTILE_BOX_ENV_SENSORS_H__ */
