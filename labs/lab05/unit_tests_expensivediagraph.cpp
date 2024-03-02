#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <iostream>
#include <istream> 
#include <fstream>
#include <algorithm> 
#include <iterator>
#include <string>
#include <vector>

// #include "ints_read_matrix.h"
// #include "ints_write.h"
#include "expensive_diagraph.h"

TEST_CASE("updateD_0") {
    SUBCASE("Zero-cost path condition - D_minus_1 + D_1 == 0") {
        vector<vector<int>> D_minus_1 = {{0, 1}, {-1, 0}};
        vector<vector<int>> D_0 = {{1, 1}, {1, 1}};
        vector<vector<int>> D_1 = {{0, 1}, {0, 0}};

        updateD_0(D_minus_1, D_0, D_1, 0, 1, 1);

        CHECK(D_0[0][1] == 1);
    }

    SUBCASE("Zero-cost path condition - D_1 + D_minus_1 == 0") {
        vector<vector<int>> D_minus_1 = {{0, 1}, {-1, 0}};
        vector<vector<int>> D_0 = {{1, 1}, {1, 1}};
        vector<vector<int>> D_1 = {{0, 1}, {0, 0}};

        updateD_0(D_minus_1, D_0, D_1, 1, 0, 1);

        CHECK(D_0[1][0] == 0);
    }

    SUBCASE("No zero-cost path condition") {
        vector<vector<int>> D_minus_1 = {{0, 1}, {-1, 0}};
        vector<vector<int>> D_0 = {{1, 1}, {1, 1}};
        vector<vector<int>> D_1 = {{0, 1}, {0, 0}};

        updateD_0(D_minus_1, D_0, D_1, 0, 1, 0);

        CHECK(D_0[0][1] == 1);
    }
}

// Similar test cases can be added for updateD_1 and updateD_minus_1 functions

TEST_CASE("expensiveDigraphExactPaths") {
    SUBCASE("Small graph") {
        vector<vector<int>> D_minus_1 = {{0, 1}, {-1, 0}};
        vector<vector<int>> D_0 = {{1, 1}, {1, 1}};
        vector<vector<int>> D_1 = {{0, 1}, {0, 0}};

        expensiveDigraphExactPaths(D_minus_1, D_0, D_1);

        CHECK(D_0[0][1] == 1);
        CHECK(D_1[1][1] == 1);
        CHECK(D_minus_1[0][1] == 1);
    }

    SUBCASE("Large graph"){
        vector<vector<int>> D_minus_1 = {
                                            {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                                        };
        vector<vector<int>> D_0 = {
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                                };
        vector<vector<int>> D_1 = {
                                    {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                                };
        CHECK(D_0[0][1] == 0);
        CHECK(D_1[1][1] == 0);
        CHECK(D_minus_1[0][1] == 1);
    }


}
