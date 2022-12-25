#include "fsm_parser.h"

#define MESS_BEGINNING		0
#define MESS_READING		1

uint8_t status = MESS_BEGINNING;

void command_parser_fsm() {
	switch (status) {
		case MESS_BEGINNING:
			if (temp == '!') {
				status = MESS_READING;
				command_index = 0;
//				command_flag = 0;
			}
			break;

		case MESS_READING:
			if (temp == '!') {
				command_index = 0;
			}
			else if (temp == '#') {
				status = MESS_BEGINNING;
				command_data[command_index] = '\0';
				command_flag = 1;
			}
			else {
				command_data[command_index++] = temp;
				command_index %= MAX_BUFFER_SIZE;
			}
			break;

		default:
			break;
	}
}
