#ifndef INC_FSM_PARSER_H_
#define INC_FSM_PARSER_H_

#include "uart.h"

extern uint8_t command_flag;
extern uint8_t command_data[MAX_BUFFER_SIZE];

void command_parser_fsm();

#endif /* INC_FSM_PARSER_H_ */
