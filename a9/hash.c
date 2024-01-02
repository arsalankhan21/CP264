/*--------------------------------------------------
Project: cp264oc-a9q2
Author:  Arsalan Khan 
Version: 2023-07-22
--------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int htsize;

int hash(char* key) {
  unsigned int hash = 0, i;
  for (i = 0; key[i] != '\0'; i++) {
    hash = 31 * hash + key[i];
  }
  return hash % htsize;
}

HSNODE *new_hashnode(char *key, int value) {
  HSNODE *newNode = (HSNODE *)malloc(sizeof(HSNODE));
  if (newNode == NULL) {
    perror("Memory allocation failed");
    return NULL;
  }
  strncpy(newNode->key, key, 10);
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

HASHTABLE *new_hashtable(int size) {
  HASHTABLE *ht = (HASHTABLE *)malloc(sizeof(HASHTABLE));
  if (ht == NULL) {
    perror("Memory allocation failed");
    return NULL;
  }
  ht->hna = (HSNODE **)malloc(sizeof(HSNODE *) * size);
  if (ht->hna == NULL) {
    free(ht);
    perror("Memory allocation failed");
    return NULL;
  }

  int i;
  for (i = 0; i < size; i++) {
    ht->hna[i] = NULL; // initialize to NULL
  }
  ht->size = size;
  ht->count = 0;
  return ht;
}

HSNODE *search(HASHTABLE *ht, char *key) {
  int i = hash(key); // compute the hash index of the key
  HSNODE *p = ht->hna[i]; // get the linked list of the hash value
  // search the linked list, if key is matched, return the node
  while (p != NULL) {
    if (strcmp(p->key, key) == 0) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

int insert(HASHTABLE *ht, HSNODE *np) {
  int i = hash(np->key);
  HSNODE *p = search(ht, np->key);
  if (p != NULL) {
    return 0; // Key already exists
  }

  np->next = ht->hna[i];
  ht->hna[i] = np;
  ht->count++;
  return 1;
}

int delete(HASHTABLE *ht, char *key) {
  int i = hash(key);
  HSNODE *prev = NULL;
  HSNODE *curr = ht->hna[i];

  while (curr != NULL) {
    if (strcmp(curr->key, key) == 0) {
      if (prev == NULL) {
        ht->hna[i] = curr->next; // Node to be deleted is the first in the list
      } else {
        prev->next = curr->next; // Node to be deleted is in the middle/end of the list
      }
      free(curr);
      ht->count--;
      return 1;
    }
    prev = curr;
    curr = curr->next;
  }
  return 0; // Key not found
}

void clean_hash(HASHTABLE **htp) {
  if (*htp == NULL) return;
  HASHTABLE *ht = *htp;
  HSNODE *p, *temp;
  int i;

  for (i = 0; i < ht->size; i++) {
    p = ht->hna[i];
    while (p != NULL) {
      temp = p;
      p = p->next;
      free(temp);
    }
    ht->hna[i] = NULL;
  }
  free(ht->hna);
  free(ht);
  *htp = NULL;
}
