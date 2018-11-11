#include "../include/ledtask.h"
#include "stm32746g_discovery.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

//*******************************************************
//   Define Queue handles
//*******************************************************
xQueueHandle led_msg_q = 0;
extern xQueueHandle gui_msg_q;

void led_task(void* params)
{
	uint8_t msg = 0;
	Led_TypeDef led_type = LED_GREEN;
	
	//*******************************************************
	// Init LED
	//*******************************************************
	//
	BSP_LED_Init(led_type);
    
  //*******************************************************
	//  Create queue of length 1
	//*******************************************************
	//
  led_msg_q = xQueueGenericCreate(1, 1, 0);

  //*******************************************************
	//  Event loop
  //
	//  Every 200ms, take an item off the queue and 
	//  toggle LED according to contents of msg
	//*******************************************************
	//	
  for(;;)
  {
		vTaskDelay(200);
		if (xQueueReceive(led_msg_q, &msg, 0) == pdTRUE)
		{
			switch(msg)
			{
				case LED_ON:
					BSP_LED_On(led_type);
					break;
				case LED_OFF:
					BSP_LED_Off(led_type);
					break;
				default:
					break;
			}
		}			
	}
}
