/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define TIMER_COUNT 4
#define BUTTON_COUNT 4

#define INIT 0

#define RS 8
#define INC 9
#define DEC 10

#define INC_WAIT 18
#define DEC_WAIT 19
#define COUNTDOWN 20

extern int status;

#define duration_COUNTDOWN 1000 //Duration to start counting down 7seg
#define duration_LONGPRESS 300 //Duration to long pressed state
#endif /* INC_GLOBAL_H_ */
