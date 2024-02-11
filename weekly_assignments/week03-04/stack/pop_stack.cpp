#include <iostream>
#include <stack>
#include <string>
#include "file_io.h"
#include "prefix_sum.h"
 
using namespace std;

int pop_stack(string file_name){
    stack<node> s = reading_file(file_name);

    int array_len = s.size();
    int array_for_prefix_sum[array_len];

    int i = 0;
    while(!s.empty()){
        array_for_prefix_sum[i++] = s.top().number;
        s.pop();
    }

    try{
        
        if (non_neg_prefix_sum(array_for_prefix_sum, array_len)){
            cout << "non-neg" << endl;
        }
        else{
            throw string("neg");
        }
    }
    catch (string err_string){
        cout << err_string << endl;
        return -1;
    }

    return s.size();
}