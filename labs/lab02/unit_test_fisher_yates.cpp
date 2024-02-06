#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "rand_array.h"
#include "fisher_yates.h"
#include "prefix_sum.h"

TEST_CASE("Testing createArray function") {
    SUBCASE("Test createArray with n = 5") {
        int n = 5;
        int* arr = createArray(n);

        // Check if the array is correctly initialized
        for (int i = 0; i < n; i++) {
            CHECK(arr[i] == 1);
        }
        for (int i = n; i < 2 * n; i++) {
            CHECK(arr[i] == -1);
        }

        // Clean up dynamically allocated memory
        delete[] arr;
    }

    SUBCASE("Test createArray with n = 0") {
        int n = 0;
        int* arr = createArray(n);

        // Check if the array is empty
        CHECK(arr == nullptr);

    }
}

TEST_CASE("Testing fisher_yates function") {
    // since the results cant be tested for void functions, I'm testing if they crash or not
    SUBCASE("Test fisher_yates with an array") {
        int arr[] = {1, 2, 3, 4, 5};
        int length = sizeof(arr) / sizeof(arr[0]);
        fisher_yates(arr, length);
    }
}

TEST_CASE("Testing non_neg_prefix_sum function") {
    SUBCASE("Test non_neg_prefix_sum with all positive values") {
        int arr[] = {1, 1, 1, 1};
        int length = sizeof(arr) / sizeof(arr[0]);
        CHECK(non_neg_prefix_sum(arr, length) == true);
    }

    SUBCASE("Test non_neg_prefix_sum with negative values") {
        int arr[] = {-1, -1, -1, -1};
        int length = sizeof(arr) / sizeof(arr[0]);
        CHECK(non_neg_prefix_sum(arr, length) == false);
    }

    SUBCASE("extra cases") {
        int arr[] = {1, -1, 1, -1};
        int length = sizeof(arr) / sizeof(arr[0]);
        CHECK(non_neg_prefix_sum(arr, length) == true);
    }

    SUBCASE("extra cases-2") {
        int arr[] = {0, -1, 0, 1};
        int length = sizeof(arr) / sizeof(arr[0]);
        CHECK(non_neg_prefix_sum(arr, length) == false);
    }
}

TEST_CASE("Testing non_pos_prefix_sum function") {
    SUBCASE("Test non_pos_prefix_sum with all negative values") {
        int arr[] = {-1, -1, -1, -1};
        int length = sizeof(arr) / sizeof(arr[0]);
        CHECK(non_pos_prefix_sum(arr, length) == true);
    }

    SUBCASE("Test non_pos_prefix_sum with positive values") {
        int arr[] = {1, 1, 1, 1};
        int length = sizeof(arr) / sizeof(arr[0]);
        CHECK(non_pos_prefix_sum(arr, length) == false);
    }

    SUBCASE("extra cases") {
        int arr[] = {0, -1, 1, -1};
        int length = sizeof(arr) / sizeof(arr[0]);
        CHECK(non_pos_prefix_sum(arr, length) == true);
    }

    SUBCASE("extra cases-2") {
        int arr[] = {0, -1, 0, -1};
        int length = sizeof(arr) / sizeof(arr[0]);
        CHECK(non_pos_prefix_sum(arr, length) == true);
    }
}
