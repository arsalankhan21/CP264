/*--------------------------------------------------
Project: cp264oc-a5q3
File:    bigint.c
Author:  Arsalan Khan
Version: 2023-06-17
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

BIGINT bigint(char *p) {
  BIGINT bn = {0};
  if (p == NULL) 
    return bn;
  else if (!(*p >= '0' && *p <= '9')) { // not begin with digits 
    return bn;
  }
  else if (*p == '0' && *(p+1) == '\0') { // just "0"
    dll_insert_end(&bn, new_node(*p -'0'));
    return bn;
  }  
  else { 
    while (*p) {
      if (*p >= '0' && *p <= '9' ){
        dll_insert_end(&bn, new_node(*p -'0'));
      } else {
        dll_clean(&bn);
        break;
      }
      p++;
    }
    return bn;
  }
}

BIGINT add(BIGINT opr1, BIGINT opr2) {
  BIGINT sum = bigint(NULL);
  NODE *p1 = opr1.end;
  NODE *p2 = opr2.end;
  int c = 0, a, b, s;
  while (p1 || p2 ) { // addition algorithm
    a = 0; b = 0;
    if (p1) { a = p1->data; p1 = p1->prev; }
    if (p2) { b = p2->data; p2 = p2->prev; }
    s = a + b + c;
    c = s / 10;
    s %= 10;
    dll_insert_start(&sum, new_node(s));
  }
  if (c == 1)
    dll_insert_start(&sum, new_node(1));
  return sum;
}

BIGINT Fibonacci(int n) {
  if (n <= 2)
    return bigint("1");
  else {
    BIGINT temp = bigint(NULL);
    BIGINT f1 = bigint("1");
    BIGINT f2 = bigint("1");

    for (int i = 3; i <= n; i++) {
      temp = add(f1, f2);
      dll_clean(&f1);
      f1 = f2;
      f2 = temp;
    }

    dll_clean(&f1);
    return f2;
  }
}
