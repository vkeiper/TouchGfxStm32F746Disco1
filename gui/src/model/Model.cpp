/******************************************************************************
 *
 * @brief     This file is part of the TouchGFX 4.8.0 evaluation distribution.
 *
 * @author    Draupner Graphics A/S <http://www.touchgfx.com>
 *
 ******************************************************************************
 *
 * @section Copyright
 *
 * This file is free software and is provided for example purposes. You may
 * use, copy, and modify within the terms and conditions of the license
 * agreement.
 *
 * This is licensed software for evaluation use, any use must strictly comply
 * with the evaluation license agreement provided with delivery of the
 * TouchGFX software.
 *
 * The evaluation license agreement can be seen on www.touchgfx.com
 *
 * @section Disclaimer
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Draupner Graphics A/S has
 * no obligation to support this software. Draupner Graphics A/S is providing
 * the software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Draupner Graphics A/S can not be held liable for any consequential,
 * incidental, or special damages, or any other relief, or for any claim by
 * any third party, arising from your use of this software.
 *
 *****************************************************************************/
#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdlib.h>
#ifndef SIMULATOR
  #include "stm32746g_discovery.h"
	#include "FreeRTOS.h"
	#include "queue.h"
	#include "task.h"

	//*******************************************************
	//   Define Queue handles
	//*******************************************************
	extern "C" xQueueHandle led_msg_q; //From LEDTask
	extern "C" xQueueHandle btn_msg_q; //From BtnTask
	
	xQueueHandle gui_msg_q;
#endif

Model::Model()
    : modelListener(0)
		, roomLightState(false)
		, roomTemperature(18)
{
    //updateRoomLight();
		#ifndef SIMULATOR
			//*******************************************************
			// 
			//  Create GUI message queue
			//
			//  Check for messages from backend, with zero timeout
			//  Any time there's a message on this mailbox, react to it. value is meaningless in this case..
			//	
			//*******************************************************
			//
			gui_msg_q = xQueueGenericCreate(1, 1, 0);
	#endif
}

void Model::tick()
{
#ifndef SIMULATOR
    //poll blue push button
    static uint32_t old = 0;
		
//    uint32_t state = BSP_PB_GetState(BUTTON_KEY);
//    if (state != old)
//    {
//        old = state;
//        if (state == 0) //released
//        {
//            roomTemperature++;
//            if (roomTemperature>85) roomTemperature = 85;
//            modelListener->guiDataChanged();
//        }
//    }
		
	//*******************************************************
	// 
	//  HANDLE MESSAGES
	//
	//  Check for messages from backend, with zero timeout to 
	//  avoid blocking the UI. 
	// 
	//*******************************************************
	//
	
	uint8_t msg = 0;
	if (xQueueReceive(gui_msg_q, &msg, 0) == pdTRUE)
  {
  	// Queue is used as a flag, so don't check msg.
    // Full = PRESSED, Empty = Do nothing.
		 roomLightState = !roomLightState;
     updateRoomLight();

		roomTemperature++;
    if (roomTemperature>85) roomTemperature = 85;
            modelListener->guiDataChanged();

  }

#else
		ticks=ticks;
#endif
}

void Model::userSetRoomLight(bool state)
{
    roomLightState = state;
    updateRoomLight();
}

void Model::userSetTemperature(uint32_t temp)
{
    roomTemperature = temp;
}
// Generates and prints 'count' random 
// numbers in range [lower, upper]. 
uint32_t Model::getRandomTemp(int lower, int upper) 
{ 
#ifndef SIMULATOR
		srand((int)HAL_GetTick());
#else
		srand(ticks);
#endif
    int num = (rand() % (upper - lower + 1)) + lower; 
        
		return (uint32_t)num; 
     
} 

uint32_t Model::getReadRoomTemperature()
{
	readRoomTemperature = getRandomTemp(55,67);
	return readRoomTemperature;	
}

void Model::updateRoomLight()
{
#ifndef SIMULATOR
		static bool last;
	  static int cnt=0; 
		//set LED only on change
	  if(last != roomLightState)
		{
				cnt++;
				last = roomLightState;
				uint8_t msg = 2;//LED_OFF;
				if (roomLightState)
				{
						msg = 1;//LED_ON;
				}
				else
				{
						msg = 2;//LED_OFF;
				}    

				if (led_msg_q)
				{
						xQueueSend(led_msg_q, &msg, 0);
				}
		}else{
				cnt=0;
		}
#endif
}
