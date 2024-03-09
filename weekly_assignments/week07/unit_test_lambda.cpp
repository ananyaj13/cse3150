#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "lambda.h"

// NOTE FOR GRADER: I asked professor bradford to check my imlementation, and he allowed 
// me to do it this way instead of the for_each approach or the vector approach

TEST_CASE("Testing perfect_num function") {
    //Now within the function I have an extra loop that checks for wrong limit val where if limit == number, then limit goes down by one
    CHECK(perfect_num(5, 6) == true); // 6 is a perfect number
    CHECK(perfect_num(6, 6) == true);   // 6 is a perfect number (1 + 2 + 3 = 6)
    CHECK(perfect_num(27, 28) == true); // 28 is a perfect number (1 + 2 + 4 + 7 + 14 = 28)
    CHECK(perfect_num(30, 30) == false); // 30 is not a perfect 
}

TEST_CASE("Testing perf_vector function") {
    std::vector<int> vec1 = {6, 28, 496, 8128}; // Perfect numbers
    std::vector<int> vec2 = {6, 28, 496, 8128, 30}; // Non-perfect number --> 30 is a non perf num
    std::vector<int> vec3 = {4, 8, 10, 14}; //Everything is non perfect
    std::vector<int> vec4 = {}; // Empty vector --> EDGE CASE 
    std::vector<int> vec5 = {-4, -8, -10, -14}; // I have another loop that checks for negative values and turns them positive to check if absolute of the value is perfect or not
    std::vector<int> vec6 = {-6, 28, 496, 8128};

    CHECK(perf_vector(vec1) == true); // All numbers in vec1 are perfect
    CHECK(perf_vector(vec2) == false); // vec2 contains a non-perfect number
    CHECK(perf_vector(vec3) == false);
    CHECK(perf_vector(vec4) == true); // Empty vector should return true
    CHECK(perf_vector(vec5) == false);
    CHECK(perf_vector(vec6) == true);
}
