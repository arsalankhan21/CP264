/*
/*
--------------------------------------------------
Project: cp264oc-a1q1
File:    quadratic.c
Author:  Arsalan Khan
Version: 2023-05-20
--------------------------------------------------
*/
#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6

int main(int argc, char* argv[])
{
  float a, b, c, disc, x1, x2;
  
  if (argc < 2) {  
     printf("argument input:missing\n");     
  } else {
    int n = sscanf(argv[1], "%f,%f,%f", &a, &b, &c); 
    if (n != 3) { 
      printf("input:invalid\n");  
    } else {
       printf("(%.2f)x^2+(%.2f)x+(%.2f)=0: ", a, b, c);
      if (fabs(a) < EPSILON) {
        printf("not a quadratic equation\n");
      } else {

        // write your solution logic for cases 2-4
        float insideRoot = pow(b, 2) - (4 * (a) * (c)); 

        if (insideRoot == 0 || insideRoot > 0) {
            x1 = (-b + sqrt(insideRoot)) / (2 * a);
            x2 = (-b - sqrt(insideRoot)) / (2 * a);
            printf("(%.2f)x^2+(%.2f)x+(%.2f)=0: %.2f, %.2f", a, b, c, x1, x2);
        } else if (insideRoot < 0) {
            insideRoot = insideRoot * -1;
            disc = sqrt(insideRoot) / (2 * a);
            x1 = -b / (2 * a);
            x2 = -b / (2 * a);
            printf("(%.2f)x^2+(%.2f)x+(%.2f)=0: %.2f + %.2fi, %.2f-%.2fi", a, b, c, x1, disc,x2, disc);

        }
            
        }
        
      }
    }
  return 0;
}