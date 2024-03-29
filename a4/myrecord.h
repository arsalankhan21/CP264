/*
--------------------------------------------------
Project: cp264oc-a4q2
File:    myrecord.h
About:   record functions
Author:  Arsalan Khan
Version: 2023-06-10
--------------------------------------------------
*/
 
#ifndef MYRECORD_H
#define MYRECORD_H 

typedef struct {
  char name[40];
  float score;
} RECORD;

typedef struct {
  float count;
  float mean;
  float stddev;
  float median;
} STATS;

typedef struct {
  char letter_grade[5];
  int percentage;
} GRADE;

GRADE grade(float score);
int import_data(char *infilename, RECORD *dataset); 
STATS process_data(RECORD *dataset, int n);   
int report_data(char *outfilename,  RECORD *dataset, STATS stats);
 
#endif