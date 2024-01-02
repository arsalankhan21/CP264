/*--------------------------------------------------
Project: cp264oc-a9q2
Author:  Arsalan Khan 
Version: 2023-07-22
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common_queue_stack.h"
#include "expression_symbol.h"

int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%')
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else
    return -1;
}

QUEUE infix_to_postfix_symbol(char *infixstr, HASHTABLE *ht) {
  QUEUE postfixQueue;
  STACK operatorStack;
  postfixQueue.front = NULL;
  postfixQueue.rear = NULL;
  postfixQueue.length = 0;
  operatorStack.top = NULL;
  operatorStack.height = 0;

  int i = 0;
  while (infixstr[i] != '\0') {
    if (infixstr[i] == ' ') {
      i++;
      continue;
    }

    if (infixstr[i] >= '0' && infixstr[i] <= '9') {
      // Handle integer operands
      int value = 0;
      while (infixstr[i] >= '0' && infixstr[i] <= '9') {
        value = value * 10 + (infixstr[i] - '0');
        i++;
      }
      NODE *operandNode = new_node(value, 0);
      enqueue(&postfixQueue, operandNode);
    } else if (infixstr[i] == '(') {
      // Handle left parenthesis
      NODE *leftParenNode = new_node(infixstr[i], 2);
      push(&operatorStack, leftParenNode);
      i++;
    } else if (infixstr[i] == ')') {
      // Handle right parenthesis
      while (operatorStack.height > 0 && operatorStack.top->data != '(') {
        NODE *opNode = pop(&operatorStack);
        enqueue(&postfixQueue, opNode);
      }
      if (operatorStack.height > 0 && operatorStack.top->data == '(') {
        pop(&operatorStack); // Pop the '('
      }
      i++;
    } else {
      // Handle operators
      while (operatorStack.height > 0 && get_priority(operatorStack.top->data) >= get_priority(infixstr[i])) {
        NODE *opNode = pop(&operatorStack);
        enqueue(&postfixQueue, opNode);
      }
      NODE *operatorNode = new_node(infixstr[i], 1);
      push(&operatorStack, operatorNode);
      i++;
    }
  }

  // Pop any remaining operators from the stack and enqueue them to the postfix queue
  while (operatorStack.height > 0) {
    NODE *opNode = pop(&operatorStack);
    enqueue(&postfixQueue, opNode);
  }

  clean_stack(&operatorStack); // Clean up the operator stack

  return postfixQueue;
}

int evaluate_postfix(QUEUE queue) {
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

int evaluate_infix_symbol(char *infixstr, HASHTABLE *ht) {
  QUEUE postfixQueue = infix_to_postfix_symbol(infixstr, ht);
  int result = evaluate_postfix(postfixQueue);
  clean_queue(&postfixQueue);
  return result;
}