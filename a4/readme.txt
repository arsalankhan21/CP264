JobID: cp264oc-a4-lab4
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

Lab4

T1 Induction proof
T1.1 [2/2/*] Write induction proof           

T2 Big-O notation
T2.1 [2/2/*] Prove Big-O statements          

T3 Build tool for complex C programs
T3.1 [0/0/*] Build all by one command        
T3.2 [0/0/*] Build incrementally             
T3.3 [1/1/*] Build static library            
T3.4 [2/2/*] Build using make                

T4 Sorting algorithms and analysis
T4.1 [2/2/*] Read and test sorting examples  
T4.2 [1/1/*] Merge sorting complexity proof  

A4

Q1 Sorting algorithms
Q1.1 [0/6/*] select_sort()                           
Q1.2 [0/6/*] quick_sort()                            

Q2 Record data processing
Q2.1 [0/1/*] RECORD type                             
Q2.2 [0/1/*] STATS type                              
Q2.3 [0/1/*] GRADE type                              
Q2.4 [0/3/*] grade()                                 
Q2.5 [0/3/*] import_data()                           
Q2.6 [0/6/*] process_data()                          
Q2.7 [0/3/*] report_data()                           

Total: [0/40/*]

Q1 output:

PS C:\Users\arsal\OneDrive\Desktop\cp264\a4> gcc mysort.c mysort_main.c -o mysort 
PS C:\Users\arsal\OneDrive\Desktop\cp264\a4> ./mysort
Algorithm correctness testing:
given data d[]:3,1,4,5,2,7,6,9,8
is_sorted(a):0
after select_sort(a):1,2,3,4,5,6,7,8,9
after select_sort(a) is_sorted(a):1
after quick_sort(a):1,2,3,4,5,6,7,8,9
after quick_sort(a) is_sorted(a):1
PS C:\Users\arsal\OneDrive\Desktop\cp264\a4> 

Q2 output:

PS C:\Users\arsal\OneDrive\Desktop\cp264\a4> gcc mysort.c myrecord.c myrecord_main.c -o q2 
PS C:\Users\arsal\OneDrive\Desktop\cp264\a4> ./q2
Stats     value
count     20.0  
mean      77.9  
stddev    13.5  
median    79.1  

name      score %     grade
Myrie     76.7  77    B+    
Hatch     66.5  67    C+    
Costa     45.1  45    F     
Dabu      74.4  74    B     
Sun       67.7  68    C+
Chabot    80.4  80    A-
Giblett   59.1  59    D+
Suglio    85.7  86    A
Smith     60.1  60    C-
Bodnar    93.6  94    A+
Allison   67.7  68    C+
Koreck    77.4  77    B+
Parr      92.5  93    A+
Lamont    98.1  98    A+
Peters    82.3  82    A-
Wang      98.1  98    A+
Eccles    77.8  78    B+
Pereira   80.3  80    A-
He        85.7  86    A
Ali       88.0  88    A
PS C:\Users\arsal\OneDrive\Desktop\cp264\a4> 



