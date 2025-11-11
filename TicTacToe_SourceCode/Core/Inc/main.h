/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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
#define BUTTON_SELECT_Pin GPIO_PIN_1
#define BUTTON_SELECT_GPIO_Port GPIOA
#define BUTTON_SWITCH_Pin GPIO_PIN_2
#define BUTTON_SWITCH_GPIO_Port GPIOA
#define BUTTON_LEFT_Pin GPIO_PIN_3
#define BUTTON_LEFT_GPIO_Port GPIOA
#define BUTTON_UP_Pin GPIO_PIN_4
#define BUTTON_UP_GPIO_Port GPIOA
#define BUTTON_DOWN_Pin GPIO_PIN_5
#define BUTTON_DOWN_GPIO_Port GPIOA
#define BUTTON_RIGHT_Pin GPIO_PIN_6
#define BUTTON_RIGHT_GPIO_Port GPIOA
#define SEG_A_Pin GPIO_PIN_7
#define SEG_A_GPIO_Port GPIOA
#define SEG_EN0_Pin GPIO_PIN_0
#define SEG_EN0_GPIO_Port GPIOB
#define SEG_EN1_Pin GPIO_PIN_1
#define SEG_EN1_GPIO_Port GPIOB
#define LED_0_Pin GPIO_PIN_2
#define LED_0_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_10
#define EN3_GPIO_Port GPIOB
#define EN4_Pin GPIO_PIN_11
#define EN4_GPIO_Port GPIOB
#define EN5_Pin GPIO_PIN_12
#define EN5_GPIO_Port GPIOB
#define EN6_Pin GPIO_PIN_13
#define EN6_GPIO_Port GPIOB
#define EN7_Pin GPIO_PIN_14
#define EN7_GPIO_Port GPIOB
#define EN8_Pin GPIO_PIN_15
#define EN8_GPIO_Port GPIOB
#define SEG_B_Pin GPIO_PIN_8
#define SEG_B_GPIO_Port GPIOA
#define SEG_C_Pin GPIO_PIN_9
#define SEG_C_GPIO_Port GPIOA
#define SEG_D_Pin GPIO_PIN_10
#define SEG_D_GPIO_Port GPIOA
#define SEG_E_Pin GPIO_PIN_11
#define SEG_E_GPIO_Port GPIOA
#define SEG_F_Pin GPIO_PIN_12
#define SEG_F_GPIO_Port GPIOA
#define SEG_G_Pin GPIO_PIN_13
#define SEG_G_GPIO_Port GPIOA
#define LED_1_Pin GPIO_PIN_3
#define LED_1_GPIO_Port GPIOB
#define R_Pin GPIO_PIN_4
#define R_GPIO_Port GPIOB
#define G_Pin GPIO_PIN_5
#define G_GPIO_Port GPIOB
#define B_Pin GPIO_PIN_6
#define B_GPIO_Port GPIOB
#define EN0_Pin GPIO_PIN_7
#define EN0_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_8
#define EN1_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_9
#define EN2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
