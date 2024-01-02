/*
--------------------------------------------------
Project: cp264oc-a2q1
File:    matrix.c 
Author:  Arsalan Khan
Version: 2023-05-14
Compile: gcc matrix.c matrix_main.c -o matrix
--------------------------------------------------
*/
#include <stdio.h>
#include <math.h>
#include "matrix.h"

float sum(float *v, int n) {
    float s = 0; // sum
    for (int i = 0; i < n; i++) { // loop through all elements
        s += v[i]; // add each element to sum
    }
    return s; // return sum

}

float norm(float *v, int n) {  // norm of a vector
    float sum_of_squares = 0.0; // sum of squares
    for (int i = 0; i < n; i++) // loop through all elements
        sum_of_squares += v[i] * v[i]; // add each element squared to sum
    return sqrt(sum_of_squares); // return square root of sum
}

float dot_product(float *v1, float *v2, int n) { // dot product of two vectors
    float result = 0.0; // result
    for (int i = 0; i < n; i++) // loop through all elements
        result += v1[i] * v2[i]; // add each element multiplied to result
    return result; // return result
}

void transpose_matrix(float *m1, float *m2, int n) {
    for (int i = 0; i < n; i++) { // loop through all elements
        for (int j = 0; j < n; j++) { // loop through all elements
            m2[j * n + i] = m1[i * n + j]; // swap elements
        }
    }
}

void matrix_multiply_vector(float *m, float *v1, float *v2, int n) {
    for (int i = 0; i < n; i++) { // for loop to iterate through the elements
        v2[i] = 0.0; // initializing vector 2 elements to 0 
        for (int j = 0; j < n; j++) { // Setting a for loop 
            v2[i] += m[i * n + j] * v1[j]; // Accumulating the sum of matrix times the vector 
        }
    }
}

void multiply_matrix(float *m1, float *m2, float *m3, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m3[i * n + j] = 0.0;
            for (int k = 0; k < n; k++) {
                m3[i * n + j] += m1[i * n + k] * m2[k * n + j];
            }
        }
    }
}