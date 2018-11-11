/**
  ******************************************************************************
  * @file    stm32746g_discovery.h
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    22-April-2016
  * @brief   This file contains definitions for STM32746G_DISCOVERY's LEDs,
  *          push-buttons and COM ports hardware resources.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32746G_DISCOVERY_H
#define __STM32746G_DISCOVERY_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
   
/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32746G_DISCOVERY
  * @{
  */
      
/** @addtogroup STM32746G_DISCOVERY_LOW_LEVEL
  * @{
  */ 

/** @defgroup STM32746G_DISCOVERY_LOW_LEVEL_Exported_Types STM32746G_DISCOVERY_LOW_LEVEL Exported Types
  * @{
  */
typedef enum 
{
LED1 = 0,
LED_GREEN = LED1,
}Led_TypeDef;

typedef enum 
{  
  BUTTON_WAKEUP = 0,
  BUTTON_TAMPER = 1,
  BUTTON_KEY = 2
}Button_TypeDef;

typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
}ButtonMode_TypeDef;

typedef enum 
{
  COM1 = 0,
  COM2 = 1
}COM_TypeDef;


typedef enum 
{
	ARDCN7_NONE = 0,
	ARDCN7_01,
	ARDCN7_02,
	ARDCN7_03,
	ARDCN7_04,
	ARDCN7_05,
	ARDCN7_06,
	ARDCN7_07 = 0,
	ARDCN7_08 = 0,
	ARDCN7_09,
	ARDCN7_10
}ArdCn7Dig_TypeDef;

typedef enum 
{
	ARDCN4_NONE = 0,
	ARDCN4_01,
	ARDCN4_02,
	ARDCN4_03,
	ARDCN4_04,
	ARDCN4_05,
	ARDCN4_06,
	ARDCN4_07,
	ARDCN4_08
}ArdCn4Dig_TypeDef;

typedef enum 
{
	ARDCN5_NONE = 0,
	ARDCN5_01,
	ARDCN5_02,
	ARDCN5_03,
	ARDCN5_04,
	ARDCN5_05,
	ARDCN5_06
}ArdAn_TypeDef;


typedef struct{
 GPIO_TypeDef *GpioType[10];
 ArdCn7Dig_TypeDef ARDENUM;	
}ArduinoCn7_Typedef;


typedef struct{
 GPIO_TypeDef GpioType[8];
 ArdCn7Dig_TypeDef ARDENUM;	
}ArduinoCn4_Typedef;

/**
  * @}
  */ 

/** @defgroup STM32746G_DISCOVERY_LOW_LEVEL_Exported_Constants STM32746G_DISCOVERY_LOW_LEVEL Exported Constants
  * @{
  */ 

/** 
  * @brief  Define for STM32746G_DISCOVERY board
  */ 
#if !defined (USE_STM32746G_DISCO)
 #define USE_STM32746G_DISCO
#endif

/** @addtogroup STM32746G_DISCOVERY_LOW_LEVEL_LED
  * @{
  */

#define LEDn                             ((uint8_t)1)

#define LED1_GPIO_PORT                   GPIOI
#define LED1_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOI_CLK_ENABLE()
#define LED1_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOI_CLK_DISABLE()
#define LED1_PIN                         GPIO_PIN_1

#define ARDCN4n                          ((uint8_t)8)
#define ARD_CN4_01_GPIO_PORT                  GPIOC
#define ARD_CN4_01_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOC_CLK_ENABLE()
#define ARD_CN4_01_GPIO_CLK_DISABLE()         __HAL_RCC_GPIOC_CLK_DISABLE()
#define ARD_CN4_01_PIN                        GPIO_PIN_7

#define ARD_CN4_02_GPIO_PORT                  GPIOC
#define ARD_CN4_02_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOC_CLK_ENABLE()
#define ARD_CN4_02_GPIO_CLK_DISABLE()         __HAL_RCC_GPIOC_CLK_DISABLE()
#define ARD_CN4_02_PIN                        GPIO_PIN_6

#define ARD_CN4_03_GPIO_PORT                  GPIOG
#define ARD_CN4_03_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOG_CLK_ENABLE()
#define ARD_CN4_03_GPIO_CLK_DISABLE()         __HAL_RCC_GPIOG_CLK_DISABLE()
#define ARD_CN4_03_PIN                        GPIO_PIN_6

