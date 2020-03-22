#ifndef INC_S_PORT_H_
#define INC_S_PORT_H_

#include "stm8s.h"

#ifdef __cplusplus
extern "C" {
#endif



/* Copyright xhawk, MIT license */
typedef unsigned long long uint64_t;
typedef signed long long my_clock_diff_t;

/* Size for stack for each stask. */
#define STACK_SIZE 200

/* Timer functions need to be implemented on a new porting. */

/* === Timer functions on posix/linux === */
#include <time.h>

//1. define a type for clock and ucontext_t
typedef uint16_t my_clock_t;

typedef struct {
    int sp;
} ucontext_t;

//2. define the clock ticks count for one second
#define MY_CLOCKS_PER_SEC ((uint32_t)16*1000*1000/16384)

//3. Implement the initilization function for clock. Leave it blank if not required.
void my_clock_init(void);

//4. Implement the function of getting current clock ticks.
my_clock_t my_clock(void);

//5. Implement the idle delay function.
void my_on_idle(uint32_t max_idle_ms);

#ifdef __cplusplus
}
#endif
#endif

