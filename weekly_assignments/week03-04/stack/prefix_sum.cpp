#include <iostream>

#include "prefix_sum.h"

bool non_neg_prefix_sum(int arr[], int length){


    //checking if the prefix sum is positive/zero or not
    bool negative_found = false;

    int sum = 0;
    for(int i = 0; i < length; i++){
        sum += arr[i];
        if (sum < 0){
            negative_found = true;
            break;
        }
    }
    return !(negative_found);
}
