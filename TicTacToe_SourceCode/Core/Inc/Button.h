/*
 * Button.h
 *
 *  Created on: Oct 28, 2025
 *      Author: Hi
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "stdint.h"

#define NUMBER_OF_BUTTON 6

/**
 * Define button index
 */
#define BUTTON_UP 0
#define BUTTON_LEFT 1
#define BUTTON_DOWN 2
#define BUTTON_RIGHT 3

#define BUTTON_SELECT 4
#define BUTTON_SWITCH 5

#define TIME_FOR_HOLD_CHECK 3000	//ms	//Only be used for reseting via holding select_button

typedef struct {
	uint8_t button_id;
	GPIO_PinState previous_pin_read;
	GPIO_PinState internal_state;

	int32_t internal_timer;		//This need to be signed so we can check if it's negative
	uint32_t previous_read_time;

	uint8_t is_pressed;
	uint8_t is_hold;
} Button;

void Button_Init();
void Button_ReadInput();

uint8_t Button_IsPressed(uint8_t button);
uint8_t Button_IsHeld(uint8_t button);

#endif /* INC_BUTTON_H_ */
