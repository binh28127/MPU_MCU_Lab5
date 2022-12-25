#include "uart.h"

//UART_HandleTypeDef huart2;
//
//uint8_t temp = 0;
//uint8_t buffer[MAX_BUFFER_SIZE];
//uint8_t buffer_index = 0;
//uint8_t buffer_flag = 0;
//
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
//	if (huart->Instance == USART2) {
////		HAL_UART_Transmit(&huart2, &temp, 1, 50);
//		buffer[buffer_index++] = temp;
//		buffer_index %= MAX_BUFFER_SIZE;
//		buffer_flag = 1;
//		HAL_UART_Receive_IT(&huart2, &temp, 1);
//	}
//}
