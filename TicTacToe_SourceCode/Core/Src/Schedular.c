/*
 * Schedular.c
 *
 *  Created on: Oct 29, 2025
 *      Author: Hi
 */

#include "Schedular.h"

Queue avalable_task_id_list;
Queue ready_task_list;

Task task_list[MAX_TASK_CAPACITY] = {};
TaskNode_t* head;

void Schedular_Init(){
	//Initialize queues
	Queue_Init(&avalable_task_id_list);
	Queue_Init(&ready_task_list);

	//Initialize Linked list with dummy node
	head = (TaskNode_t*)malloc(sizeof(TaskNode_t));
	head->next_node = 0;

	//Initialize task_id that are "free"
	for(int i = 0; i < MAX_TASK_CAPACITY; ++i){
		Queue_PushBack(i, &avalable_task_id_list);
	}
}

uint8_t Schedular_AddTask(void (* function)(void), int32_t delay, int32_t period){
	uint8_t task_id = Queue_PopFront(&avalable_task_id_list);

	task_list[task_id].task_id = task_id;
	task_list[task_id].task_function = function;
	task_list[task_id].delay = delay / 10;
	task_list[task_id].period = period / 10;

	TaskNode_t* new_node = (TaskNode_t*)malloc(sizeof(TaskNode_t));
	new_node->task = &task_list[task_id];
	new_node->next_node = 0;

	LinkedList_Add(head, new_node);
	return task_id;
}

void Schedular_DeleteTask(uint8_t task_id){
	task_list[task_id].task_id = 0;
	task_list[task_id].task_function = 0;
	task_list[task_id].delay = 0;
	task_list[task_id].period = 0;
}

void Schedular_Update(){
	if(head->next_node == 0){
		return;
	}

	if(head->next_node && head->next_node->task->delay <= 0){
		TaskNode_t* timed_up_task = LinkedList_PopHead(head);
		if(timed_up_task == 0){
			return;
		}

		uint8_t removed_task_id = timed_up_task->task->task_id;
		Queue_PushBack(removed_task_id, &ready_task_list);

		if(timed_up_task->task->period > 0){
			timed_up_task->task->delay = timed_up_task->task->period;
			LinkedList_Add(head, timed_up_task);
		}
		else{
			free(timed_up_task);
		}

	}

	if(head->next_node){
		head->next_node->task->delay -= 1;
	}
}

void Schedular_Dispatch(){
	if(ready_task_list.size > 0){
		uint8_t finished_task_id = Queue_PopFront(&ready_task_list);
		if(task_list[finished_task_id].task_function != 0){
			(*task_list[finished_task_id].task_function)();
		}

		if(task_list[finished_task_id].period <= 0){
			Schedular_DeleteTask(finished_task_id);
			Queue_PushBack(finished_task_id, &avalable_task_id_list);

		}
	}
}

void LinkedList_Add(TaskNode_t* head_node, TaskNode_t* new_node){
	TaskNode_t* current_node = head_node;

	//Iterate until new_node to appropriate location while calculating its delay
	while(current_node->next_node && current_node->next_node->task->delay < new_node->task->delay){
		new_node->task->delay -= current_node->next_node->task->delay;
		current_node = current_node->next_node;
	}

	//Insert the new node to the appropriate location
	new_node->next_node = current_node->next_node;
	current_node->next_node = new_node;

	//If the new_node is not at tail -> update the counter next to it
	if(new_node->next_node != 0){
		new_node->next_node->task->delay -= new_node->task->delay;
	}
};

TaskNode_t* LinkedList_PopHead(TaskNode_t* head_node){
	if(head_node->next_node == 0){
		return 0;
	}

	TaskNode_t* removed_node = head_node->next_node;
	head_node->next_node = removed_node->next_node;
	return removed_node;
}
