/*--------------------------------------------------
Project:  cp264oc-a6
Author:   Arsalan Khan
Version:  2023-06-24
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

NODE *new_node(int data, int type) {
  NODE *np = (NODE *) malloc(sizeof(NODE));
  np->data = data;
  np->type = type;
  np->next = NULL;
  return np;
}

void clean(NODE **startp) {
  NODE *tmp, *p = *startp;
  while (p) {
    tmp = p;
    p = p->next;
    free(tmp);
  }
  *startp = NULL;
}

void display(NODE *start) {
  while (start) {
    if (start->type == 0) 
      printf("%d", start->data);
    else 
      printf("%c", start->data);      
    
    start = start->next;
    
    if (start) printf(" ");
  }
}