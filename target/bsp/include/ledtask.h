
#ifndef LEDTASK_H
#define LEDTASK_H

/* Message interface between UI and LED Task */

#define LED_ON 1
#define LED_OFF 2


void led_task(void* params);

#endif /* LEDTASK_H */
