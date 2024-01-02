/*--------------------------------------------------
Project:  cp264oc-a6
Author:   Arsalan Khan
Version:  2023-06-24
--------------------------------------------------
*/

#include <stdio.h>
#include "queue.h"
#include "expression.h"

int main(int argc, char *args[]) {
  char *infixstr = "10-((3*4)+8)/4";
  if (argc > 1) infixstr = args[1];

  printf("infix expression:%s\n", infixstr);  
  QUEUE postfix_queue = infix_to_postfix(infixstr);
  
  printf("postfix expression:");
  display(postfix_queue.front);
  printf("\n");
    
  printf("postfix evaluation:%d\n", evaluate_postfix(postfix_queue));
  queue_clean(&postfix_queue); 
  
  printf("infix evaluation:%d\n", evaluate_infix(infixstr));
  
  return 0;
}
