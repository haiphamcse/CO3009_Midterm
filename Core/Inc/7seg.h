/*
 * 7seg.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_
#include "main.h"
#include "global.h"
void display7SEG();
void increment();
void decrement();
void reset_counter();
int get_counter();
extern int seg_counter;
#endif /* INC_7SEG_H_ */
