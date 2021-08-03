/*
 * Implementation file for dirt simple circular fifo stack
 * Programmed by wrh2
 * github.com/wrh2
 */

#include "stack.h"

#define STACK_SUCCESS 1
#define STACK_FAILURE 0

typedef struct{

  STACK_DATA_TYPE buffer[STACK_SIZE];

  unsigned int num_bytes;

  // write pointer
  unsigned int w_ptr;

  // read pointer
  unsigned int r_ptr;

}stack_t;

static stack_t stack = {0};

uint8_t push_stack(STACK_DATA_TYPE * obj){

  stack.buffer[stack.w_ptr++] = *obj;

  stack.w_ptr %= STACK_SIZE;

  stack.num_bytes++;

  // if stack.w_ptr == 0, overflow error
  return !stack.w_ptr ? STACK_FAILURE : STACK_SUCCESS;

}

uint8_t pop_stack(STACK_DATA_TYPE * obj){

  uint8_t result = STACK_FAILURE;

  if(stack.num_bytes){

    *obj = stack.buffer[stack.r_ptr++];

    stack.r_ptr %= STACK_SIZE;

    stack.num_bytes--;

    result = STACK_SUCCESS;

  }

  return result;

}
