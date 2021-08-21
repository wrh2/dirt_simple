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
static unsigned int overflow_counter;
static unsigned int underflow_counter;

uint8_t push_stack(STACK_DATA_TYPE * obj){

  uint8_t result = STACK_SUCCESS;

  stack.buffer[stack.w_ptr++] = *obj;

  stack.w_ptr %= STACK_SIZE;

  stack.num_bytes++;

  // overflow error
  if(stack.num_bytes >= STACK_SIZE){

    overflow_counter++;

    result = STACK_FAILURE;

  }

  return result;

}

uint8_t pop_stack(STACK_DATA_TYPE * obj){

  uint8_t result = STACK_FAILURE;

  if(stack.num_bytes){

    *obj = stack.buffer[stack.r_ptr++];

    stack.r_ptr %= STACK_SIZE;

    stack.num_bytes--;

    result = STACK_SUCCESS;

  }
  else underflow_counter++; // underflow error

  return result;

}

inline unsigned int stack_size(void){

  return stack.num_bytes;

}

inline unsigned int stack_underflow(void){

  return underflow_counter;

}

inline unsigned int stack_overflow(void){

  return overflow_counter;

}
