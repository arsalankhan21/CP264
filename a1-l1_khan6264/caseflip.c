/*
/*
--------------------------------------------------
Project: cp264oc-a1q1
File:    caseflip.c
Author:  Arsalan Khan
Version: 2023-05-20
--------------------------------------------------
*/

#include <stdio.h>

int main() {
  
  char c = 0, temp;
  do {
    printf("Please enter a character:\n");
    scanf("%c", &c); //this is to get a character input from keyboard stdin.

  // flush the input buffer 
    do { // this loop is to get rid of additional characters in stdin buffer
      scanf("%c", &temp);
      if (temp == '\n') break;
    } while (1);

    if (c == '!'){ 
      printf("Quit\n");
      break;
    } 
    else if (c >= 'a' && c <= 'z') // if the input is a lowercase letter then convert it to uppercase
      printf("%c,%d,%c,%d\n", c, c, c - 32, c - 32);
    else if (c >= 'A' && c <= 'Z') // if the input is a uppercase letter then convert it to lowercase
      printf("%c,%d,%c,%d\n", c, c, c + 32, c + 32);
    else if (c >= '0' && c <= '9') {
      int temp = c - '0';
      int out = temp*temp;
      printf("%c:%d,%c,%d\n", c, c,c,out);
    }
    else {
      printf("Invalid input\n");
    }
  
  } while (1);
  
  return 0;
}
  

  