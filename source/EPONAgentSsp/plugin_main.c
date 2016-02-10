/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2015 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

/*********************************************************************** 
  
    module: plugin_main.c

        Implement COSA Data Model Library Init and Unload apis.
 
    ---------------------------------------------------------------

    copyright:

        Cisco Systems, Inc.
        All Rights Reserved.

    ---------------------------------------------------------------

    author:

        COSA XML TOOL CODE GENERATOR 1.0

    ---------------------------------------------------------------

    revision:

        09/28/2011    initial revision.

**********************************************************************/

#include "ansc_platform.h"
#include "ansc_load_library.h"
#include "cosa_plugin_api.h"
#include "plugin_main.h"
#include "cosa_apis_epon_plugin.h"

#define THIS_PLUGIN_VERSION                         1

int ANSC_EXPORT_API
COSA_Init
    (
        ULONG                       uMaxVersionSupported, 
        void*                       hCosaPlugInfo         /* PCOSA_PLUGIN_INFO passed in by the caller */
    )
{
    PCOSA_PLUGIN_INFO               pPlugInfo  = (PCOSA_PLUGIN_INFO)hCosaPlugInfo;

    if ( uMaxVersionSupported < THIS_PLUGIN_VERSION )
    {
      /* this version is not supported */
        return -1;
    }   
    
    pPlugInfo->uPluginVersion       = THIS_PLUGIN_VERSION;
    /* register the back-end apis for the data model */
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_GetParamBoolValue",  DPoE_GetParamBoolValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_GetParamUlongValue", DPoE_GetParamUlongValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_GetParamIntValue",   DPoE_GetParamIntValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_GetParamStringValue", DPoE_GetParamStringValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_SetParamBoolValue",  DPoE_SetParamBoolValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_SetParamUlongValue", DPoE_SetParamUlongValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_SetParamIntValue",  DPoE_SetParamIntValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_SetParamStringValue", DPoE_SetParamStringValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_FirmwareInfo_GetParamStringValue", DPoE_FirmwareInfo_GetParamStringValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_FirmwareInfo_GetParamUlongValue", DPoE_FirmwareInfo_GetParamUlongValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_ChipInfo_GetParamStringValue", DPoE_ChipInfo_GetParamStringValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_ChipInfo_GetParamUlongValue", DPoE_ChipInfo_GetParamUlongValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_ManufacturerInfo_GetParamStringValue", DPoE_ManufacturerInfo_GetParamStringValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_DeviceSysDescrInfo_GetParamStringValue", DPoE_DeviceSysDescrInfo_GetParamStringValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_OnuPacketBufferCapabilities_GetParamUlongValue", DPoE_OnuPacketBufferCapabilities_GetParamUlongValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_LlidForwardingState_GetEntryCount", DPoE_LlidForwardingState_GetEntryCount);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_LlidForwardingState_GetEntry", DPoE_LlidForwardingState_GetEntry);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_LlidForwardingState_GetParamBoolValue", DPoE_LlidForwardingState_GetParamBoolValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_LlidForwardingState_GetParamIntValue", DPoE_LlidForwardingState_GetParamIntValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_OamFrameRate_GetEntryCount", DPoE_OamFrameRate_GetEntryCount);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_OamFrameRate_GetEntry", DPoE_OamFrameRate_GetEntry);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_OamFrameRate_GetParamIntValue", DPoE_OamFrameRate_GetParamIntValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_DynamicMacTable_GetEntryCount", DPoE_DynamicMacTable_GetEntryCount);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_DynamicMacTable_GetEntry", DPoE_DynamicMacTable_GetEntry);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_DynamicMacTable_GetParamStringValue", DPoE_DynamicMacTable_GetParamStringValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_DynamicMacTable_GetParamIntValue", DPoE_DynamicMacTable_GetParamIntValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_StaticMacTable_GetEntryCount", DPoE_StaticMacTable_GetEntryCount);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_StaticMacTable_GetEntry", DPoE_StaticMacTable_GetEntry);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_StaticMacTable_GetParamUlongValue", DPoE_StaticMacTable_GetParamUlongValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_StaticMacTable_GetParamStringValue", DPoE_StaticMacTable_GetParamStringValue);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_OnuLinkStatistics_GetEntryCount", DPoE_OnuLinkStatistics_GetEntryCount);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_OnuLinkStatistics_GetEntry", DPoE_OnuLinkStatistics_GetEntry);
    pPlugInfo->RegisterFunction(pPlugInfo->hContext, "DPoE_OnuLinkStatistics_GetParamUlongValue", DPoE_OnuLinkStatistics_GetParamUlongValue);
    return  0;
}

BOOL ANSC_EXPORT_API
COSA_IsObjectSupported
    (
        char*                        pObjName
    )
{
    
    return TRUE;
}

void ANSC_EXPORT_API
COSA_Unload
    (
        void
    )
{
    /* unload the memory here */
}
