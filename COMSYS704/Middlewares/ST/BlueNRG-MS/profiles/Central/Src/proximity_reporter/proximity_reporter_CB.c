/**
  ******************************************************************************
  * @file    proximity_reporter_CB.c
  * @author  AMS - VMA, RF Application Team
  * @brief   Source code for the proximity reporter callbacks handler (profile
  *          central role)
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
/******************************************************************************
* Include Files
******************************************************************************/
#include <host_config.h>
#include <hci.h>
#include <debug.h>
#include <ble_list.h>
#include <timer.h>
#include <uuid.h>
#include <master_basic_profile.h>

#if (BLE_CURRENT_PROFILE_ROLES & PROXIMITY_REPORTER)

#include <proximity_reporter.h>
#include <proximity_reporter_config.h>

/******************************************************************************
* Macro Declarations
******************************************************************************/
#define WEAK_FUNCTION(x) __weak x
/******************************************************************************
* type definitions
******************************************************************************/

/******************************************************************************
* Variable Declarations
******************************************************************************/

/******************************************************************************
* Imported Variable
******************************************************************************/

/******************************************************************************
* Function Prototypes
******************************************************************************/

/*******************************************************************************
* exported CallBacks
*******************************************************************************/  

void Master_DeviceDiscovery_CB(uint8_t *status, uint8_t *addr_type, uint8_t *addr, 
			       uint8_t *data_length, uint8_t *data, 
			       uint8_t *RSSI)
{
  uint8_t i;

  if (*status == DEVICE_DISCOVERED) {
    CALLBACKS_MESG_DBG(profiledbgfile, "**** Device Discovered ****\r\n");
    CALLBACKS_MESG_DBG(profiledbgfile, "Addr Type = %d\r\n", *addr_type);
    CALLBACKS_MESG_DBG(profiledbgfile, "Addr = 0x");
    for (i=0; i<6; i++)
      CALLBACKS_MESG_DBG(profiledbgfile, "%02x", addr[i]);
    CALLBACKS_MESG_DBG(profiledbgfile, "\r\n");
    CALLBACKS_MESG_DBG(profiledbgfile, "Data (Length=%d):\r\n", *data_length);
    for (i=0; i<*data_length; i++)
      CALLBACKS_MESG_DBG(profiledbgfile, "%02x ", data[i]);
    CALLBACKS_MESG_DBG(profiledbgfile, "\r\n");
    CALLBACKS_MESG_DBG(profiledbgfile, "RSSI = 0x%02x\r\n", *RSSI);
    CALLBACKS_MESG_DBG(profiledbgfile, "**************************\r\n");
  }

  if (*status == DEVICE_DISCOVERY_PROCEDURE_ENDED) {
    if (proximity_reporter_context.state != PROXIMITY_REPORTER_START_CONNECTION)
      proximity_reporter_context.state = PROXIMITY_REPORTER_INITIALIZED;
    CALLBACKS_MESG_DBG(profiledbgfile,"**** Device Discovery Procedure ended from the application\r\n");
  }

  if (*status == DEVICE_DISCOVERY_PROCEDURE_TIMEOUT) {
    proximity_reporter_context.state = PROXIMITY_REPORTER_INITIALIZED;
    CALLBACKS_MESG_DBG(profiledbgfile,"**** Device Discovery Procedure Timeout\r\n");    
  }  

  PXR_DeviceDiscovery_CB(*status, *addr_type, addr, *data_length, data, *RSSI);
}

void Master_Connection_CB(uint8_t *connection_evt, uint8_t *status, 
			  uint16_t *connection_handle, connUpdateParamType *param)
{
  switch (*connection_evt) {
  case DISCONNECTION_EVT:
    {
      proximity_reporter_context.state = PROXIMITY_REPORTER_INITIALIZED;
      
      PXR_ConnectionStatus_CB(*connection_evt, *status);
      CALLBACKS_MESG_DBG(profiledbgfile, "**** Disconnection Event Received\r\n");
      
      PXR_Alert_CB(EVT_PR_PATH_LOSS_ALERT,NO_ALERT);
      /* though the application will know about link loss through
       * the disconnection event to the main profile, this event is sent
       * so that the application starts the alerting procedure only when
       * the proximity reporter was running and the alert is of the level
       * specified by the client
       */ 
       PXR_Alert_CB(EVT_PR_LINK_LOSS_ALERT,proximity_reporter_context.linkLossAlertLevel);    
    }
    break;
  case CONNECTION_ESTABLISHED_EVT:
    {
      if (*status == BLE_STATUS_SUCCESS) {
	CALLBACKS_MESG_DBG(profiledbgfile, "**** Connection Established with Success\r\n");
	proximity_reporter_context.connHandle = *connection_handle;  
	proximity_reporter_context.state = PROXIMITY_REPORTER_CONNECTED;
	PXR_ConnectionStatus_CB(*connection_evt, *status);
      }
    }
    break;
  case CONNECTION_FAILED_EVT:
    {
      CALLBACKS_MESG_DBG(profiledbgfile, "**** Connection Failed with Status 0x%02x\r\n", *status);
      proximity_reporter_context.state = PROXIMITY_REPORTER_INITIALIZED;

      PXR_ConnectionStatus_CB(*connection_evt, *status);
    }
    break;
  case STOP_CONNECTION_PROCEDURE_EVT:
    {
      CALLBACKS_MESG_DBG(profiledbgfile, "**** Stop Connection Procedure from the application\r\n");
      proximity_reporter_context.state = PROXIMITY_REPORTER_INITIALIZED;
    }
    break;
  case CONNECTION_UPDATE_PARAMETER_REQUEST_EVT:
    {
      CALLBACKS_MESG_DBG(profiledbgfile, "**** Connection Parameter Update Request\r\n");
      proximity_reporter_context.state = PROXIMITY_REPORTER_CONN_PARAM_UPDATE_REQ;
      PXR_ConnectionParameterUpdateReq_CB((pxrConnUpdateParamType*) param);
    }
    break;
  }
}

