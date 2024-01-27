#include <iostream>
#include "prefix_sum.h"

int main() {
    int arr1[] = {};
    int arr2[] = { 1, -1};
    int arr3[] = { 1, -1,-1};
    int arr4[] = { 1, -1, 1, -1};
    int arr5[] = { 1, 2, 3, 4, 5};

    int sum1 = prefix_sum(arr1, sizeof(arr1)/sizeof(arr1[0]));

    bool non_neg2 = non_neg_prefix_sum(arr2, sizeof(arr2)/sizeof(arr2[0]));

    bool non_pos5 = non_pos_prefix_sum(arr5, sizeof(arr5)/sizeof(arr5[0]));

    std::cout << sum1 << std::endl;
    std::cout << non_neg2 << std::endl;
    std::cout << non_pos5 << std::endl;

    return 0;
}