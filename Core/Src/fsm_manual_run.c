/*
 * fsm_manual_run.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */
#include "fsm_manual_run.h"
int status = INIT;
/*
 * BUTTON[0] = RESET
 * BUTTON[1] = INC
 * BUTTON[2] = DEC
 * */
/*
 * TIMER_FLAG[0]: 7SEG
 * TIMER_FLAG[1]: LED_DEBUG
 * */

void fsm_LED()
{
	if(timer_flag[0] == 1)
	{
		HAL_GPIO_TogglePin(GPIOA, OUT5_Pin);
		setTimer(timer_delay[0], 0);
	}
}

void fsm_simple_buttons_run(){
	switch(status){
	case INIT:
		setTimer(100, 0);
		HAL_GPIO_WritePin(GPIOA,OUT2_Pin|OUT3_Pin|OUT4_Pin|OUT5_Pin,1);
		reset_counter();
		status = RS;
		break;
	case RS:
		HAL_GPIO_WritePin(GPIOA, OUT2_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, OUT3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, OUT4_Pin, 1);
		if(isButtonPressed(0) == 1)
		{
			reset_counter();
		}
		if(isButtonPressed(1) == 1)
		{
			increment();
			setTimer(duration_COUNTDOWN, 3);
			status = INC;
		}
		if(isButtonPressed(2) == 1)
		{
			decrement();
			setTimer(duration_COUNTDOWN, 3);
			status = DEC;
		}
		break;
	case INC_WAIT:
		if(timer_flag[1] == 1 && isButtonLongPressed(1) == 1)
		{
			increment();
			setTimer(100, 1);
			setTimer(duration_COUNTDOWN, 3);
		}
		if(isButtonPressed(0) == 1)
		{
			reset_counter();
			status = RS;
		}
		if(isButtonPressed(1) == 1)
		{
			increment();
			setTimer(duration_COUNTDOWN, 3);
			status = INC;
		}
		if(isButtonPressed(2) == 1)
		{
			decrement();
			setTimer(duration_COUNTDOWN, 3);
			status = DEC;
		}
		if(timer_flag[3] == 1){status = COUNTDOWN;}
		break;
	case INC:
		HAL_GPIO_WritePin(GPIOA, OUT2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, OUT3_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, OUT4_Pin, 1);
		if(isButtonPressed(0) == 1)
		{
			reset_counter();
			status = RS;
		}
		if(isButtonPressed(1) == 1)
		{
			increment();
			setTimer(duration_COUNTDOWN, 3);
		}
		if(isButtonLongPressed(1) == 1)
		{
			setTimer(duration_LONGPRESS, 1);
			status = INC_WAIT;
		}
		if(isButtonPressed(2) == 1)
		{
			decrement();
			setTimer(duration_COUNTDOWN, 3);
			status = DEC;
		}
		if(timer_flag[3] == 1){status = COUNTDOWN;}
		break;
	case DEC_WAIT:
		if(timer_flag[2] == 1 && isButtonLongPressed(2) == 1)
		{
			decrement();
			setTimer(100, 2);
			setTimer(duration_COUNTDOWN, 3);
		}
		if(isButtonPressed(0) == 1)
		{
			reset_counter();
			status = RS;
		}
		if(isButtonPressed(1) == 1)
		{
			increment();
			status = INC;
		}
		if(isButtonPressed(2) == 1)
		{
			decrement();
			status = DEC;
		}
		if(timer_flag[3] == 1){status = COUNTDOWN;}
		break;
	case DEC:
		HAL_GPIO_WritePin(GPIOA, OUT2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, OUT3_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, OUT4_Pin, 0);
		if(isButtonPressed(0) == 1)
		{
			reset_counter();
			status = RS;
		}
		if(isButtonPressed(1) == 1)
		{
			increment();
			setTimer(duration_COUNTDOWN, 3);
			status = INC;
		}
		if(isButtonLongPressed(2) == 1)
		{
			setTimer(duration_LONGPRESS, 2);
			status = DEC_WAIT;
		}
		if(isButtonPressed(2) == 1)
		{
			decrement();
			setTimer(duration_COUNTDOWN, 3);
		}
		if(timer_flag[3] == 1){status = COUNTDOWN;}
		break;
	case COUNTDOWN:
		if(timer_flag[3] == 1)
		{
			decrement();
			if(get_counter() == 0)
			{status = RS;}
			else{setTimer(100, 3);}
		}
		break;
	}

}
