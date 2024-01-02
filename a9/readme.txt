JobID: cp264oc-a9-lab9
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

Lab9

T1 Hash tables
T1.1 [5/5/*] Read and test hash tables

T2 Heaps
T2.1 [5/5/*] Read and test Heaps

A9

Q1 Chained hash table
Q1.1 [3/3/*] new_node(), new_hashtable()             
Q1.2 [3/3/*] search()                                
Q1.3 [3/3/*] insert()                                
Q1.4 [3/3/*] delete()                                

Q2 Symbolic expression evaluation
Q2.1 [5/6/*] infix_to_postfix_symbol()               

Q3 Binary heap
Q3.1 [3/3/*] new_heap(),find_index_data()            
Q3.2 [3/3/*] insert()                                
Q3.3 [3/3/*] extract_min()                           
Q3.4 [3/3/*] change_key()                            

Total: [39/40/*]

q1 output:
PS C:\Users\arsal\OneDrive\Desktop\cp264\a9> gcc hash.c hash_main.c -o q1                                                 
PS C:\Users\arsal\OneDrive\Desktop\cp264\a9> ./q1                                                                         
      
hash table after insertions:
size:5
count:20
0:(s,18) (n,13) (i,8) (d,3) 
1:(t,19) (o,14) (j,9) (e,4) 
2:(p,15) (k,10) (f,5) (a,0) 
3:(q,16) (l,11) (g,6) (b,1) 
4:(r,17) (m,12) (h,7) (c,2) 
search(a):(a,0)
hash table after deletions:
size:5
count:10
0:(s,18) (n,13)
1:(t,19) (o,14) 
2:(p,15) (k,10)
3:(q,16) (l,11)
4:(r,17) (m,12)
search(b):NULL

PS C:\Users\arsal\OneDrive\Desktop\cp264\a9>


q2 output:
PS C:\Users\arsal\OneDrive\Desktop\cp264\a9> gcc common_queue_stack.c hash.c expression_symbol.c expression_symbol_main.c -o q2 
PS C:\Users\arsal\OneDrive\Desktop\cp264\a9> ./q2                                                                         
Symbolic expressions:
a=10
b=8
d=2
c=(a+b)*(a-b)
PS C:\Users\arsal\OneDrive\Desktop\cp264\a9> 

q3 output:
PS C:\Users\arsal\OneDrive\Desktop\cp264\a9> gcc heap.c heap_main.c -o q3                                                 
PS C:\Users\arsal\OneDrive\Desktop\cp264\a9> ./q3                                                                         
      
new heap:
size:0
capacity:4
(index,key,data):

heap after insertions:
size:10
capacity:16
(index,key,data):(0,4,10) (1,5,9) (2,8,6) (3,7,7) (4,6,8) (5,12,2) (6,9,5) (7,13,1) (8,10,4) (9,11,3)

(find_data_index(hp,6),key,data):(2,8,6)
change_key(hp,2,2):1
change_key(hp,2,2):(2,8,6)->(1,5,9)
size:10
capacity:16
(index,key,data):(0,2,6) (1,5,9) (2,4,10) (3,7,7) (4,6,8) (5,12,2) (6,9,5) (7,13,1) (8,10,4) (9,11,3) 

(find_data_index(hp,6),key,data):(0,2,6)
change_key(hp,0,8):1
change_key(hp,0,8):(0,2,6)->(1,5,9)
size:10
capacity:16
(index,key,data):(0,4,10) (1,5,9) (2,8,6) (3,7,7) (4,6,8) (5,12,2) (6,9,5) (7,13,1) (8,10,4) (9,11,3)

call extract_min 8 times:(4 10) (5 9) (6 8) (7 7) (8 6) (9 5) (10 4) (11 3) 
heap after extract_min operations:
size:2
capacity:16
(index,key,data):(0,12,2) (1,13,1)

PS C:\Users\arsal\OneDrive\Desktop\cp264\a9> 

