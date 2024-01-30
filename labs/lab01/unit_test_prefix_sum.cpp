#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"

int test_arr_1[] = {};
int test_arr_2[] = {1, -1, -1};
int test_arr_3[] = {-1, 1};
int test_arr_4[] = {1, 1, -1, 1};
int test_arr_5[] = {1, 2, -1};
int test_arr_6[] = {1, -2, -1};
int test_arr_7[] = {1, -1, -1, 1};


TEST_CASE("value-check"){
    SUBCASE("proper inputs"){
        CHECK_EQ(value_check(test_arr_2, 3), false);
        CHECK_EQ(value_check(test_arr_3, 2), false);
        CHECK_EQ(value_check(test_arr_4, 4), false);
        CHECK_EQ(value_check(test_arr_7, 4), false);
    }

    SUBCASE("empty list"){
        CHECK_EQ(value_check(test_arr_1, 0), false);
    }
    
    SUBCASE("improper input -> input values are above 1/below -1"){
        CHECK_EQ(value_check(test_arr_5, 3), true);
        CHECK_EQ(value_check(test_arr_6, 3), true);
    }
    
};

TEST_CASE("non-negative"){
    SUBCASE("proper inputs"){
        CHECK_EQ(non_neg_prefix_sum(test_arr_2, 3),false);
        CHECK_EQ(non_neg_prefix_sum(test_arr_3, 2),false);
        CHECK_EQ(non_neg_prefix_sum(test_arr_4, 4),true);
        CHECK_EQ(non_neg_prefix_sum(test_arr_7, 4),false);
    }

    SUBCASE("empty list"){
        CHECK_EQ(non_neg_prefix_sum(test_arr_1, 0),false);
    }
    
    SUBCASE("improper input -> input values are above 1/below -1"){
        CHECK_EQ(non_neg_prefix_sum(test_arr_5, 3), false);
        CHECK_EQ(non_neg_prefix_sum(test_arr_6, 3), false);
    }
    
};

TEST_CASE("non-positive"){ 
    SUBCASE("proper inputs"){
        CHECK_EQ(non_pos_prefix_sum(test_arr_2, 3),false);
        CHECK_EQ(non_pos_prefix_sum(test_arr_3, 2),true);
        CHECK_EQ(non_pos_prefix_sum(test_arr_4, 4),false);
        CHECK_EQ(non_pos_prefix_sum(test_arr_7, 4),false);
    }

    SUBCASE("empty list"){
        CHECK_EQ(non_pos_prefix_sum(test_arr_1, 0),false);
    }
    
    SUBCASE("improper input -> input values are above 1/below -1"){
        CHECK_EQ(non_pos_prefix_sum(test_arr_5, 3), false);
        CHECK_EQ(non_pos_prefix_sum(test_arr_6, 3), false);
    }
    
};