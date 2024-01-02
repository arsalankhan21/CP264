
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "avl.h"

// Helper functions
int max(int a, int b);
int height(TNODE *np);

int max(int a, int b) {
  return (a > b) ? a : b;
}

int height(TNODE *np) {
  if (np == NULL) {
    return 0;
  } else {
    return np->height;
  }
}

int balance_factor(TNODE *np) {
  if (np == NULL) {
    return 0;
  } else {
    return height(np->left) - height(np->right);
  }
}

int is_avl(TNODE *root) {
  if (root == NULL) {
    return 1;
  }

  int left_height = height(root->left);
  int right_height = height(root->right);
  int balance = balance_factor(root);

  if (balance < -1 || balance > 1) {
    return 0; // Tree is not balanced
  }

  return is_avl(root->left) && is_avl(root->right);
}

TNODE *rotate_right(TNODE *y) {
  TNODE *x = y->left;
  TNODE *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

TNODE *rotate_left(TNODE *x) {
  TNODE *y = x->right;
  TNODE *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

void insert(TNODE **rootp, char *name, float score) {
  TNODE *np = (TNODE *)malloc(sizeof(TNODE));
  if (np == NULL) {
    return;
  }

  strcpy(np->data.name, name);
  np->data.score = score;
  np->height = 1;
  np->left = NULL;
  np->right = NULL;

  if (*rootp == NULL) {
    *rootp = np;
    return;
  }

  TNODE *root = *rootp;
  if (strcmp(name, root->data.name) < 0) {
    insert(&(root->left), name, score);
  } else if (strcmp(name, root->data.name) > 0) {
    insert(&(root->right), name, score);
  } else {
    return; // Node with the same name already exists, do nothing
  }

  root->height = max(height(root->left), height(root->right)) + 1;

  int balance = balance_factor(root);

  // Rebalance if the node is unbalanced
  if (balance > 1 && strcmp(name, root->left->data.name) < 0) {
    *rootp = rotate_right(root);
  } else if (balance < -1 && strcmp(name, root->right->data.name) > 0) {
    *rootp = rotate_left(root);
  } else if (balance > 1 && strcmp(name, root->left->data.name) > 0) {
    root->left = rotate_left(root->left);
    *rootp = rotate_right(root);
  } else if (balance < -1 && strcmp(name, root->right->data.name) < 0) {
    root->right = rotate_right(root->right);
    *rootp = rotate_left(root);
  }
}

void delete(TNODE **rootp, char *name) {
  TNODE *root = *rootp;

  if (root == NULL) {
    return;
  }

  if (strcmp(name, root->data.name) == 0) {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      *rootp = NULL;
    } else if (root->left != NULL && root->right == NULL) {
      TNODE *np = root->left;
      free(root);
      *rootp = np;
    } else if (root->left == NULL && root->right != NULL) {
      TNODE *np = root->right;
      free(root);
      *rootp = np;
    } else if (root->left != NULL && root->right != NULL) {
      TNODE *np = extract_smallest_node(&(root->right));
      np->left = root->left;
      np->right = root->right;
      free(root);
      *rootp = np;
    }
  } else {
    if (strcmp(name, root->data.name) < 0) {
      delete(&(root->left), name);
    } else {
      delete(&(root->right), name);
    }
  }

  if (*rootp == NULL) {
    return;
  }

  root = *rootp;

  root->height = max(height(root->left), height(root->right)) + 1;

  int balance = balance_factor(root);

  // Rebalance if the node is unbalanced
  if (balance > 1 && balance_factor(root->left) >= 0) {
    *rootp = rotate_right(root);
  } else if (balance > 1 && balance_factor(root->left) < 0) {
    root->left = rotate_left(root->left);
    *rootp = rotate_right(root);
  } else if (balance < -1 && balance_factor(root->right) <= 0) {
    *rootp = rotate_left(root);
  } else if (balance < -1 && balance_factor(root->right) > 0) {
    root->right = rotate_right(root->right);
    *rootp = rotate_left(root);
  }
}

TNODE *extract_smallest_node(TNODE **rootp) {
  TNODE *tnp = *rootp;
  TNODE *parent = NULL;
  if (tnp == NULL) {
    return NULL;
  } else {
    while (tnp->left) {
      parent = tnp;
      tnp = tnp->left;
    }
    if (parent == NULL) {
      *rootp = tnp->right;
    } else {
      parent->left = tnp->right;
    }
    tnp->left = NULL;
    tnp->right = NULL;
    return tnp;
  }
  
}

void clean_tree(TNODE **rootp) {
  if (*rootp == NULL) {
    return;
  }

  TNODE *root = *rootp;

  clean_tree(&(root->left));
  clean_tree(&(root->right));

  free(root);
  *rootp = NULL;
}

TNODE *search(TNODE *root, char *name) {
    if (root == NULL || strcmp(name, root->data.name) == 0)
        return root;

    if (strcmp(name, root->data.name) < 0)
        return search(root->left, name);
    else
        return search(root->right, name);
}

