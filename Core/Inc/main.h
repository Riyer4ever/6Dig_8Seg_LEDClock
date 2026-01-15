/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define dig1_Pin GPIO_PIN_6
#define dig1_GPIO_Port GPIOF
#define dig2_Pin GPIO_PIN_7
#define dig2_GPIO_Port GPIOF
#define dig3_Pin GPIO_PIN_8
#define dig3_GPIO_Port GPIOF
#define aSeg_Pin GPIO_PIN_0
#define aSeg_GPIO_Port GPIOC
#define bSeg_Pin GPIO_PIN_1
#define bSeg_GPIO_Port GPIOC
#define cSeg_Pin GPIO_PIN_2
#define cSeg_GPIO_Port GPIOC
#define dSeg_Pin GPIO_PIN_3
#define dSeg_GPIO_Port GPIOC
#define eSeg_Pin GPIO_PIN_4
#define eSeg_GPIO_Port GPIOC
#define fSeg_Pin GPIO_PIN_5
#define fSeg_GPIO_Port GPIOC
#define key1_Pin GPIO_PIN_0
#define key1_GPIO_Port GPIOG
#define key2_Pin GPIO_PIN_1
#define key2_GPIO_Port GPIOG
#define key3_Pin GPIO_PIN_2
#define key3_GPIO_Port GPIOG
#define key4_Pin GPIO_PIN_3
#define key4_GPIO_Port GPIOG
#define gSeg_Pin GPIO_PIN_6
#define gSeg_GPIO_Port GPIOC
#define dpSeg_Pin GPIO_PIN_7
#define dpSeg_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
