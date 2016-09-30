/*
 * 	timer.h
 *
 *  Created on: 12 sep. 2016
 *  Author: Rick Kock en Arther vd Berg
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "timer.h"

void timerInit(unsigned long mr0Value, unsigned long prescaleValue);
void startTimer(void);
void resetInterrupt(void);
unsigned long timerRead(void);
unsigned int getSeconds(void);
unsigned int getMinutes(void);
unsigned int getHours(void);
void printTime(void);
void TIMER16_0_IRQHandler(void);

#endif /* TIMER_H_ */
