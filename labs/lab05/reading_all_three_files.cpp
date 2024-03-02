#include <iostream>
#include <istream> 
#include <fstream>
#include <algorithm> 
#include <iterator>
#include <string>
#include <vector>

#include "ints_read_matrix.h"
#include "ints_write.h"
#include "expensive_diagraph.h"

using namespace std;  

int main(){
    string files[] = {"graph_0.txt", "graph_1.txt", "graph_m1.txt"};

    ifstream in_file_0, in_file_1, in_file_m1;
    in_file_0.open(files[0]);
    in_file_1.open(files[1]);
    in_file_m1.open(files[2]);

    vector<vector<int>> zero_matrix, plus_one_matrix, minus_one_matrix;

    zero_matrix = ints_read_matrix(in_file_0);
    for (auto my_vector:zero_matrix){
        cout << my_vector << endl;
    }
    cout << "---------------------------------------  " << endl;


    
    plus_one_matrix = ints_read_matrix(in_file_1);
    for (auto my_vector:plus_one_matrix){
        cout << my_vector << endl;
    }
    cout << "---------------------------------------  " << endl;


    
    minus_one_matrix = ints_read_matrix(in_file_m1);
    for (auto my_vector:minus_one_matrix){
        cout << my_vector << endl;
    }
    cout << endl;
    cout << " - the end of pt 1-" << endl;
    cout << endl;

    in_file_0.close();
    in_file_1.close();
    in_file_m1.close();

    expensiveDigraphExactPaths(minus_one_matrix, zero_matrix, plus_one_matrix);

    for (auto my_vector:zero_matrix){
        cout << my_vector << endl;
    }
    cout << "---------------------------------------  " << endl;


    
    for (auto my_vector:plus_one_matrix){
        cout << my_vector << endl;
    }
    cout << "---------------------------------------  " << endl;



    for (auto my_vector:minus_one_matrix){
        cout << my_vector << endl;
    }
    cout << "---------------------------------------  " << endl;

}