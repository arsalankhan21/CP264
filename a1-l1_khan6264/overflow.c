/*
/*
--------------------------------------------------
Project: cp264oc-a1q1
File:    overflow.c
Author:  Arsalan Khan
Version: 2023-05-20
--------------------------------------------------
*/

#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(int argc, char *args[]) {
    int i, n = 0, b = 1;
    long long sum = 0;
    
    if (argc > 2) {
        sscanf(args[1], "%d", &b);
        sscanf(args[2], "%d", &n);
        
        if (b >= 1 && n >= 0) {
            for (i = 0; i <= n; i++) {
                long long term = (long long)pow(b, i);
                if (term > INT_MAX || sum + term > INT_MAX) {
                    printf("overflow\n");
                    return 0;
                }
                sum += term;
            }
            printf("powersum=%lld\n", sum);
        } else {
            printf("invalid argument\n");
        }
    } else {
        printf("arguments: b>0 n>0\n");
    }
    
    return 0;
}
