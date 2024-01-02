/*--------------------------------------------------
Project:  cp264oc-a6
Author:   Arsalan Khan
Version:  2023-06-24
--------------------------------------------------
*/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "common.h"
#include "queue.h"


QUEUE infix_to_postfix(char *infixstr);

int evaluate_postfix(QUEUE queue);

int evaluate_infix(char *infixstr);

#endif