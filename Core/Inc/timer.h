/*
 * timer.h
 *
 *  Created on: Sep 24, 2022
 *      Author: PC
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_
#include "global.h"
#include "main.h"
#include "global.h"
#include "button.h"

extern int timer_delay[TIMER_COUNT];
extern int timer_counter[TIMER_COUNT];
extern int timer_flag[TIMER_COUNT];
void timerRun();
void setAllTimer(int duration);
void setTimer(int duration, int index);
#endif /* INC_TIMER_H_ */
