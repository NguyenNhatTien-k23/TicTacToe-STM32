/*
 * Schedular.h
 *
 *  Created on: Oct 29, 2025
 *      Author: Hi
 */

#ifndef INC_SCHEDULAR_H_
#define INC_SCHEDULAR_H_

#define MAX_TASK_CAPACITY 40

#include <stdint.h>
#include <stdlib.h>
#include "Queue.h"
#include "main.h"

typedef struct TaskNode TaskNode_t;

typedef struct {
	void (* task_function)(void);

	int32_t delay;
	int32_t period;

	uint8_t task_id;
}Task;

typedef struct TaskNode{
	Task* task;
	TaskNode_t* next_node;
}TaskNode_t;

void Schedular_Init();

uint8_t Schedular_AddTask(void (* function)(void), int32_t delay, int32_t period);
void Schedular_DeleteTask(uint8_t task_id);

void Schedular_Update();
void Schedular_Dispatch();

void LinkedList_Add(TaskNode_t* head_node, TaskNode_t* new_node);
TaskNode_t* LinkedList_PopHead(TaskNode_t* head_node);
#endif /* INC_SCHEDULAR_H_ */
