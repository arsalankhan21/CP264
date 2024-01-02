
/*
-------------------------------------------------------
Project:  cp264oc-a10q3
Author:   Arsalan Khan
Version:  2023-07-28
-------------------------------------------------------
*/
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "edgelist.h"
#include "graph.h"

EDGELIST *mst_prim(GRAPH *g, int start);
EDGELIST *spt_dijkstra(GRAPH *g, int start);
EDGELIST *sp_dijkstra(GRAPH *g, int start, int end);

#endif