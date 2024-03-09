#include <iostream>
#include "lambda.h"
#include <vector>

using namespace std;

int main(){
    //test 1:
    bool val = perfect_num(5, 6);
    cout << val << endl;
    
    //test 2:
    vector<int> the_vector = {28, 6};
    val = perf_vector(the_vector);
    cout << val << endl;

    return 0;
}
