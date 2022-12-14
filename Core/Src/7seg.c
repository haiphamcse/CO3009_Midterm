/*
 * 7seg.c
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#include "7seg.h"
/*
 * INSTRUCTION: NEED TO SET SEG0->SEG6 PIN
 * 				ALSO ASSUME THE LED IS ACTIVE LOW
 * */
int seg_counter = 0;

//Get counter value
int get_counter()
{
	return seg_counter;
}

//Increment counter value
void increment(){seg_counter++;
if(seg_counter == 10){seg_counter=0;}
display7SEG();
}

//Decrement counter value
void decrement(){seg_counter--;
if(seg_counter < 0){seg_counter=9;}
display7SEG();
}

//Reset counter value
void reset_counter(){seg_counter = 0;
display7SEG();
}

//Display 7seg
void display7SEG()
{
	HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, 1);
	switch(seg_counter){
	case 0:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, 0);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA,SEG1_Pin|SEG2_Pin,0);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA,SEG0_Pin|SEG1_Pin|SEG3_Pin|SEG4_Pin|SEG6_Pin,0);
		HAL_GPIO_WritePin(GPIOA, SEG2_Pin|SEG5_Pin, 1);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin |SEG6_Pin, 0);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOA, SEG1_Pin|SEG2_Pin| SEG5_Pin|SEG6_Pin, 0);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin| SEG2_Pin | SEG3_Pin | SEG5_Pin | SEG6_Pin, 0);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 0);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG1_Pin | SEG2_Pin, 0);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, 0);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOA, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG5_Pin | SEG6_Pin, 0);
		break;
	}
}
