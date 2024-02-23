#include "fisher_yates.h"
#include "prefix_sum.h"
#include <iostream>

using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print_array(int arr[], const int length){
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fisher_yates(int arr[], const int length){
    for(int i = length - 1; i >= 0; i--){
        int rand_int = i;
        while (rand_int == i){
            rand_int = rand() % length;
        }
        swap(arr[rand_int], arr[i]);
    }
}

double thousand_instances(int arr[], const int length){
    double i = 0;
    double success = 0;

    while( i < 5000 && length > 0){
        fisher_yates(arr, length);
        if (non_neg_prefix_sum(arr, length) || non_pos_prefix_sum(arr, length)){
            success++;
        }
        i++;
    }
    if (length > 0){
        cout << success/i << endl;
        return (success/i);
    }
    else{
        return 0;
    }
}