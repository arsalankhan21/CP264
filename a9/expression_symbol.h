/*--------------------------------------------------
Project: cp264oc-a9q2
Author:  Arsalan Khan 
Version: 2023-07-22
--------------------------------------------------
*/
 
#ifndef EXPRESSION_SYMBOL_H
#define EXPRESSION_SYMBOL_H
#include "common_queue_stack.h"
#include "hash.h"

QUEUE infix_to_postfix_symbol(char *infixstr, HASHTABLE *ht);
int evaluate_infix_symbol(char *infixstr, HASHTABLE *ht);
int evaluate_postfix(QUEUE queue);

#endif