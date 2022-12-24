#include "fsm_communication.h"

#define COM_RST			0
#define COM_ADC			1
#define COM_OK			2

ADC_HandleTypeDef hadc1;
uint8_t message_status = COM_RST;
char str[50];
uint32_t ADC_value = 0;

void uart_communication_fsm() {
	switch (message_status) {
		case COM_RST:
			if (command_flag) {
				command_flag = 0;

				if (command_data[0] == 'R' && command_data[1] == 'S' && command_data[2] == 'T') {
					message_status = COM_ADC;
					HAL_ADC_Start(&hadc1);
					ADC_value = HAL_ADC_GetValue(&hadc1);
					HAL_ADC_Stop(&hadc1);
				}
			}
			break;

		case COM_ADC:
			message_status = COM_OK;
			HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "!ADC=%ld#\r\n", ADC_value), 100);
			setTimer(1, 3000);
			break;

		case COM_OK:
			if (command_flag) {
				command_flag = 0;

				if (command_data[0] == 'O' && command_data[1] == 'K') {
					message_status = COM_RST;
				}
			}
			else if (isTimerUp(1)) {
				message_status = COM_ADC;
			}
			break;

		default:
			break;
	}
}
