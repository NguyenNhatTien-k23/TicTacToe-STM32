/*
 * Resource_Manager.h
 *
 *  Created on: Nov 5, 2025
 *      Author: Hi
 */

#ifndef INC_RESOURCE_MANAGER_H_
#define INC_RESOURCE_MANAGER_H_

#include <stdint.h>

#define SIDE_X 0
#define SIDE_O 1

/**
 * Board layout (represented via bitmap):
 * MSB		[2, 2], [2, 1], [2, 0], [1, 2], [1, 1], [1, 0], [0, 2], [0, 1], [0, 0]	LSB
 * MSB		9		8		7		6		5		4		3		2		1		LSB
 *
 * NOTE: Bit 10-15 is un-used
 *
 * Board layout (on the hardware):
 * [0, 0]	[0, 1]	 [0, 2]
 * [1, 0]	[1, 1]	 [1, 2]
 * [2, 0]	[2, 1]	 [2, 2]
 */

typedef struct{
	uint16_t bitmap_side_X;
	uint16_t bitmap_side_O;

}GameBoard;

typedef struct{
	uint8_t score_X;
	uint8_t score_O;

}GameInfo;

typedef struct{
	GameBoard game_board;
	GameInfo game_info;

	uint8_t running;		//Function only run when running == 1

	uint8_t
}Game;

GameBoard GetGameBoard();
GameInfo GetGameInfo();

/**
 * Position for input can be change depend on the UI side.
 */
void InputMove(uint8_t pos_i, uint8_t pos_j, uint8_t side);

/**
 * This should be called in the scheduler after input is used with period = 0
 */
void UpdateGameBoard();


#endif /* INC_RESOURCE_MANAGER_H_ */
