/*
--------------------------------------------------
Project: cp264oc-a2q1
File:    polynomial.h
Author:  Arsalan Khan
Version: 2023-05-14
Compile: gcc polynomial.c polynomial_main.c -o polynomial
--------------------------------------------------
*/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
 
float horner(float *p, int n, float x);
float bisection(float *p, int n, float a, float b);

#endif