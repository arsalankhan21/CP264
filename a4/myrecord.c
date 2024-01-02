/*
--------------------------------------------------
Project: cp264oc-a4q2
File:    myrecord.c  
About:   record functions
Author:  Arsalan Khan
Version: 2023-06-10
--------------------------------------------------
*/
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "mysort.h"
#include "myrecord.h"

#define MAX_LINE 100

GRADE grade(float score){
  GRADE r = {"F", 0};
  int p = (int) round(score);
  r.percentage = p;
  if (p >= 90) strcpy(r.letter_grade, "A+");
  else if (p >= 85) strcpy(r.letter_grade, "A");
  else if (p >= 80) strcpy(r.letter_grade, "A-");
  else if (p >= 77) strcpy(r.letter_grade, "B+");
  else if (p >= 73) strcpy(r.letter_grade, "B");
  else if (p >= 70) strcpy(r.letter_grade, "B-");
  else if (p >= 67) strcpy(r.letter_grade, "C+");
  else if (p >= 63) strcpy(r.letter_grade, "C");
  else if (p >= 60) strcpy(r.letter_grade, "C-");
  else if (p >= 57) strcpy(r.letter_grade, "D+");
  else if (p >= 53) strcpy(r.letter_grade, "D");
  else if (p >= 50) strcpy(r.letter_grade, "D-");
  else strcpy(r.letter_grade, "F");
  
  return r;
}

STATS process_data(RECORD *dataset, int n) {
  STATS stats = {0, 0, 0, 0};
  float sum = 0.0;
  float sum_squared = 0.0;

  for (int i = 0; i < n; i++) {
    stats.count++;
    sum += dataset[i].score;
  }
  stats.mean = sum / stats.count;

  for (int i = 0; i < n; i++) {
    float deviation = dataset[i].score - stats.mean;
    sum_squared += deviation * deviation;
  }
  stats.stddev = sqrt(sum_squared / stats.count);

  // Create an array of pointers to scores
  float *scores[n];
  for (int i = 0; i < n; i++) {
    scores[i] = &(dataset[i].score);
  }

  // Sort the scores using quick_sort
  quick_sort(scores, 0, n - 1);

  // Calculate median
  int mid = (n - 1) / 2;
  stats.median = (n % 2 == 0) ? (scores[mid][0] + scores[mid + 1][0]) / 2.0 : scores[mid][0];

  return stats;
}


int import_data(char *infilename, RECORD *dataset) {
  FILE *fp = fopen(infilename, "r");
  if (fp == NULL) {
    printf("file %s not found\n", infilename);
    return 0;
  }
  char line[MAX_LINE];
  int i = 0;
  while (fgets(line, MAX_LINE, fp) != NULL) {
    sscanf(line, "%[^,],%f", dataset[i].name, &dataset[i].score);
    i++;
  }
  fclose(fp);
  return i;
}


int report_data(char *outfilename, RECORD dataset[], STATS stats) {
  FILE *fp = fopen(outfilename, "w");
  if (fp == NULL) {
    printf("file %s cannot be created\n", outfilename);
    return 0;
  }
  int i;
  fprintf(fp, "Stats     value\n");
  fprintf(fp, "count     %-6.1f\n", stats.count);
  fprintf(fp, "mean      %-6.1f\n", stats.mean);
  fprintf(fp, "stddev    %-6.1f\n", stats.stddev);
  fprintf(fp, "median    %-6.1f\n\n", stats.median);
  fprintf(fp, "name      score %%     grade\n");
  for (i = 0; i < stats.count; i++) {
    GRADE g = grade(dataset[i].score);
    fprintf(fp, "%-10s%-6.1f%-6d%-6s\n", dataset[i].name, dataset[i].score, g.percentage, g.letter_grade);
  }
  fclose(fp);
  return 1;
}

