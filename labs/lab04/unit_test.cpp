#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "gen_permutations.h"
#include "prefix_sum.h"

TEST_CASE("Test compute_permutation_of_array") {
    // Test if function shuffles the array
    int arr[] = {1, -1, 1, -1, 1, -1}; 
    int arr_copy[] = {1, -1, 1, -1, 1, -1}; // Copy of the original array
    compute_permutation_of_array(arr, 6); // Apply function to array
    CHECK(memcmp(arr, arr_copy, sizeof(arr)) != 0); // Assert that the array has changed
}

TEST_CASE("Test get_lowest_prefix_sum_val") {
    // Test if function returns the lowest prefix sum correctly
    int arr[] = {1, -1, 1, -1, -1, 1, -1}; 
    int lowest_sum = get_lowest_prefix_sum_val(arr, 7);
    CHECK(lowest_sum == -1); // Assert that the lowest sum is -1
}

TEST_CASE("Test index_of_lowest_prefix_sum_element - 1") {
    // Test if function returns the index of the lowest prefix sum element correctly
    int arr[] = {1, -1, 1, -1, 1, -1}; 
    int index = index_of_lowest_prefix_sum_element(arr, 6);
    CHECK(index == 1); // Assert that the index of the lowest sum element is 1
}

TEST_CASE("Test index_of_lowest_prefix_sum_element - 2") {
    // Test if function returns the index of the lowest prefix sum element correctly
    int arr[] = {1, -1, 1, -1, -1, 1, -1}; 
    int index = index_of_lowest_prefix_sum_element(arr, 5);
    CHECK(index == 4); // Assert that the index of the lowest sum element is 1
}

TEST_CASE("1 -> Test switch_p1_and_p2_and_drop") {
    // Test if function switches P1 and P2 correctly
    int arr[] = {1, -1, 1, -1, 1, -1};
    int* new_arr = switch_p1_and_p2_and_drop(arr, 6, 2); // Example call
    CHECK(new_arr[0] == 1);
    CHECK(new_arr[1] == -1);
    CHECK(new_arr[2] == 1);
    CHECK(new_arr[3] == -1);
    CHECK(new_arr[4] == 1);
    CHECK(new_arr[5] == -1);
    CHECK_EQ(non_neg_prefix_sum(new_arr, 6),true);
    delete[] new_arr; // Don't forget to deallocate memory
}

TEST_CASE("2 -> Test switch_p1_and_p2_and_drop") {
    // Test if function switches P1 and P2 correctly
    int arr[] = {1, -1, 1, -1, -1, 1, -1};
    int index = index_of_lowest_prefix_sum_element(arr, 7); // Index of lowest prefix sum element
    int* new_arr = switch_p1_and_p2_and_drop(arr, 7, index); // Example call
    CHECK(new_arr[0] == -1);
    CHECK(new_arr[1] == 1);
    CHECK(new_arr[2] == -1);
    CHECK(new_arr[3] == 1);
    CHECK(new_arr[4] == -1);
    CHECK(new_arr[5] == 1);
    CHECK(new_arr[6] == -1); // The last element should not change
    delete[] new_arr; // Don't forget to deallocate memory
}

TEST_CASE("3 -> Test switch_p1_and_p2_and_drop") {
    // Test if function switches P1 and P2 correctly
    int arr[] = {1, -1, -1, -1, 1, -1, 1};
    int index = index_of_lowest_prefix_sum_element(arr, 7); // Index of lowest prefix sum element
    int* new_arr = switch_p1_and_p2_and_drop(arr, 7, index); // Example call
    CHECK(new_arr[0] == -1);
    CHECK(new_arr[1] == 1);
    CHECK(new_arr[2] == -1);
    CHECK(new_arr[3] == 1);
    CHECK(new_arr[4] == 1);
    CHECK(new_arr[5] == -1);
    CHECK(new_arr[6] == -1);
    delete[] new_arr; // Don't forget to deallocate memory
}

TEST_CASE("4 -> Test switch_p1_and_p2_and_drop") {
    // Test if function switches P1 and P2 correctly
    int arr[] = {-1, 1, -1, 1, -1, 1, -1};
    int index = index_of_lowest_prefix_sum_element(arr, 7); // Index of lowest prefix sum element
    int* new_arr = switch_p1_and_p2_and_drop(arr, 7, index); // Example call
    // The expected array after the operation: {-1, 1, -1, 1, -1, 1, -1}
    CHECK(new_arr[0] == -1);
    CHECK(new_arr[1] == 1);
    CHECK(new_arr[2] == -1);
    CHECK(new_arr[3] == 1);
    CHECK(new_arr[4] == -1);
    CHECK(new_arr[5] == 1);
    CHECK(new_arr[6] == -1);
    delete[] new_arr; // Don't forget to deallocate memory
}




TEST_CASE("Test switch_p1_and_p2_and_drop_CustomArray") {
    // Test if function switches P1 and P2 correctly for a custom array
    int arr[] = {1, -1, 1, -1, -1, 1, 1}; // Custom array
    int index = index_of_lowest_prefix_sum_element(arr, 7); // Index of lowest prefix sum element
    int* new_arr = switch_p1_and_p2_and_drop(arr, 7, index); // Call the function
    // The expected array after the operation: {1, 1, 1, -1, 1, -1}
    CHECK(new_arr[0] == -1);
    CHECK(new_arr[1] == 1);
    CHECK(new_arr[2] == 1);
    CHECK(new_arr[3] == 1);
    CHECK(new_arr[4] == -1);
    CHECK(new_arr[5] == 1);
    CHECK_EQ(non_neg_prefix_sum(new_arr, 6), false); // Check if prefix sum is non-negative
    delete[] new_arr; // Deallocate memory
}




TEST_CASE("EDGE CASE -> Test switch_p1_and_p2_and_drop_empty_array") {
    // Test if function handles empty arrays correctly
    int* arr = nullptr; // Empty array
    int* new_arr = switch_p1_and_p2_and_drop(arr, 0, 2); // Attempt to switch elements in an empty array
    int index = index_of_lowest_prefix_sum_element(arr, 0);
    int lowest = get_lowest_prefix_sum_val(arr, 0);
    CHECK(lowest == -1);
    CHECK(index == -1);
    CHECK(new_arr == nullptr); // Assert that nullptr is returned for empty array
}
