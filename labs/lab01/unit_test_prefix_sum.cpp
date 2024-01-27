#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"

int test_arr_1[] = {};
int test_arr_2[] = {1, -1, -1};
int test_arr_3[] = {-1, 1};
int test_arr_4[] = {1, 1, -1, 1};
int test_arr_5[] = {1, 2, -1};

TEST_CASE("prefix sum"){
    CHECK_EQ(prefix_sum(test_arr_1, 0), 0);
    CHECK_EQ(prefix_sum(test_arr_2, sizeof(test_arr_2)/sizeof(test_arr_2[0])), -1);

    SUBCASE("value-check"){
        CHECK_EQ(value_check(test_arr_1, 0), false);
        CHECK_EQ(value_check(test_arr_2, 3), false);
        CHECK_EQ(value_check(test_arr_3, 2), false);
        CHECK_EQ(value_check(test_arr_4, 4), false);
        CHECK_EQ(value_check(test_arr_5, 3), true);
    }

    SUBCASE("non-negative"){
        CHECK_EQ(non_neg_prefix_sum(test_arr_1, 0),false);
        CHECK_EQ(non_neg_prefix_sum(test_arr_2, 3),true);
        CHECK_EQ(non_neg_prefix_sum(test_arr_3, 2),true);
        CHECK_EQ(non_neg_prefix_sum(test_arr_4, 4),false);
        CHECK_EQ(non_neg_prefix_sum(test_arr_5, 3), false);
    };

    SUBCASE("non-positive"){ 
        CHECK_EQ(non_pos_prefix_sum(test_arr_1, 0),false);
        CHECK_EQ(non_pos_prefix_sum(test_arr_2, 3),true);
        CHECK_EQ(non_pos_prefix_sum(test_arr_3, 2),false);
        CHECK_EQ(non_pos_prefix_sum(test_arr_4, 4),true);
        CHECK_EQ(non_pos_prefix_sum(test_arr_5, 3), false);
    }

    
};