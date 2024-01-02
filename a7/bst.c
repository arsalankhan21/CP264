/*
-------------------------------------------------------
Project:  cp264oc-a7q2
Author:   Arsalan Khan
Version:  2023-07-08
-------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

TNODE *search(TNODE *root, char *name) {
  if (root == NULL || strcmp(root->data.name, name) == 0)
    return root;
  if (strcmp(root->data.name, name) > 0)
    return search(root->left, name);
  return search(root->right, name);
}

void insert(TNODE **rootp, char *name, float score) {
  if (*rootp == NULL) {
    *rootp = new_node(name, score);
  } else if (strcmp((*rootp)->data.name, name) > 0) {
    insert(&((*rootp)->left), name, score);
  } else {
    insert(&((*rootp)->right), name, score);
  }
}

void delete(TNODE **rootp, char *name) {
  if (*rootp == NULL)
    return;

  if (strcmp((*rootp)->data.name, name) > 0) {
    delete(&((*rootp)->left), name);
  } else if (strcmp((*rootp)->data.name, name) < 0) {
    delete(&((*rootp)->right), name);
  } else {
    if ((*rootp)->left == NULL) {
      TNODE *temp = *rootp;
      *rootp = (*rootp)->right;
      free(temp);
    } else if ((*rootp)->right == NULL) {
      TNODE *temp = *rootp;
      *rootp = (*rootp)->left;
      free(temp);
    } else {
      TNODE *smallest = extract_smallest_node(&((*rootp)->right));
      strcpy((*rootp)->data.name, smallest->data.name);
      (*rootp)->data.score = smallest->data.score;
      free(smallest);
    }
  }
}

TNODE *new_node(char *name, float score) {
  TNODE *np = (TNODE *)malloc(sizeof(TNODE));
  if (np) {
    strcpy(np->data.name, name);
    np->data.score = score;
    np->left = NULL;
    np->right = NULL;
  }
  return np;
}

TNODE *extract_smallest_node(TNODE **rootp) {
  TNODE *p = *rootp, *parent = NULL;
  if (p) {
    while (p->left) {
      parent = p;
      p = p->left;
    }
    
    if (parent == NULL)
      *rootp = p->right;
    else
      parent->left = p->right;
    
    p->left = NULL;
    p->right = NULL;
  }
  
  return p;
}

void clean_tree(TNODE **rootp) {
  TNODE *root = *rootp;
  if (root) {
    if (root->left)
      clean_tree(&root->left);
    if (root->right)
      clean_tree(&root->right);
    free(root);
  }
  *rootp = NULL;
}
