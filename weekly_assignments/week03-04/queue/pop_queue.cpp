#include <iostream>
#include <queue>
#include <string>
#include "file_io.h"
#include "prefix_sum.h"

using namespace std;

int pop_queue(string file_name){
    queue<node> q = reading_file(file_name);

    int array_len = q.size();
    int array_for_prefix_sum[array_len];

    int i = 0;
    while(!q.empty()){
        array_for_prefix_sum[i++] = q.front().number;
        // cout << q.front().number << endl;
        q.pop();
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

    return q.size();
} 