#define ARD_CN4_04_GPIO_PORT                  GPIOB
#define ARD_CN4_04_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOB_CLK_ENABLE()
#define ARD_CN4_04_GPIO_CLK_DISABLE()         __HAL_RCC_GPIOB_CLK_DISABLE()
#define ARD_CN4_04_PIN                        GPIO_PIN_4

#define ARD_CN4_05_GPIO_PORT            GPIOG
#define ARD_CN4_05_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOG_CLK_ENABLE()
#define ARD_CN4_05_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOG_CLK_DISABLE()
#define ARD_CN4_05_PIN                  GPIO_PIN_7

#define ARD_CN4_06_GPIO_PORT            GPIOI
#define ARD_CN4_06_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOI_CLK_ENABLE()
#define ARD_CN4_06_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOI_CLK_DISABLE()
#define ARD_CN4_06_PIN                  GPIO_PIN_0

#define ARD_CN4_07_GPIO_PORT            GPIOH
#define ARD_CN4_07_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOH_CLK_ENABLE()
#define ARD_CN4_07_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOH_CLK_DISABLE()
#define ARD_CN4_07_PIN                  GPIO_PIN_6

#define ARD_CN4_08_GPIO_PORT            GPIOI
#define ARD_CN4_08_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOI_CLK_ENABLE()
#define ARD_CN4_08_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOI_CLK_DISABLE()
#define ARD_CN4_08_PIN                  GPIO_PIN_3


#define ARDCN7n                          ((uint8_t)10)
// use for CAN1 
#define ARD_CN7_10_GPIO_PORT             GPIOB
#define ARD_CN7_10_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()
#define ARD_CN7_10_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOB_CLK_DISABLE()
#define ARD_CN7_10_PIN                   GPIO_PIN_8

// use for CAN1 
#define ARD_CN7_09_GPIO_PORT             GPIOB
#define ARD_CN7_09_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()
#define ARD_CN7_09_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOB_CLK_DISABLE()
#define ARD_CN7_09_PIN                   GPIO_PIN_9

#define ARD_CN7_08_PIN                   (NULL)
#define ARD_CN7_07_PIN                   (NULL)


#define ARD_CN7_06_GPIO_PORT            GPIOI
#define ARD_CN7_06_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOI_CLK_ENABLE()
#define ARD_CN7_06_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOI_CLK_DISABLE()
#define ARD_CN7_06_PIN                  GPIO_PIN_1

#define ARD_CN7_05_GPIO_PORT             GPIOB
#define ARD_CN7_05_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()
#define ARD_CN7_05_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOB_CLK_DISABLE()
#define ARD_CN7_05_PIN                   GPIO_PIN_14

#define ARD_CN7_04_GPIO_PORT             GPIOB
#define ARD_CN7_04_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()
#define ARD_CN7_04_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOB_CLK_DISABLE()
#define ARD_CN7_04_PIN                   GPIO_PIN_15

#define ARD_CN7_03_GPIO_PORT             GPIOA
#define ARD_CN7_03_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define ARD_CN7_03_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOA_CLK_DISABLE()
#define ARD_CN7_03_PIN                   GPIO_PIN_8

#define ARD_CN7_02_GPIO_PORT            GPIOA
#define ARD_CN7_02_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()
#define ARD_CN7_02_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOA_CLK_DISABLE()
#define ARD_CN7_02_PIN                  GPIO_PIN_15

#define ARD_CN7_01_GPIO_PORT            GPIOI
#define ARD_CN7_01_GPIO_CLK_ENABLE()    __HAL_RCC_GPIOI_CLK_ENABLE()
#define ARD_CN7_01_GPIO_CLK_DISABLE()   __HAL_RCC_GPIOI_CLK_DISABLE()
#define ARD_CN7_01_PIN                  GPIO_PIN_2

//ARDUINO Analog header Pins
#define ARDCN5n                          ((uint8_t)6)
 
#define ARD_CN5_06_GPIO_PORT             GPIOF //ADC3_IN4
#define ARD_CN5_06_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOF_CLK_ENABLE()
#define ARD_CN5_06_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOF_CLK_DISABLE()
#define ARD_CN5_06_PIN                   GPIO_PIN_6

#define ARD_CN5_05_GPIO_PORT             GPIOF //ADC3_IN5
#define ARD_CN5_05_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOF_CLK_ENABLE()
#define ARD_CN5_05_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOF_CLK_DISABLE()
#define ARD_CN5_05_PIN                   GPIO_PIN_7

