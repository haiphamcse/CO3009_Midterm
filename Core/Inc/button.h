/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"
#include "global.h"

#define NORMAL_STATE SET
#define PRESSED_STATE RESET
#define KEY_TIMED_OUT 100
extern int button_flag[BUTTON_COUNT];
void getKeyInput();
int isButtonPressed(int);
int isButtonLongPressed(int);
#endif /* INC_BUTTON_H_ */
