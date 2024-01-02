JobID: cp264oc-a10-lab10
Name: Arsalan Khan
ID: 210862640

Statement: I claim that the enclosed submission is my individual work.

Fill in the self-evaluation in the following evaluation grid.
Symbols:  A - Assignment, Q - Question, T - Task
Field format: [self-evaluation/total marks/marker's evaluation]

For example, you put your self-evaluation, say 2, like [2/2/*]. 
If markers give different evaluation value, say 1, it will show 
[2/2/1] in the marking report. 

Grade_Item_ID [self-evaluation/total/marker-evaluation] Description

Lab10

T1 Graph data structure and operations
T1.1 [4/4/*] Read & test graph data structure

T2 Minimum spanning tree
T2.1 [2/2/*] Read and test Kruskal algorithm 
T2.2 [2/2/*] Read and test Prim algorithm    

T3 Shortest path problem
T3.1 [2/2/*] Read and test Dijkstra algorithm

A10

Q1 Edge list graph data structure
Q1.1 [3/3/*] new_edgelist()                          
Q1.2 [3/3/*] add_edge_start(), add_edge_end()        
Q1.3 [3/3/*] weight_edgelist()                       

Q2 Adjacency list graph data structure
Q2.1 [3/3/*] new_graph()                             
Q2.2 [3/3/*] add_edge()                              
Q2.3 [2/3/*] bf_traverse()                           
Q2.4 [2/3/*] df_traverse()                           

Q3 Graph algorithms
Q3.1 [3/3/*] mst_prim()                              
Q3.2 [3/3/*] spt_dijkstra()                          
Q3.3 [3/3/*] sp_dijkstra()                           

Total: [38/40/*]

Q1 output:
PS C:\Users\arsal\OneDrive\Desktop\cp264\a10> gcc edgelist.c edgelist_main.c -o q1 
PS C:\Users\arsal\OneDrive\Desktop\cp264\a10> ./q1
display_edgelist():
size:4
(from to weight):(0 2 3) (2 1 4) (1 3 9) (1 4 11) 

weight:27
PS C:\Users\arsal\OneDrive\Desktop\cp264\a10> 


Q2 output:
PS C:\Users\arsal\OneDrive\Desktop\cp264\a10> gcc queue_stack.c graph.c graph_main.c -o q2
PS C:\Users\arsal\OneDrive\Desktop\cp264\a10> ./q2
display_graph():
order:5
size:12
from:(to weight)
0:(1 7) (2 3)
1:(0 7) (2 4) (3 9) (4 11)
2:(0 3) (1 4) (3 10)
3:(2 10) (1 9)
4:(1 11)

display_bforder():
BFOrder: 0 1 2 3 4
display_dforder():
DFOrder: 0 1 2 3 4
PS C:\Users\arsal\OneDrive\Desktop\cp264\a10>

Q3 output:
PS C:\Users\arsal\OneDrive\Desktop\cp264\a10> gcc queue_stack.c heap.c edgelist.c graph.c algorithm.c algorithm_main.c -o q3
PS C:\Users\arsal\OneDrive\Desktop\cp264\a10> ./q3                                                                        
display_graph(g):
order:5
size:12
from:(to weight)
0:(1 7) (2 3) 
1:(0 7) (2 4) (3 9) (4 11) 
2:(0 3) (1 4) (3 10) 
3:(2 10) (1 9) 
4:(1 11) 


mst_prim(g, 0):
size:4
(from to weight):(0 2 3) (2 1 4) (1 3 9) (1 4 11)

mst weight:27

spt_dijkstra():
size:4
(from to weight):(0 2 3) (0 1 7) (2 3 10) (1 4 11)

spt weight:31

sp_dijkstra(g 0 4):
size:2
(from to weight):(0 1 7) (1 4 11)

sp length:18
PS C:\Users\arsal\OneDrive\Desktop\cp264\a10> 

