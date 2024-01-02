/*
-------------------------------------------------------
Project:  cp264oc-a10q3
Author:   Arsalan Khan
Version:  2023-07-28
-------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include "edgelist.h"

EDGELIST *new_edgelist() {
    EDGELIST *g = (EDGELIST *)malloc(sizeof(EDGELIST));
    if (g) {
        g->size = 0;
        g->start = NULL;
        g->end = NULL;
    }
    return g;
}

void add_edge_end(EDGELIST *g, int from, int to, int weight) {
    EDGE *newEdge = (EDGE *)malloc(sizeof(EDGE));
    if (newEdge) {
        newEdge->from = from;
        newEdge->to = to;
        newEdge->weight = weight;
        newEdge->next = NULL;

        if (g->start == NULL) {
            g->start = newEdge;
            g->end = newEdge;
        } else {
            g->end->next = newEdge;
            g->end = newEdge;
        }
        g->size++;
    }
}

void add_edge_start(EDGELIST *g, int from, int to, int weight) {
    EDGE *newEdge = (EDGE *)malloc(sizeof(EDGE));
    if (newEdge) {
        newEdge->from = from;
        newEdge->to = to;
        newEdge->weight = weight;
        newEdge->next = g->start;
        g->start = newEdge;
        if (g->end == NULL) {
            g->end = newEdge;
        }
        g->size++;
    }
}

int weight_edgelist(EDGELIST *g) {
    if (g == NULL) {
        return 0;
    }

    int totalWeight = 0;
    EDGE *p = g->start;
    while (p) {
        totalWeight += p->weight;
        p = p->next;
    }
    return totalWeight;
}

void clean_edgelist(EDGELIST **gp) {
    EDGELIST *g = *gp;
    EDGE *temp, *p = g->start;
    while (p) {
        temp = p;
        p = p->next;
        free(temp);
    }
    free(g);
    *gp = NULL;
}

void display_edgelist(EDGELIST *g) {
    if (g == NULL) {
        printf("Empty edge list.\n");
        return;
    }
    printf("size:%d\n", g->size);
    printf("(from to weight):");
    EDGE *p = g->start;
    while (p) {
        printf("(%d %d %d) ", p->from, p->to, p->weight);
        p = p->next;
    }
    printf("\n");
}
