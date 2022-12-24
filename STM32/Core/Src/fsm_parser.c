#include "fsm_parser.h"

#define MESS_BEGINNING		0
#define MESS_READING		1

uint8_t status = MESS_BEGINNING;
uint8_t command_flag = 0;
uint8_t command_data[MAX_BUFFER_SIZE];
uint8_t command_index = 0;

void command_parser_fsm() {
	switch (status) {
		case MESS_BEGINNING:
			if (buffer[buffer_index] == '!') {
				status = MESS_READING;
				command_index = 0;
				command_flag = 0;
			}
			break;

		case MESS_READING:
			if (buffer[buffer_index] == '!') {
				command_index = 0;
			}
			else if (buffer[buffer_index] == '#') {
				status = MESS_BEGINNING;
				command_data[command_index] = '\0';
				command_flag = 1;
			}
			else {
				command_data[command_index++] = buffer[buffer_index];
				command_index %= MAX_BUFFER_SIZE;
			}
			break;

		default:
			break;
	}
}
