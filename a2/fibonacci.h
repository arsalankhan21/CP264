/*
--------------------------------------------------
Project: cp264oc-a2q1
File:    fibonacci.h
Author:  Arsalan Khan
Version: 2023-05-14
Compile: gcc fibonacci.c fibonacci_main.c
--------------------------------------------------
*/

#ifndef FIBONACCI_H
#define FIBONACCI_H

int iterative_fibonacci(int n);
int recursive_fibonacci(int n);
int dpbu_fibonacci(int *f, int n);
int dptd_fibonacci(int *f, int n);

#endif