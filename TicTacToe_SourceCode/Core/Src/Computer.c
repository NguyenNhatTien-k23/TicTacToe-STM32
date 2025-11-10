/*
 * Computer.c
 *
 *  Created on: Nov 5, 2025
 *      Author: Hi
 */

#include "Computer.h"
void test(){
	HAL_GPIO_WritePin(R_GPIO_Port, R_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, GPIO_PIN_RESET);
	HAL_GPIO_TogglePin(EN2_GPIO_Port, EN2_Pin);
}
