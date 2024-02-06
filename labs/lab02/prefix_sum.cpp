#include <iostream>

#include "prefix_sum.h"


bool value_check(int arr[], int length){
    bool stat = false;
    for (int i = 0; i < length; i++){
        if ((arr[i] > 1) || (arr[i] < -1)){
            stat = true;
        } 
    }
    return stat;
}

bool non_neg_prefix_sum(int arr[], int length){
    //checking if there are values other than -1 or 0 or 1
    bool arr_check = value_check(arr, length);
    if (arr_check == true || length == 0){
        return false;
    }

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

bool non_pos_prefix_sum(int arr[], int length){
    //checking if there are values other than -1 or 0 or 1
    bool arr_check = value_check(arr, length);
    if (arr_check == true || length == 0){
        return false;
    }

    //checking if the prefix sum is negative/zero or not
    bool positive_found = false;

    int sum = 0;
    for(int i = 0; i < length; i++){
        sum += arr[i];
        if (sum > 0){
            positive_found = true;
            break;
        }
    }
    return !(positive_found);
}