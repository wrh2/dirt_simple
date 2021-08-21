/*
 * Header file for dirt simple circular fifo stack
 * Programmed by wrh2
 * github.com/wrh2
 */
#ifndef _DIRT_SIMPLE_
#define _DIRT_SIMPLE_

#include <stdint.h>

#define STACK_SIZE 100

#define STACK_DATA_TYPE uint8_t

uint8_t push_stack(STACK_DATA_TYPE * obj);
uint8_t pop_stack(STACK_DATA_TYPE *obj);
unsigned int stack_size(void);
unsigned int stack_underflow(void);
unsigned int stack_overflow(void);

#endif /* _DIRT_SIMPLE_ */
