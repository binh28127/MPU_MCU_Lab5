#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "stdio.h"
#include "timer.h"
#include "fsm_parser.h"
#include "fsm_communication.h"

#define MAX_BUFFER_SIZE		30
extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t buffer_index;
extern uint8_t buffer_flag;

extern uint8_t command_flag;
extern uint8_t command_data[MAX_BUFFER_SIZE];
extern uint8_t command_index;

#endif /* INC_GLOBAL_H_ */
