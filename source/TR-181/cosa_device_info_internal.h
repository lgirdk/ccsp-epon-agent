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

/**********************************************************************
   Copyright [2014] [Cisco Systems, Inc.]
 
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at
 
       http://www.apache.org/licenses/LICENSE-2.0
 
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
**********************************************************************/

/**************************************************************************

    module: cosa_device_info_internal.h

        For COSA Data Model Library Development

    -------------------------------------------------------------------

    description:

        This file defines the apis for objects to support Data Model Library.

    -------------------------------------------------------------------


    author:

        COSA XML TOOL CODE GENERATOR 1.0

    -------------------------------------------------------------------

    revision:

        01/14/2011    initial revision.

**************************************************************************/

#ifndef  _COSA_DI_INTERNAL_H
#define  _COSA_DI_INTERNAL_H

#include "cosa_apis.h"
#include "plugin_main_apis.h"
#include "cosa_device_info_apis.h"

#define  COSA_DATAMODEL_DEVICEINFO_CLASS_CONTENT		\
	COSA_BASE_CONTENT                                                       \
	BOOLEAN		Download_Control_Flag;					\
	char		Current_Firmware[128];					\
	char		Firmware_To_Download[128];				\
	char		DownloadURL[128];						\

typedef  struct
_COSA_DATAMODEL_DEVICEINFO_CLASS_CONTENT
{
    COSA_DATAMODEL_DEVICEINFO_CLASS_CONTENT
}
COSA_DATAMODEL_DEVICEINFO, *PCOSA_DATAMODEL_DEVICEINFO;

/*
    Standard function declaration
*/
ANSC_HANDLE
CosaDeviceInfoCreate
    (
        VOID
    );

ANSC_STATUS
CosaDeviceInfoInitialize
    (
        ANSC_HANDLE                 hThisObject
    );

ANSC_STATUS
CosaDeviceInfoRemove
    (
        ANSC_HANDLE                 hThisObject
    );

#endif

