#Steps

#Explanation: The algorithm for barbell graphs examines how nodes are connected within the graph. It starts by setting up matrices to represent these connections, then goes through pairs of nodes, checking if there are different lengths of paths between them. Based on these checks, it updates the matrices to reflect the graph's connectivity. This process repeats until the algorithm has analyzed all possible connections. Ultimately, it produces matrices that summarize how nodes are reachable from one another in the graph.


1. download lab05 folder
2. thorugh the terminal cd into lab05
3. to run the main file enter g++ reading_all_three_files.cpp ints_read_matrix.cpp ints_read_vector.cpp ints_write.cpp expensive_diagraph.cpp into terminal
4. to run the unit tests, enter 
            a. g++ unit_tests_expensivediagraph.cpp expensive_diagraph.cpp  and then ./a.out into the terminal
            b. g++ unit_tests_ints_read_vector.cpp ints_read_vector.cpp and then ./a.out
            c. g++ ints_read_matrix.cpp unit_tests_ints_read_matrix.cpp ints_read_vector.cpp and then ./a.out