/*--------------------------------------------------
Project:  cp264oc-a6
Author:   Arsalan Khan
Version:  2023-06-24
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

/*
 * auxiliary function
 */
int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%')
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else
    return -1;
}

/*
 * auxiliary function
 */
int type(char c) {
  if (c >= '0' && c <= '9')
    return 0;
  else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
    return 1;
  else if (c == '(')
    return 2;
  else if (c == ')')
    return 3;
  else
    return 4;
}

QUEUE infix_to_postfix(char *infixstr) {
  char *p = infixstr;
  QUEUE queue = {0}; // result postfix expression in queue
  STACK stack = {0}; // auxiliary stack
  int sign = 1, num = 0; // sign and number of an operand
  while (*p) { // expression str traversal
    if (*p == '-' && (p == infixstr || *(p - 1) == '(')) { // get the sign of an operand
      sign = -1; // negative sign
    } else if (*p >= '0' && *p <= '9') { // case of number character
      // use horner’s algorithm to get the operand
      num = *p - '0'; // convert the first digit to int
      while (*(p + 1) >= '0' && *(p + 1) <= '9') {
        num = num * 10 + *(p + 1) - '0';
        p++; // move to next digit 
      }
      enqueue(&queue, new_node(sign * num, 0)); // enqueue the operand
      sign = 1; // reset sign
    } else if (*p == '(') { // case of left parenthesis
      push(&stack, new_node(*p, 2)); // push it into the stack
    } else if (*p == ')') { // case of right parenthesis
      while (stack.top && stack.top->data != '(') { // pop each node and insert it into the queue
        enqueue(&queue, pop(&stack));            // until the left parenthesis is found 
      }
      if (stack.top && stack.top->data == '(') { // pop the left parenthesis
        pop(&stack);
      } else {
        fprintf(stderr, "Invalid expression: Mismatched parentheses.\n");
        exit(1);
      }
    } else if (type(*p) == 1) { // case of operator
      while (stack.top && get_priority(stack.top->data) >= get_priority(*p)) {
        enqueue(&queue, pop(&stack)); // pop each node and insert it into the queue
      }
      push(&stack, new_node(*p, 1));
    }
    p++; // move to next character
  }
  // finally, pop each node and insert it into the queue
  while (stack.top) { // until the stack is empty 
    if (stack.top->data == '(') {
      fprintf(stderr, "Invalid expression: Mismatched parentheses.\n");
      exit(1);
    }
    enqueue(&queue, pop(&stack)); // pop each node and insert it into the queue
  }
  return queue;
}

int evaluate_postfix(QUEUE queue) { // evaluate the postfix expression
  NODE *p = queue.front;
  STACK stack = {0}; // auxiliary stack for postfix evaluation
  int type = 0;
  while (p) { // traverse the queue linked list
    type = p->type;
    if (type == 0) { // operand
      push(&stack, new_node(p->data, 0));
    } else if (type == 1) { // operator
      int operand2 = pop(&stack)->data; // pop the top two nodes
      int operand1 = pop(&stack)->data; // and evaluate the result
      int result = 0; // result of the operation
      switch (p->data) {
        case '+':
          result = operand1 + operand2; 
          break;
        case '-':
          result = operand1 - operand2; 
          break;
        case '*':
          result = operand1 * operand2; 
          break;
        case '/':
          result = operand1 / operand2; 
          break;
        case '%':
          result = operand1 % operand2;
          break;
      }
      push(&stack, new_node(result, 0));
    }
    p = p->next;
  }
  if (stack.top && stack.top->next == NULL) { // if the stack has only one node
    int result = stack.top->data;
    free(stack.top);
    return result;
  } else {
    fprintf(stderr, "Invalid postfix expression.\n"); // invalid postfix expression
    exit(1);
  }
}

int evaluate_infix(char *infixstr) { // evaluate the infix expression
  QUEUE postfix_queue = infix_to_postfix(infixstr); // convert infix to postfix
  int result = evaluate_postfix(postfix_queue);   // evaluate the postfix expression
  queue_clean(&postfix_queue); // clean the postfix queue
  return result;
}
