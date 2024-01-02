/*
--------------------------------------------------
Project: cp264oc-a4q1 
File:    mysort.c
About:   public test driver for mysort.c
Author:  Arsalan Khan
Version: 2023-06-10
--------------------------------------------------
*/

#include "mysort.h"


void select_sort(float *a[], int left, int right){
    int i, j, min; // loop counters
    float *temp; // temporary pointer for swapping
    for (i = left; i <= right; i++) { // loop for each element
        min = i; 
        for (j = i + 1; j <= right; j++) {
            if (*a[j] < *a[min])  // compare data
                min = j;
        }
        if (min != i) { // swap pointers if necessary
        temp = a[min]; // set temp to point to a[i]
        a[min] = a[i]; // set a[i] to point to a[min]
        a[i] = temp; // set a[min] to point to temp  
        }

    }

    

}

void quick_sort(float *a[], int left, int right) { 

    int i, j, pivot; // loop counters
    float *temp; // temporary pointer for swapping
    if (left < right) { // base case
        pivot = left; // set pivot to left
        i = left; // set i to left
        j = right; // set j to right
        while (i < j) { // loop until i and j cross
            while (*a[i] <= *a[pivot] && i < right) { // move i right until data > pivot
                i++;
            }
            while (*a[j] > *a[pivot]) { // move j left until data <= pivot
                j--;
            }
            if (i < j) { // swap pointers if necessary
                temp = a[i]; // set temp to point to a[i]
                a[i] = a[j]; // set a[i] to point to a[j]
                a[j] = temp; // set a[j] to point to temp
            }
        }
        temp = a[pivot]; // set temp to point to a[pivot]
        a[pivot] = a[j]; // set a[pivot] to point to a[j]
        a[j] = temp; // set a[j] to point to temp
        quick_sort(a, left, j - 1); // recursive call on left subarray
        quick_sort(a, j + 1, right); // recursive call on right subarray
    }

}