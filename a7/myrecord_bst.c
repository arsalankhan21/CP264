/*
-------------------------------------------------------
Project:  cp264oc-a7q2
Author:   Arsalan Khan
Version:  2023-07-08
-------------------------------------------------------
*/
 
#include <stdio.h>
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"

void update_stats(TREE *tree, float score) {
  tree->count++;
  float delta = score - tree->mean;
  tree->mean += delta / tree->count;
  tree->stddev += delta * (score - tree->mean);
}

void add_data(TREE *tree, char *name, float score) {
  TNODE *node = search(tree->root, name);
  if (node != NULL) {
    printf("Error: Record with name '%s' already exists.\n", name);
    return;
  }

  insert(&tree->root, name, score);
  update_stats(tree, score);
  tree->stddev = sqrt(tree->stddev / tree->count);
}

void remove_data(TREE *tree, char *name) {
  TNODE *node = search(tree->root, name);
  if (node == NULL) {
    printf("Error: Record with name '%s' does not exist.\n", name);
    return;
  }

  delete(&tree->root, name);
  update_stats(tree, -node->data.score);
  tree->stddev = sqrt(tree->stddev / tree->count);
}
