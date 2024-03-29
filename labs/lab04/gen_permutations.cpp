#include <cstdlib>

#include "gen_permutations.h"
#include "prefix_sum.h"
#include "fisher_yates.h"

using namespace std;

void compute_permutation_of_array(int arr[], int length){
    fisher_yates(arr, length);
}

int get_lowest_prefix_sum_val(int arr[], int length){
    
    if (length == 0){
        return -1;
    }

    int sum{0}, lowest_sum{0};

    for (int i = 0; i < length; i++){
        sum += arr[i];
        if (sum < lowest_sum){
            lowest_sum = sum;
        }
    }

    return lowest_sum;
}

int index_of_lowest_prefix_sum_element(int arr[], int length){
    
    if (length == 0){
        return -1;
    }

    int lowest_prefix_sum = get_lowest_prefix_sum_val(arr, length);

    int sum{0}, index_of_first_lowest{0};

    for(int i = 0; i < length; i++){
        sum += arr[i];
        if (sum == lowest_prefix_sum){
            index_of_first_lowest = i;
            break;
        }
    }

    return index_of_first_lowest;
}
int* switch_p1_and_p2_and_drop(int arr[], int length, int index_of_first_lowest) {
    if (length == 0 || index_of_first_lowest >= length - 1) {
        return nullptr; // Return nullptr for invalid inputs
    }

    int* new_arr = new int[length];

    // Copy P2 to the beginning of new_arr
    for (int i = 0; i < length - index_of_first_lowest - 1; i++) {
        new_arr[i] = arr[index_of_first_lowest + i + 1];
    }

    // Drop the last element (-1) from P1 and copy it to the end of new_arr
    for (int j = length - index_of_first_lowest - 1; j < length - 1; j++) {
        new_arr[j] = arr[j - (length - index_of_first_lowest) + 1];
    }

    return new_arr;
}


