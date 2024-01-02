/*--------------------------------------------------
Project:  cp264oc-a6
Author:   Arsalan Khan
Version:  2023-06-24
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "stack.h"

void push(STACK *sp, NODE *np) {
  np->next = sp->top;  // Set the next pointer of the new node to the current top node
  sp->top = np;  // Make the new node the new top node
  sp->height++;  // Increment the height of the stack
}

NODE *pop(STACK *sp) {
  if (sp->top == NULL) {
    // If the stack is empty, return NULL
    return NULL;
  }

  NODE *topNode = sp->top;  // Store the top node
  sp->top = sp->top->next;  // Move the top pointer to the next node
  sp->height--;  // Decrement the height of the stack

  topNode->next = NULL;  // Set the next pointer of the top node to NULL before returning

  return topNode;
}

void stack_clean(STACK *sp) {
  clean(&(sp->top));  // Call the clean() function in common.h to clean the data stored in each node
  sp->height = 0;  // Reset the height of the stack
}