#define ARD_CN5_04_GPIO_PORT             GPIOF //ADC3_IN6
#define ARD_CN5_04_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOF_CLK_ENABLE()
#define ARD_CN5_04_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOF_CLK_DISABLE()
#define ARD_CN5_04_PIN                   GPIO_PIN_8

#define ARD_CN5_03_GPIO_PORT             GPIOF //ADC3_IN7
#define ARD_CN5_03_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOF_CLK_ENABLE()
#define ARD_CN5_03_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOF_CLK_DISABLE()
#define ARD_CN5_03_PIN                   GPIO_PIN_9

#define ARD_CN5_02_GPIO_PORT             GPIOF //ADC3_IN8
#define ARD_CN5_02_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOF_CLK_ENABLE()
#define ARD_CN5_02_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOF_CLK_DISABLE()
#define ARD_CN5_02_PIN                   GPIO_PIN_10

#define ARD_CN5_01_GPIO_PORT             GPIOA //ADC3_IN0
#define ARD_CN5_01_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define ARD_CN5_01_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOA_CLK_DISABLE()
#define ARD_CN5_01_PIN                   GPIO_PIN_0


/**
  * @}
  */

/** @addtogroup STM32746G_DISCOVERY_LOW_LEVEL_BUTTON
  * @{
  */ 
#define BUTTONn                             ((uint8_t)3) 

/**
  * @brief Wakeup push-button
  */
#define WAKEUP_BUTTON_PIN                   GPIO_PIN_11
#define WAKEUP_BUTTON_GPIO_PORT             GPIOI
#define WAKEUP_BUTTON_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOI_CLK_ENABLE()
#define WAKEUP_BUTTON_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOI_CLK_DISABLE()
#define WAKEUP_BUTTON_EXTI_IRQn             EXTI15_10_IRQn 

/**
  * @brief Tamper push-button
  */
#define TAMPER_BUTTON_PIN                    GPIO_PIN_11
#define TAMPER_BUTTON_GPIO_PORT              GPIOI
#define TAMPER_BUTTON_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOI_CLK_ENABLE()
#define TAMPER_BUTTON_GPIO_CLK_DISABLE()     __HAL_RCC_GPIOI_CLK_DISABLE()
#define TAMPER_BUTTON_EXTI_IRQn              EXTI15_10_IRQn

/**
  * @brief Key push-button
  */
#define KEY_BUTTON_PIN                       GPIO_PIN_11
#define KEY_BUTTON_GPIO_PORT                 GPIOI
#define KEY_BUTTON_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOI_CLK_ENABLE()
#define KEY_BUTTON_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOI_CLK_DISABLE()
#define KEY_BUTTON_EXTI_IRQn                 EXTI15_10_IRQn

#define BUTTONx_GPIO_CLK_ENABLE(__INDEX__)    do { if((__INDEX__) == 0) WAKEUP_BUTTON_GPIO_CLK_ENABLE(); else\
                                                   if((__INDEX__) == 1) TAMPER_BUTTON_GPIO_CLK_ENABLE(); else\
												                        KEY_BUTTON_GPIO_CLK_ENABLE(); } while(0)											   

#define BUTTONx_GPIO_CLK_DISABLE(__INDEX__)    (((__INDEX__) == 0) ? WAKEUP_BUTTON_GPIO_CLK_DISABLE() :\
                                                ((__INDEX__) == 1) ? TAMPER_BUTTON_GPIO_CLK_DISABLE() : KEY_BUTTON_GPIO_CLK_DISABLE())

/**
  * @}
  */

/** @addtogroup STM32746G_DISCOVERY_LOW_LEVEL_SIGNAL
  * @{
  */
#define SIGNALn                             ((uint8_t)1)

/**
  * @brief SD-detect signal
  */
#define SD_DETECT_PIN                        GPIO_PIN_13
#define SD_DETECT_GPIO_PORT                  GPIOC
#define SD_DETECT_GPIO_CLK_ENABLE()          __HAL_RCC_GPIOC_CLK_ENABLE()
#define SD_DETECT_GPIO_CLK_DISABLE()         __HAL_RCC_GPIOC_CLK_DISABLE()
#define SD_DETECT_EXTI_IRQn                  EXTI15_10_IRQn

/**
  * @brief Touch screen interrupt signal
  */
