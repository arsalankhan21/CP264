/*
 * your program signature
 */ 

#include "fibonacci.h"

int recursive_fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    else
    {
        return recursive_fibonacci(n - 2) + recursive_fibonacci(n-1);
    }
}

int iterative_fibonacci(int n)
{

}

int dpbu_fibonacci(int *f, int n) {

}

int dptd_fibonacci(int *f, int n) {

}
