/*--------------------------------------------------
Project: cp264oc-a5q3
File:    bigint.h
Author:  Arsalan Khan
Version: 2023-06-17
--------------------------------------------------
*/
 
#ifndef BIGINT_H
#define BIGINT_H
#include "dllist.h"

typedef DLL BIGINT;
BIGINT bigint(char *digitstr);
BIGINT add(BIGINT oprand1, BIGINT oprand2);
BIGINT Fibonacci(int n);

#endif