#include <stdint.h>

#define STACK_SIZE 100

#define STACK_DATA_TYPE uint8_t

uint8_t push_stack(STACK_DATA_TYPE * obj);
uint8_t pop_stack(STACK_DATA_TYPE *obj);
