/*
--------------------------------------------------
Project: cp264oc-a2q1
File:    polynomial.c
Author:  Arsalan Khan
Version: 2023-05-14
Compile: gcc polynomial.c polynomial_main.c -o polynomial
--------------------------------------------------
*/

#include <stdio.h>
#include <math.h>
#include "polynomial.h"
#include<math.h>


float horner(float p[], int n, float x) {
    float result = p[0]; 
    for (int i = 1; i < n; i++)
        result = result * x + p[i];
    return result;
}

float bisection(float p[], int n, float a, float b) {
    float c;
    while (1) {
        c = (a + b) / 2;
        if (horner(p, n, c) == 0 || (b - a) / 2 < 1e-6 || fabs(horner(p, n, c)) < 1e-6)
            break;
        else if (horner(p, n, a) * horner(p, n, c) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}
