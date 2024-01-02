/*
-------------------------------------------------------
Project:  cp264oc-a10q3
Author:   Arsalan Khan
Version:  2023-07-28
-------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "algorithm.h"

EDGELIST *mst_prim(GRAPH *g, int start) {
    if (g == NULL)
        return NULL;

    int i, heapindex, u, n = g->order;
    int T[n], parent[n];
    for (i = 0; i < n; i++) {
        T[i] = 0;
        parent[i] = -1;
    }

    HNODE hn;
    HEAP *h = new_heap(4);

    // set the first node of the current tree T from start
    T[start] = 1;

    // for each neighbor, add the corresponding heap node into the heap
    ADJNODE *temp = g->nodes[start]->neighbor;
    while (temp) {
        hn.key = temp->weight;
        hn.data = temp->nid;
        insert(h, hn);
        parent[temp->nid] = start;
        temp = temp->next;
    }

    // create an EDGELIST object to hold MST
    EDGELIST *mst = new_edgelist();

    // the main loop of Prim's algorithm
    while (h->size > 0) {
        hn = extract_min(h); // get the minimum node, time
        i = hn.data;
        T[i] = 1; // add i to the current tree
        add_edge_end(mst, parent[i], i, hn.key); // add to MST

        // update the keys of neighbors of the newly added node
        temp = g->nodes[i]->neighbor;
        while (temp) {
            heapindex = find_data_index(h, temp->nid);
            if (heapindex >= 0) {
                if (T[temp->nid] == 0 && temp->weight < h->hna[heapindex].key) {
                    change_key(h, heapindex, temp->weight);
                    parent[temp->nid] = i;
                }
            } else {
                if (T[temp->nid] == 0) {
                    hn.key = temp->weight;
                    hn.data = temp->nid;
                    insert(h, hn);
                    parent[temp->nid] = i;
                }
            }
            temp = temp->next;
        }
    }

    return mst;
}

EDGELIST *spt_dijkstra(GRAPH *g, int start) {
    if (!g)
        return NULL;

    EDGELIST *spt = new_edgelist();
    int i, heapindex, u, n = g->order;
    int T[n], parent[n], label[n];
    HNODE hn;
    for (i = 0; i < n; i++) {
        T[i] = 0;
        label[i] = 9999;
    }

    HEAP *h = new_heap(4);
    ADJNODE *temp = g->nodes[start]->neighbor;
    label[start] = 0;
    T[start] = 1;

    while (temp) {
        hn.key = temp->weight + label[start];
        hn.data = temp->nid;
        insert(h, hn);
        parent[temp->nid] = start;
        temp = temp->next;
    }

    while (h->size > 0) {
        hn = extract_min(h);
        u = hn.data;
        T[u] = 1;
        label[u] = hn.key;
        add_edge_end(spt, parent[u], u, label[u] - label[parent[u]]);
        // label[u] - label[parent[u]] is the weight of the newly added edge

        temp = g->nodes[u]->neighbor;
        while (temp) {
            heapindex = find_data_index(h, temp->nid);
            if (heapindex >= 0) {
                if (T[temp->nid] == 0 && temp->weight + label[u] < h->hna[heapindex].key) {
                    change_key(h, heapindex, temp->weight + label[u]);
                    parent[temp->nid] = u;
                }
            } else {
                if (T[temp->nid] == 0) {
                    hn.key = temp->weight + label[u];
                    hn.data = temp->nid;
                    insert(h, hn);
                    parent[temp->nid] = u;
                }
            }
            temp = temp->next;
        }
    }

    return spt;
}

EDGELIST *sp_dijkstra(GRAPH *g, int start, int end) {
    if (!g)
        return NULL;

    int heapindex, u;
    EDGELIST *spt = new_edgelist();
    int n = g->order;
    int T[n], parent[n], label[n];
    HNODE hn;

    for (int i = 0; i < n; i++) {
        T[i] = 0;
        label[i] = 9999;
    }

    HEAP *h = new_heap(4);
    ADJNODE *temp = g->nodes[start]->neighbor;
    label[start] = 0;
    T[start] = 1;

    while (temp) {
        hn.key = temp->weight + label[start];
        hn.data = temp->nid;
        insert(h, hn);
        parent[temp->nid] = start;
        temp = temp->next;
    }

    while (h->size > 0) {
        hn = extract_min(h);
        u = hn.data;
        T[u] = 1;
        label[u] = hn.key;

        if (u == end)
            break;

        temp = g->nodes[u]->neighbor;
        while (temp) {
            heapindex = find_data_index(h, temp->nid);
            if (heapindex >= 0) {
                if (T[temp->nid] == 0 && temp->weight + label[u] < h->hna[heapindex].key) {
                    change_key(h, heapindex, temp->weight + label[u]);
                    parent[temp->nid] = u;
                }
            } else {
                if (T[temp->nid] == 0) {
                    hn.key = temp->weight + label[u];
                    hn.data = temp->nid;
                    insert(h, hn);
                    parent[temp->nid] = u;
                }
            }
            temp = temp->next;
        }
    }

    EDGELIST *sp = new_edgelist();
    int i = end;

    while (1) {
        if (i == start)
            break;

        add_edge_start(sp, parent[i], i, label[i] - label[parent[i]]);
        i = parent[i];
    }

    return sp;
}
