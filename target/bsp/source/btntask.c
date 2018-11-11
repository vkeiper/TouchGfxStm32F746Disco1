#include "../include/btntask.h"
#include "stm32746g_discovery.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

//*******************************************************
//   Define Queue handles
//*******************************************************
xQueueHandle btn_msg_q = 0;

//gui message queue
extern xQueueHandle gui_msg_q;
uint32_t last_btn_state = 0;

void btn_task(void* params)
{  
	uint32_t btn_state = 0;
  uint8_t msg = 0;
	
  //*******************************************************
	//  GPIO MODE: Init BUTTON_USER
	//*******************************************************
	//
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
	    
	//*******************************************************
	//  Create queue of length 1
	//*******************************************************
	//
  btn_msg_q = xQueueGenericCreate(1, 1, 0);

	//*******************************************************
	//  Event loop
	//*******************************************************
	//
  for(;;)
  {
		vTaskDelay(50);
		
		//*******************************************************
		//  Read state of button and only send message if pressed
		//*******************************************************
		//
		btn_state = BSP_PB_GetState(BUTTON_KEY);   
		if(btn_state == 1)
		{
			// Send empty message. Queue item implicitly means PRESSED.
			xQueueSend(gui_msg_q, &msg, 0);
		}
	}
}
