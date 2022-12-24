#ifndef INC_FSM_COMMUNICATION_H_
#define INC_FSM_COMMUNICATION_H_

#include <stdio.h>
#include "timer.h"
#include "uart.h"
#include "fsm_parser.h"

extern ADC_HandleTypeDef hadc1;

void uart_communication_fsm();

#endif /* INC_FSM_COMMUNICATION_H_ */
