/*--------------------------------------------------
Project:  cp264oc-a6
Author:   Arsalan Khan
Version:  2023-06-24
--------------------------------------------------
*/
#ifndef COMMON_H
#define COMMON_H

/* 
Node structure of linked queue stack for postfix expression operations 
int data - represent operand, operator, or parenthesis according to the type
int type - 0:operand; 1:operator; 2:left parenthesis 3:right parenthesis      
*/ 
typedef struct node {
	int data;  
	int type; 
	struct node *next;
} NODE;

NODE *new_node(int data, int type);
void clean(NODE **startp);
void display(NODE *start);

#endif
