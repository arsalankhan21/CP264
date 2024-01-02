/*
-------------------------------------------------------
Project:  cp264oc-a10q3
Author:   Arsalan Khan
Version:  2023-07-28
-------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"
#include "graph.h"

GRAPH *new_graph(int order) {
    GRAPH *g = (GRAPH *)malloc(sizeof(GRAPH));
    if (g) {
        g->order = order;
        g->size = 0;
        g->nodes = (GNODE **)malloc(order * sizeof(GNODE *));
        for (int i = 0; i < order; i++) {
            g->nodes[i] = (GNODE *)malloc(sizeof(GNODE));
            g->nodes[i]->nid = i;
            g->nodes[i]->neighbor = NULL;
        }
    }
    return g;
}

void add_edge(GRAPH *g, int from, int to, int weight) {
    ADJNODE *newAdjNode = (ADJNODE *)malloc(sizeof(ADJNODE));
    newAdjNode->nid = to;
    newAdjNode->weight = weight;
    newAdjNode->next = NULL;

    ADJNODE *p = g->nodes[from]->neighbor;
    ADJNODE *prev = NULL;
    while (p != NULL && p->nid != to) {
        prev = p;
        p = p->next;
    }

    if (p != NULL) {
        p->weight = weight;
    } else {
        if (prev == NULL) {
            g->nodes[from]->neighbor = newAdjNode;
        } else {
            prev->next = newAdjNode;
        }
        g->size++;
    }
}

void display_bforder(GRAPH *g, int start) {
    if (g == NULL || start >= g->order) {
        printf("Invalid input.\n");
        return;
    }

    int visited[g->order];
    for (int i = 0; i < g->order; i++) {
        visited[i] = 0;
    }

    QUEUE queue;
    queue.front = queue.rear = NULL;

    enqueue(&queue, g->nodes[start]);
    visited[start] = 1;

    printf("\nBFOrder:");
    while (queue.front != NULL) {
        GNODE *currNode = (GNODE *)dequeue(&queue);
        printf(" %d", currNode->nid);

        ADJNODE *p = currNode->neighbor;
        while (p != NULL) {
            if (!visited[p->nid]) {
                enqueue(&queue, g->nodes[p->nid]);
                visited[p->nid] = 1;
            }
            p = p->next;
        }
    }
}

void dfs(GRAPH *g, int start, int *visited) {
    visited[start] = 1;
    printf(" %d", g->nodes[start]->nid);

    ADJNODE *p = g->nodes[start]->neighbor;
    while (p != NULL) {
        if (!visited[p->nid]) {
            dfs(g, p->nid, visited);
        }
        p = p->next;
    }
}

void display_dforder(GRAPH *g, int start) {
    if (g == NULL || start >= g->order) {
        printf("Invalid input.\n");
        return;
    }

    int visited[g->order];
    for (int i = 0; i < g->order; i++) {
        visited[i] = 0;
    }

    printf("\nDFOrder:");
    dfs(g, start, visited);
}

int get_weight(GRAPH *g, int from, int to) {
    ADJNODE *p = g->nodes[from]->neighbor;
    while (p != NULL) {
        if (p->nid == to) {
            return p->weight;
        }
        p = p->next;
    }
    return INFINITY;
}

void clean_graph(GRAPH **gp) {
    GRAPH *g = *gp;
    if (g) {
        for (int i = 0; i < g->order; i++) {
            ADJNODE *p = g->nodes[i]->neighbor;
            while (p != NULL) {
                ADJNODE *temp = p;
                p = p->next;
                free(temp);
            }
            free(g->nodes[i]);
        }
        free(g->nodes);
        free(g);
        *gp = NULL;
    }
}

void display_graph(GRAPH *g) {
    if (g == NULL) {
        printf("Empty graph.\n");
        return;
    }
    printf("order:%d\n", g->order);
    printf("size:%d\n", g->size);
    printf("from:(to weight)\n");
    for (int i = 0; i < g->order; i++) {
        printf("%d:", g->nodes[i]->nid);
        ADJNODE *p = g->nodes[i]->neighbor;
        while (p != NULL) {
            printf("(%d %d) ", p->nid, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}