#define TS_INT_PIN                           GPIO_PIN_13
#define TS_INT_GPIO_PORT                     GPIOI
#define TS_INT_GPIO_CLK_ENABLE()             __HAL_RCC_GPIOI_CLK_ENABLE()
#define TS_INT_GPIO_CLK_DISABLE()            __HAL_RCC_GPIOI_CLK_DISABLE()
#define TS_INT_EXTI_IRQn                     EXTI15_10_IRQn

/**
  * @}
  */ 

/** @addtogroup STM32746G_DISCOVERY_LOW_LEVEL_COM
  * @{
  */
#define COMn                             ((uint8_t)1)

/**
 * @brief Definition for COM port1, connected to USART1
 */ 
#define DISCOVERY_COM1                          USART1
#define DISCOVERY_COM1_CLK_ENABLE()             __HAL_RCC_USART1_CLK_ENABLE()
#define DISCOVERY_COM1_CLK_DISABLE()            __HAL_RCC_USART1_CLK_DISABLE()

#define DISCOVERY_COM1_TX_PIN                   GPIO_PIN_9
#define DISCOVERY_COM1_TX_GPIO_PORT             GPIOA
#define DISCOVERY_COM1_TX_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE()
#define DISCOVERY_COM1_TX_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOA_CLK_DISABLE()
#define DISCOVERY_COM1_TX_AF                    GPIO_AF7_USART1

#define DISCOVERY_COM1_RX_PIN                   GPIO_PIN_7
#define DISCOVERY_COM1_RX_GPIO_PORT             GPIOB
#define DISCOVERY_COM1_RX_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()
#define DISCOVERY_COM1_RX_GPIO_CLK_DISABLE()    __HAL_RCC_GPIOB_CLK_DISABLE()
#define DISCOVERY_COM1_RX_AF                    GPIO_AF7_USART1

#define DISCOVERY_COM1_IRQn                     USART1_IRQn

#define DISCOVERY_COMx_CLK_ENABLE(__INDEX__)            do { if((__INDEX__) == COM1) DISCOVERY_COM1_CLK_ENABLE(); } while(0)
#define DISCOVERY_COMx_CLK_DISABLE(__INDEX__)           (((__INDEX__) == 0) ? DISCOVERY_COM1_CLK_DISABLE() : 0)

#define DISCOVERY_COMx_TX_GPIO_CLK_ENABLE(__INDEX__)    do { if((__INDEX__) == COM1) DISCOVERY_COM1_TX_GPIO_CLK_ENABLE(); } while(0)
#define DISCOVERY_COMx_TX_GPIO_CLK_DISABLE(__INDEX__)   (((__INDEX__) == 0) ? DISCOVERY_COM1_TX_GPIO_CLK_DISABLE() : 0)

#define DISCOVERY_COMx_RX_GPIO_CLK_ENABLE(__INDEX__)    do { if((__INDEX__) == COM1) DISCOVERY_COM1_RX_GPIO_CLK_ENABLE(); } while(0)
#define DISCOVERY_COMx_RX_GPIO_CLK_DISABLE(__INDEX__)   (((__INDEX__) == 0) ? DISCOVERY_COM1_RX_GPIO_CLK_DISABLE() : 0)

/* Exported constant IO ------------------------------------------------------*/

#define LCD_I2C_ADDRESS                  ((uint16_t)0x70)
#define CAMERA_I2C_ADDRESS               ((uint16_t)0x60)
#define AUDIO_I2C_ADDRESS                ((uint16_t)0x34)
#define EEPROM_I2C_ADDRESS_A01           ((uint16_t)0xA0)
#define EEPROM_I2C_ADDRESS_A02           ((uint16_t)0xA6)
#define TS_I2C_ADDRESS                   ((uint16_t)0x70)

/* I2C clock speed configuration (in Hz) 
   WARNING: 
   Make sure that this define is not already declared in other files (ie. 
   stm32746g_discovery.h file). It can be used in parallel by other modules. */
#ifndef I2C_SPEED
 #define I2C_SPEED                       ((uint32_t)100000)
#endif /* I2C_SPEED */

/* User can use this section to tailor I2Cx/I2Cx instance used and associated 
   resources */
/* Definition for AUDIO and LCD I2Cx resources */
#define DISCOVERY_AUDIO_I2Cx                             I2C3
#define DISCOVERY_AUDIO_I2Cx_CLK_ENABLE()                __HAL_RCC_I2C3_CLK_ENABLE()
#define DISCOVERY_AUDIO_DMAx_CLK_ENABLE()                __HAL_RCC_DMA1_CLK_ENABLE()
#define DISCOVERY_AUDIO_I2Cx_SCL_SDA_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOH_CLK_ENABLE()

