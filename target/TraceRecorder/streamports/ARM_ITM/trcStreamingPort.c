/*******************************************************************************
 * Trace Recorder Library for Tracealyzer v4.2.6
 * Percepio AB, www.percepio.com
 *
 * trcStreamingPort.c
 *
 * Supporting functions for trace streaming, used by the "stream ports" 
 * for reading and writing data to the interface.
 * Existing ports can easily be modified to fit another setup, e.g., a 
 * different TCP/IP stack, or to define your own stream port.
 *
  * Terms of Use
 * This file is part of the trace recorder library (RECORDER), which is the 
 * intellectual property of Percepio AB (PERCEPIO) and provided under a
 * license as follows.
 * The RECORDER may be used free of charge for the purpose of recording data
 * intended for analysis in PERCEPIO products. It may not be used or modified
 * for other purposes without explicit permission from PERCEPIO.
 * You may distribute the RECORDER in its original source code form, assuming
 * this text (terms of use, disclaimer, copyright notice) is unchanged. You are
 * allowed to distribute the RECORDER with minor modifications intended for
 * configuration or porting of the RECORDER, e.g., to allow using it on a 
 * specific processor, processor family or with a specific communication
 * interface. Any such modifications should be documented directly below
 * this comment block.  
 *
 * Disclaimer
 * The RECORDER is being delivered to you AS IS and PERCEPIO makes no warranty
 * as to its use or performance. PERCEPIO does not and cannot warrant the 
 * performance or results you may obtain by using the RECORDER or documentation.
 * PERCEPIO make no warranties, express or implied, as to noninfringement of
 * third party rights, merchantability, or fitness for any particular purpose.
 * In no event will PERCEPIO, its technology partners, or distributors be liable
 * to you for any consequential, incidental or special damages, including any
 * lost profits or lost savings, even if a representative of PERCEPIO has been
 * advised of the possibility of such damages, or for any claim by any third
 * party. Some jurisdictions do not allow the exclusion or limitation of
 * incidental, consequential or special damages, or the exclusion of implied
 * warranties or limitations on how long an implied warranty may last, so the
 * above limitations may not apply to you.
 *
 * Tabs are used for indent in this file (1 tab = 4 spaces)
 *
 * Copyright Percepio AB, 2018.
 * www.percepio.com
 ******************************************************************************/

#include "trcRecorder.h"

#if (TRC_USE_TRACEALYZER_RECORDER == 1)
#if (TRC_CFG_RECORDER_MODE == TRC_RECORDER_MODE_STREAMING)

static void itm_write_32(uint32_t data);

volatile int32_t tz_host_command_bytes_to_read = 0; // This is set by the Tracealyzer host application (to the number of bytes written), after having written to tz_host_commands. Set to zero by the read function after the message in tz_host_commands has been read.
volatile char tz_host_command_data[32];

/* This reads "command" data from a RAM buffer, written by a host macro in the debugger */
int32_t read_from_host(void* ptrData, uint32_t size, int32_t* ptrBytesRead)
{
	if ( tz_host_command_bytes_to_read > 0)
	{		
		int i;
		uint8_t * bytesBuffer = (uint8_t*) ptrData;

		if (ptrBytesRead != NULL)
			*ptrBytesRead = (int32_t)tz_host_command_bytes_to_read;
	
		if (tz_host_command_bytes_to_read != size)
		{
			return -1;
		}
			
		for (i=0; i < tz_host_command_bytes_to_read; i++)
		{
			bytesBuffer[i] = tz_host_command_data[i];
		}
		
		tz_host_command_bytes_to_read = 0;
	}

	return 0;
}

static void itm_write_32(uint32_t data)
{	
     if   ((CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk)  &&      // Trace enabled
           (ITM->TCR & ITM_TCR_ITMENA_Msk)                  &&      // ITM enabled
           (ITM->TER & (1UL << TRC_CFG_ITM_PORT)))                  // ITM port enabled
    {
        while (ITM->PORT[TRC_CFG_ITM_PORT].u32 == 0);     // Block until room in ITM FIFO - This stream port is always in "blocking mode", since intended for high-speed ITM!
        ITM->PORT[TRC_CFG_ITM_PORT].u32 = data;           // Write the data
	}	
}

/* This is assumed to execute from within the recorder, with interrupts disabled */
int32_t itm_write(void* ptrData, uint32_t size, int32_t* ptrBytesWritten)
{
	uint32_t bytesWritten = 0;
	uint32_t* ptr32 = (uint32_t*)ptrData;
	
	if (size % 4 != 0) return -2;
		
	while(bytesWritten < size)
	{
		itm_write_32(*ptr32);
		ptr32++;
		bytesWritten += 4;
	}

	*ptrBytesWritten = bytesWritten;
	
	return 0;
}

#endif
#endif
