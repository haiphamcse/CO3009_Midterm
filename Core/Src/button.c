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
int button[] = {IN0_Pin, IN1_Pin};

int TimeOutForKeyPress = KEY_TIMED_OUT; //What is this and how do we quantify this
int button_flag[BUTTON_COUNT] = {0}; //Init button flag to 0
int temp;
void subKeyProcess(int index) //Used to set button at index flag
{
	button_flag[index] = 1;
}

//int isButtonPressed(int index)
//{
//	if(index >= BUTTON_COUNT) return 0;
//	else if(KeyReg3[index] == PRESSED_STATE)
//	{
//		KeyReg3[index] = NORMAL_STATE;
//		return 1;
//	}
//	else return 0;
//}
//
//int isButtonLongPressed(int index)
//{
//	if(index >= BUTTON_COUNT) return 0;
//	else if(button_flag[index] == 1)
//	{
//		button_flag[index] = 0;
//		return 1;
//	}
//	else return 0;
//}
//void getKeyInput()
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
//			KeyReg3[i] = KeyReg2[i];
//			button_flag[i] = 1;
//			if(KeyReg3[i] == PRESSED_STATE)
//			{
//				if(counter[i] < TimeOutForKeyPress)
//				{
//					counter[i]++;
//				}
//				else
//				{
//					button_flag[i] = 2;
//				}
//			}
//			else
//			{
//				counter[i] = 0;
//				button_flag[i] = 0;
//			}
//
//		}
//	}
//}
//Thay Nhan Version
int isButtonPressed(int index) //Check button at index is pressed or not
{
	if(button_flag[index] != 0){
		temp = button_flag[index];
		button_flag[index] = 0; //Why set this to 0?
		return temp;
	} return 0;
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
		KeyReg2[i] = HAL_GPIO_ReadPin(GPIOB, button[i]); //How to set button in series?
		//Debouncing
		if((KeyReg1[i] == KeyReg0[i])
		&&(KeyReg1[i] == KeyReg2[i])) //If all 3 registers have the same values
		{
			if(KeyReg2[i] != KeyReg3[i])
			{
				KeyReg3[i] = KeyReg2[i];

				if(KeyReg2[i] == PRESSED_STATE)
				{
					subKeyProcess(i);
					TimeOutForKeyPress = KEY_TIMED_OUT;
				}
			}
			else
			{
				//DO sth else
				TimeOutForKeyPress--;
				if (TimeOutForKeyPress == 0){
//					KeyReg3[i] = NORMAL_STATE;
					if(KeyReg2[i] == PRESSED_STATE)
					{
						subKeyProcess(i);
					}
					TimeOutForKeyPress = KEY_TIMED_OUT;
				}
			}
		}
	}
}