#define DISCOVERY_AUDIO_I2Cx_FORCE_RESET()               __HAL_RCC_I2C3_FORCE_RESET()
#define DISCOVERY_AUDIO_I2Cx_RELEASE_RESET()             __HAL_RCC_I2C3_RELEASE_RESET()

/* Definition for I2Cx Pins */
#define DISCOVERY_AUDIO_I2Cx_SCL_PIN                     GPIO_PIN_7
#define DISCOVERY_AUDIO_I2Cx_SCL_SDA_GPIO_PORT           GPIOH
#define DISCOVERY_AUDIO_I2Cx_SCL_SDA_AF                  GPIO_AF4_I2C3
#define DISCOVERY_AUDIO_I2Cx_SDA_PIN                     GPIO_PIN_8

/* I2C interrupt requests */
#define DISCOVERY_AUDIO_I2Cx_EV_IRQn                     I2C3_EV_IRQn
#define DISCOVERY_AUDIO_I2Cx_ER_IRQn                     I2C3_ER_IRQn

/* Definition for external, camera and Arduino connector I2Cx resources */
#define DISCOVERY_EXT_I2Cx                               I2C1
#define DISCOVERY_EXT_I2Cx_CLK_ENABLE()                  __HAL_RCC_I2C1_CLK_ENABLE()
#define DISCOVERY_EXT_DMAx_CLK_ENABLE()                  __HAL_RCC_DMA1_CLK_ENABLE()
#define DISCOVERY_EXT_I2Cx_SCL_SDA_GPIO_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE()

#define DISCOVERY_EXT_I2Cx_FORCE_RESET()                 __HAL_RCC_I2C1_FORCE_RESET()
#define DISCOVERY_EXT_I2Cx_RELEASE_RESET()               __HAL_RCC_I2C1_RELEASE_RESET()

/* Definition for I2Cx Pins */
#define DISCOVERY_EXT_I2Cx_SCL_PIN                       GPIO_PIN_8
#define DISCOVERY_EXT_I2Cx_SCL_SDA_GPIO_PORT             GPIOB
#define DISCOVERY_EXT_I2Cx_SCL_SDA_AF                    GPIO_AF4_I2C1
#define DISCOVERY_EXT_I2Cx_SDA_PIN                       GPIO_PIN_9

/* I2C interrupt requests */
#define DISCOVERY_EXT_I2Cx_EV_IRQn                       I2C1_EV_IRQn
#define DISCOVERY_EXT_I2Cx_ER_IRQn                       I2C1_ER_IRQn

/* I2C TIMING Register define when I2C clock source is SYSCLK */
/* I2C TIMING is calculated from APB1 source clock = 50 MHz */
/* Due to the big MOFSET capacity for adapting the camera level the rising time is very large (>1us) */
/* 0x40912732 takes in account the big rising and aims a clock of 100khz */
/* this value might be adapted when next Rev Birdie board is available */
#ifndef DISCOVERY_I2Cx_TIMING  
#define DISCOVERY_I2Cx_TIMING                      ((uint32_t)0x40912732)  
#endif /* DISCOVERY_I2Cx_TIMING */

/**
  * @}
  */ 

/**
  * @}
  */ 
  
/** @defgroup STM32746G_DISCOVERY_LOW_LEVEL_Exported_Macros STM32746G_DISCOVERY_LOW_LEVEL Exported Macros
  * @{
  */  
/**
  * @}
  */ 

/** @addtogroup STM32746G_DISCOVERY_LOW_LEVEL_Exported_Functions
  * @{
  */
uint32_t  BSP_GetVersion(void);
void      BSP_LED_Init(Led_TypeDef Led);
void      BSP_LED_DeInit(Led_TypeDef Led);
void      BSP_LED_On(Led_TypeDef Led);
void      BSP_LED_Off(Led_TypeDef Led);
void      BSP_LED_Toggle(Led_TypeDef Led);
void      BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef ButtonMode);
void      BSP_PB_DeInit(Button_TypeDef Button);
uint32_t  BSP_PB_GetState(Button_TypeDef Button);
void      BSP_COM_Init(COM_TypeDef COM, UART_HandleTypeDef *husart);
void      BSP_COM_DeInit(COM_TypeDef COM, UART_HandleTypeDef *huart);

/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32746G_DISCOVERY_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
