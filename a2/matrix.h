/*
--------------------------------------------------
Project: cp264oc-a2q1
File:    matrix.h
Author:  Arsalan Khan
Version: 2023-05-14
Compile: gcc matrix.c matrix_main.c -o matrix
--------------------------------------------------
*/
 
#ifndef MATRIX_H
#define MATRIX_H
 
float sum(float *v, int n);
float norm(float *v, int n);
float dot_product(float *v1, float *v2, int n);
void transpose_matrix(float *m1, float *m2, int n);
void multiply_matrix(float *m1, float *m2, float *m3, int n);
void matrix_multiply_vector(float *m, float *v1, float *v2, int n);

#endif