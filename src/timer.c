/*
 * 	timer.c
 *
 *  Created on: 12 sep. 2016
 *  Author: Rick Kock en Arther vd Berg
 */

#include "timer.h"

#define CT16B0 			0x4000C000
#define NVIC  			0xE000E000
#define SYSAHBCLKCTRL 	(*(unsigned int*) 0x40048080)
#define TMR16B0MR0 		(*(unsigned int*) (0x018 + CT16B0))
#define TMR16B0MCR 		(*(unsigned int*) (0x014 + CT16B0))
#define TMR16B0TC  		(*(unsigned int*) (0x008 + CT16B0))
#define TMR16B0TCR 		(*(unsigned int*) (0x004 + CT16B0))
#define TMR16B0IR  		(*(unsigned int*) (0x000 + CT16B0))
#define TMR16B0PR  		(*(unsigned int*) (0x00C + CT16B0))
#define ISER1	   		(*(unsigned int*) (0x104 + NVIC))

unsigned int seconds = 0;

void timerInit(unsigned long mr0Value, unsigned long prescaleValue) {
	// Enables clock for 16-bit counter/timer 0
	SYSAHBCLKCTRL |= (1 << 7);
	// Set speed to which the TC will increment
	TMR16B0PR |= (prescaleValue-1);
	// Set value to set a limit for TC to generate an interrupt
	TMR16B0MR0 |= mr0Value;
	/* Will enable an interrupt on MR0
	 * and reset the clock, so you don't need
	 * to do it manually.*/
	TMR16B0MCR |= (1 << 0) | (1 << 1);
	// Enables an interrupt on MR0
	ISER1 |= (1 << 9);
}

// Timer Counter and Prescale Counter are enabled for counting.
void startTimer(void) {
	TMR16B0TCR |= 0x1;
}

// Clears flag by writing 1
void resetInterrupt(void) {
	TMR16B0IR |= 0x1;
}

// Get timer counter value
unsigned long timerRead(void) {
	return TMR16B0TC;
}

// Disables timer
void stopTimer(void) {
	TMR16B0TCR &= ~0x1;
}

unsigned int getSeconds(void) {
	return seconds % 60;
}

unsigned int getMinutes(void) {
	int m = seconds / 60;

	while (m > 59) {
		m = m - 60;
	}
	return m;
}

unsigned int getHours(void) {
	int h = seconds / 3600;

	while (h > 23) {
		h = h - 24;
		seconds = 0;
	}
	return h;
}

void printTime(void) {
	printf("%2d:%02d:%02d\n", getHours(), getMinutes(), getSeconds());
}


