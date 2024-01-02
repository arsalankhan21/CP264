/*--------------------------------------------------
Project: cp264oc-a5q1
File:    myrecord_sllist.c
Author:  Arsalan Khan
Version: 2023-06-17
--------------------------------------------------
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_sllist.h"


NODE *sll_search(SLL *sllp, char *name) {
  NODE *np = sllp->start; // start from the first node

  while (np != NULL) { // traverse the list
    if (strcmp(np->data.name, name) == 0) { // found the node if the name matches return the node pointer
      return np;
    }
    np = np->next; // move to the next node
  }
  return NULL; // return NULL if not found

}

void sll_insert(SLL *sllp, char *name, float score) {
NODE* np = (NODE *) malloc(sizeof(NODE)); // create and set the node
strcpy(np->data.name, name);
np->data.score = score;
np->next = NULL;

NODE *prev = NULL, *p = sllp->start;
while (p != NULL) {
    if (strcmp(p->data.name, name) >= 0) {
        break;
    } else {
        prev = p;
        p = p->next;
    }
}

if (prev == NULL) {
    sllp->start = np; // insert at the beginning
    np->next = p;
} else {
    prev->next = np; // insert between prev and p
    np->next = p;
}
sllp->length++; // increment the length of the list

}

int sll_delete(SLL *sllp, char *name) {
    NODE *prev = NULL;
    NODE *current = sllp->start;

    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            if (prev == NULL) {
                sllp->start = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            sllp->length--;
            return 1; // Deletion successful
        }
        prev = current;
        current = current->next;
    }

    return 0; // Node with the given name not found
}


void sll_clean(SLL *sllp) {
    NODE *current = sllp->start;
    NODE *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    sllp->start = NULL; // Reset the start of the list
    sllp->length = 0; // Reset the length of the list

}
