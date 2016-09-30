#ifdef __USE_CMSIS
#include "LPC13xx.h"
#endif

#include <cr_section_macros.h>

#include <stdio.h>

// TODO: insert other include files here
#include "timer.h"

// TODO: insert other definitions and declarations here

int main(void) {

	timerInit(500, 11999);
	startTimer();

    while(1) {
    }
    return 0 ;
}
