#include <iostream>
#include <vector>
#include "lambda.h"

using namespace std;

int turn_pos(int &val){
    if (val < 0){
        val = 0 - val;
    }

    return val;
}

bool perfect_num(int limit, int num){

    turn_pos(num);

    if (limit == num){
        limit = limit - 1;
    }

    int sum = 0;
    for (int i = 1; i <= limit; i++){
        
        if (num % i == 0){
            sum = sum + i;
        }
    }
    
    return num == sum;
}

bool perf_vector(vector<int> the_vector){
    for (int element : the_vector){
        turn_pos(element);
        bool val = perfect_num(element - 1, element);
        if (val == 0){
            return 0;
        }
    }
    return 1;
}