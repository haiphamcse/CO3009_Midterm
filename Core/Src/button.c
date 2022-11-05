/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */
#include "button.h"

//INIT KEYREG STATE
int KeyReg0[BUTTON_COUNT] = {NORMAL_STATE};
int KeyReg1[BUTTON_COUNT] = {NORMAL_STATE};
int KeyReg2[BUTTON_COUNT] = {NORMAL_STATE};
int KeyReg3[BUTTON_COUNT] = {NORMAL_STATE};
int counter[BUTTON_COUNT] = {0};
uint16_t button[] = {IN0_Pin, IN1_Pin, IN2_Pin, IN3_Pin};
int TimeOutForKeyPress[BUTTON_COUNT] = {KEY_TIMED_OUT}; //What is this and how do we quantify this
int button_flag[BUTTON_COUNT] = {0}; //Init button flag to 0
int button_long_flag[BUTTON_COUNT] = {0};
void subKeyProcess(int index) //Used to set button at index flag
{
	button_flag[index] = 1;
}
void subKeyLongProcess(int index){
	button_long_flag[index] = 1;
}
//Thay Nhan Version
int isButtonPressed(int index) //Check button at index is pressed or not
{
	if(button_flag[index] == 1){
		button_flag[index] = 0; //Reset flag
		return 1;
	}
	else return 0;
}

int isButtonLongPressed(int index){
	if(button_long_flag[index] == 1){
		button_long_flag[index] = 0; //Reset flag
		return 1;
	}
	else return 0;
}
//
//void getKeyInput() //Thay Nhan version 1
//{
//	for (int i = 0; i < BUTTON_COUNT; i++)
//	{
//		KeyReg2[i] = KeyReg1[i];
//		KeyReg1[i] = KeyReg0[i];
//		KeyReg0[i] = HAL_GPIO_ReadPin(GPIOB, button[i]); //How to set button in series?
//		//Debouncing
//		if(		(KeyReg1[i] == KeyReg0[i])
//			&&	(KeyReg1[i] == KeyReg2[i])	) //If all 3 registers have the same values
//		{
//			if(KeyReg2[i] != KeyReg3[i])
//			{
//				KeyReg3[i] = KeyReg2[i];
//
//				if(KeyReg2[i] == PRESSED_STATE)
//				{
//					subKeyProcess(i);
//					TimeOutForKeyPress = KEY_TIMED_OUT;
//				}
//			}
//			else
//			{
//				//DO sth else
//				TimeOutForKeyPress--;
//				if (TimeOutForKeyPress == 0){
////					if(KeyReg2[i] == PRESSED_STATE)
////					{button_flag[i] = 2;}
////					TimeOutForKeyPress = KEY_TIMED_OUT;
//					KeyReg3[i] = NORMAL_STATE;
//				}
//			}
//		}
//	}
//}
//


void getKeyInput() //Thay Nhan version 1
{
	for (int i = 0; i < BUTTON_COUNT; i++)
	{
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(GPIOB, button[i]);
		//Debouncing
		if((KeyReg1[i] == KeyReg0[i])
		&&(KeyReg1[i] == KeyReg2[i])) //If all 3 registers have the same values
		{
			if(KeyReg3[i] != KeyReg2[i])
			{
				KeyReg3[i] = KeyReg2[i];

				if(KeyReg2[i] == PRESSED_STATE)
				{
					subKeyProcess(i);
					TimeOutForKeyPress[i] = KEY_TIMED_OUT;
				}
			}
			else
			{
				//DO sth else
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0){
//					KeyReg3[i] = NORMAL_STATE;
					if(KeyReg2[i] == PRESSED_STATE)
					{
						subKeyLongProcess(i);
					}
					TimeOutForKeyPress[i] = KEY_TIMED_OUT;
				}
			}
		}
	}
}

