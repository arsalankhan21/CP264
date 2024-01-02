/*--------------------------------------------------
Project: cp264oc-a5q2
File:    dllist.c
Author:  Arsalan Khan
Version: 2023-06-17
--------------------------------------------------
*/
 
#include <stdio.h>
#include <stdlib.h> 
#include "dllist.h"

NODE *new_node(char data) {
    NODE *np = (NODE *)malloc(sizeof(NODE));
    np->data = data;
    np->prev = NULL;
    np->next = NULL;
    return np;
}

void dll_insert_start(DLL *dllp, NODE *np) {
    if (dllp->start == NULL) {
        dllp->start = np;
        dllp->end = np;
    } else {
        np->next = dllp->start;
        dllp->start->prev = np;
        dllp->start = np;
    }
    dllp->length++;
}

void dll_insert_end(DLL *dllp, NODE *np) {
    if (dllp->end == NULL) {
        dllp->start = np;
        dllp->end = np;
    } else {
        np->prev = dllp->end;
        dllp->end->next = np;
        dllp->end = np;
    }
    dllp->length++;
}

void dll_delete_start(DLL *dllp) {
    if (dllp->start != NULL) {
        NODE *temp = dllp->start;
        dllp->start = dllp->start->next;
        if (dllp->start == NULL) {
            dllp->end = NULL;
        } else {
            dllp->start->prev = NULL;
        }
        free(temp);
        dllp->length--;
    }
}

void dll_delete_end(DLL *dllp) {
    if (dllp->end != NULL) {
        NODE *temp = dllp->end;
        dllp->end = dllp->end->prev;
        if (dllp->end == NULL) {
            dllp->start = NULL;
        } else {
            dllp->end->next = NULL;
        }
        free(temp);
        dllp->length--;
    }
}

void dll_clean(DLL *dllp) {
    NODE *current = dllp->start;
    while (current != NULL) {
        NODE *temp = current;
        current = current->next;
        free(temp);
    }
    dllp->start = NULL;
    dllp->end = NULL;
    dllp->length = 0;
}
