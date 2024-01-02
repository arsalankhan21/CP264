/*
--------------------------------------------------
Project: cp264oc-a3q1
File:    mystring_main.c 
About:   public test driver
Author:  Arsalan Khan
ID:      210862640
Version: 2023-06-02
--------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include "mystring.h"

int main(int argc, char* args[]) {
  char str[100] = "     This Is    a Test   ";
  if (argc > 1) {
    strcpy(str, args[1]);
  }
  printf("str:\"%s\"\n", str);
  printf("str_len(str):%d\n", str_len(str));  
  printf("str_wc(str):%d\n", str_wc(str));
  str_lower(str);  
  str_trim(str);
  printf("str_trim(str):\"%s\"\n", str);
  printf("str_len(trim(str)):%d\n", str_len(str));
  return 0;
}