void Master_ServiceCharacPeerDiscovery_CB(uint8_t *procedure, uint8_t *status, uint16_t *connection_handle)
{
}

void Master_PeerDataExchange_CB(uint8_t *procedure, uint8_t *status, uint16_t *connection_handle, dataReceivedType *data)
{ 
  CALLBACKS_MESG_DBG(profiledbgfile,"Conn handle: 0x%04x Procedure 0x%02x Ended with status = 0x%02x\n", *connection_handle, *procedure, *status);
  
  if (*procedure == NOTIFICATION_INDICATION_CHANGE_STATUS) 
  {
    CALLBACKS_MESG_DBG(profiledbgfile,"Master_PeerDataExchange_CB(), event: NOTIFICATION_INDICATION_CHANGE_STATUS\r\n");
  }

  if ((*procedure == READ_VALUE_STATUS) ||  
      (*procedure == READ_LONG_VALUE_STATUS)) 
  {
    CALLBACKS_MESG_DBG(profiledbgfile,"Read Procedure %d: \r\n", *procedure);
  }

  if (*procedure == WRITE_VALUE_STATUS) 
  {
    CALLBACKS_MESG_DBG(profiledbgfile,"WRITE_VALUE_STATUS, Write Status = 0x%02x\r\n", *status);
  }

  if (*procedure == NOTIFICATION_DATA_RECEIVED) 
  {
    CALLBACKS_MESG_DBG(profiledbgfile,"NOTIFICATION_DATA_RECEIVED: handle=0x%04x, data length=%d, data:\r\n",
	   data->attr_handle, data->data_length);      
  }
  
  if (*procedure == INDICATION_DATA_RECEIVED ) 
  {
    
    CALLBACKS_MESG_DBG(profiledbgfile,"INDICATION_DATA_RECEIVED: handle=0x%04X, data length=%d\n",data->attr_handle,data->data_length);
  }
  
  if (*procedure == ATTRIBUTE_MODIFICATION_RECEIVED)
  {
    CALLBACKS_MESG_DBG(profiledbgfile,"ATTRIBUTE_MODIFICATION_RECEIVED: handle=0x%04X, data length=%d\n",data->attr_handle,data->data_length);
    for (uint8_t i=0; i<data->data_length; i++) {
      CALLBACKS_MESG_DBG(profiledbgfile,"%02x ", data->data_value[i]);
    }
    CALLBACKS_MESG_DBG(profiledbgfile,"\r\n");
      
    PXR_Received_Alert_Handler(data->attr_handle, data->data_value[0]);
  }
  
}/* end Master_PeerDataExchange_CB() */

void Master_Pairing_CB(uint16_t *conn_handle, uint8_t *status)
{
  CALLBACKS_MESG_DBG(profiledbgfile,"Pairing CB conn_handle = 0x%04x with status = 0x%02x***************\n", *conn_handle, *status);
  if (*status == BLE_STATUS_SUCCESS)
  {
    if (aci_gap_configure_whitelist()!= BLE_STATUS_SUCCESS) //TBR
        CALLBACKS_MESG_DBG(profiledbgfile,"Error during aci_gap_configure_whitelist() function call\r\n");
  }
  PXR_Pairing_CB(*conn_handle, *status);
  
  if (*status == PASS_KEY_REQUEST) {
     PXR_PinCodeRequired_CB();
  }
}/* end Master_Pairing_CB() */

void Master_PeerDataPermitExchange_CB(uint8_t * procedure, uint16_t * connection_handle, dataPermitExchangeType * data) 
{
  CALLBACKS_MESG_DBG(profiledbgfile,"Conn handle: 0x%04x Procedure 0x%02x \n", *connection_handle, *procedure);
}/* end Master_PeerDataPermitExchange_CB() */


/****************** phone alert status server Weak Callbacks definition ***************************/

WEAK_FUNCTION(void PXR_DeviceDiscovery_CB(uint8_t status, uint8_t addr_type, uint8_t *addr, 
                                                   uint8_t data_length, uint8_t *data, 
					           uint8_t RSSI))
{
}

WEAK_FUNCTION(void PXR_ConnectionStatus_CB(uint8_t connection_evt, uint8_t status))
{
}

WEAK_FUNCTION(void PXR_ConnectionParameterUpdateReq_CB(pxrConnUpdateParamType *param))
{
}

WEAK_FUNCTION(void PXR_PinCodeRequired_CB(void))
{
}

WEAK_FUNCTION(void PXR_Pairing_CB(uint16_t conn_handle, uint8_t status))
{
}

#endif /* (BLE_CURRENT_PROFILE_ROLES & PROXIMITY_REPORTER) */
