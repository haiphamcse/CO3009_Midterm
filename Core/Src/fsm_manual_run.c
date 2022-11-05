/*
 * fsm_manual_run.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */
#include "fsm_manual_run.h"
int status = 1;
void fsm_manual_run()
{
	switch(status){
			case INIT:
				if(isButtonPressed(0) == 1)
				{
					status = GREEN_MANUAL;
				}
				break;
			case GREEN_MANUAL:
						//DO STH
				HAL_GPIO_WritePin(GPIOA, SEG0_Pin, 0);
				HAL_GPIO_WritePin(GPIOA, SEG1_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, SEG2_Pin, 1);
				if(isButtonPressed(0) == 1)
				{
					status = YELLOW_MANUAL;
				}
				else if(isButtonPressed(0) == 2)
				{
					HAL_GPIO_TogglePin(GPIOA, OUT1_Pin);
				}
//				if(isButtonPressed(1) == 1)
//				{
//					status = RED_MANUAL;
//				}
				break;
			case YELLOW_MANUAL:
				HAL_GPIO_WritePin(GPIOA, SEG0_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, SEG1_Pin, 0);
				HAL_GPIO_WritePin(GPIOA, SEG2_Pin, 1);
				if(isButtonPressed(0) == 1)
				{
					status = RED_MANUAL;
				}
//				if(isButtonPressed(1) == 1)
//				{
//					status = GREEN_MANUAL;
//				}
				break;
			case RED_MANUAL:
				HAL_GPIO_WritePin(GPIOA, SEG0_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, SEG1_Pin, 1);
				HAL_GPIO_WritePin(GPIOA, SEG2_Pin, 0);
				if(isButtonPressed(0) == 1)
				{
					status = GREEN_MANUAL;
				}
//				if(isButtonPressed(1) == 1)
//				{
//					status = YELLOW_MANUAL;
//				}
				break;
			default:
				status = RED_MANUAL;
				break;
	}
}

