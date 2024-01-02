/*--------------------------------------------------
Project:  cp264oc-a6
Author:   Arsalan Khan
Version:  2023-06-24
--------------------------------------------------
*/

#ifndef STACK_H
#define STACK_H

#include "common.h"

typedef struct stack {
  int height;
  NODE *top;
} STACK;

void push(STACK *sp, NODE *np);
NODE *pop(STACK *sp);
void stack_clean(STACK *sp);

#endif