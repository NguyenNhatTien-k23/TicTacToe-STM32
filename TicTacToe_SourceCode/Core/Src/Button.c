/*
 * Button.c
 *
 *  Created on: Oct 28, 2025
 *      Author: Hi
 */

#include "button.h"

#define BUTTON_STATE_PRESSED GPIO_PIN_RESET
#define BUTTON_STATE_RELEASE GPIO_PIN_SET

Button button_list[NUMBER_OF_BUTTON] = {};

void Button_ReadInput() {
	for (int index = 0; index < NUMBER_OF_BUTTON; ++index) {

		// Read pin first
		GPIO_PinState current_pin_read = HAL_GPIO_ReadPin(GPIOA, BUTTON_SELECT_Pin << index);

		// If state is stable (same as previous)
		if (current_pin_read == button_list[index].previous_pin_read) {

			// State changed from last stable reading
			if (button_list[index].internal_state != current_pin_read) {
				button_list[index].internal_state = current_pin_read;

				if (current_pin_read == BUTTON_STATE_PRESSED) {
					button_list[index].internal_timer = TIME_FOR_HOLD_CHECK;
					button_list[index].is_pressed = 1;
				} else {
					// Released -> clear hold flag
					button_list[index].is_hold = 0;
				}
			}
			else if (button_list[index].internal_state == BUTTON_STATE_PRESSED) {
				// Count down hold timer
				button_list[index].internal_timer--;
				if (button_list[index].internal_timer <= 0) {
					button_list[index].internal_timer = TIME_FOR_HOLD_CHECK;  // reset for next hold
					button_list[index].is_hold = 1;
				}
			}
		}

		// Update timing for next loop
		button_list[index].previous_pin_read = current_pin_read;
	}
}


void Button_Init(){
	for(int index = 0; index < NUMBER_OF_BUTTON; ++index){
		button_list[index].internal_timer = TIME_FOR_HOLD_CHECK;
		button_list[index].previous_pin_read = BUTTON_STATE_RELEASE;
		button_list[index].internal_state = BUTTON_STATE_RELEASE;
		button_list[index].is_pressed = 0;
		button_list[index].is_hold = 0;
	}

	button_list[BUTTON_SELECT].button_id = BUTTON_SELECT;
	button_list[BUTTON_SWITCH].button_id = BUTTON_SWITCH;
	button_list[BUTTON_LEFT].button_id = BUTTON_LEFT;
	button_list[BUTTON_UP].button_id = BUTTON_UP;
	button_list[BUTTON_DOWN].button_id = BUTTON_DOWN;
	button_list[BUTTON_RIGHT].button_id = BUTTON_RIGHT;

}

uint8_t Button_IsPressed(uint8_t button){
	if(button_list[button].is_pressed == 1){
		button_list[button].is_pressed = 0;
		return 1;
	}
	return 0;
}
uint8_t Button_IsHeld(uint8_t button){
	if(button_list[button].is_hold == 1){
		button_list[button].is_hold = 0;
		return 1;
	}
	return 0;
}
