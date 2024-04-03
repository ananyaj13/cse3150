#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <cmath>
#include "double_vector.h"
#include "distance.h"

#define EPSILON 0.0001

using namespace std;

//doctest::Approx is to approximate the final value as performing calculations with doubles can sometimes output
// values that are a few decimals off

TEST_CASE("Square Function") {
    CHECK(square(2.0) == doctest::Approx(4.0));
    CHECK(square(-3.0) == doctest::Approx(9.0));
    CHECK(square(0.0) == doctest::Approx(0.0));
}

TEST_CASE("Dot Product Function") {
    double_vector v1({1.0, 2.0}, 1);
    double_vector v2({3.0, 4.0}, 2);
    CHECK(dot_product(v1, v2) == doctest::Approx(11.0));

    double_vector v3({1.0, 0.0}, 1);
    double_vector v4({0.0, 1.0}, 2);
    CHECK(dot_product(v3, v4) == doctest::Approx(0.0));

    double_vector v5({2.0, 3.0}, 1);
    double_vector v6({-2.0, -3.0}, 2);
    CHECK(dot_product(v5, v6) == doctest::Approx(-13.0));

    double_vector v7({3.0, 4.0}, 1);
    double_vector v8({6.0, 8.0}, 2);
    CHECK(dot_product(v7, v8) == doctest::Approx(50.0));
}

TEST_CASE("Magnitude Function") {
    double_vector v({3.0, 4.0}, 1);
    CHECK(magnitude(v) == doctest::Approx(5.0));

    double_vector v2({0.0, 0.0}, 1);
    CHECK(magnitude(v2) == doctest::Approx(0.0));

    double_vector v3({-3.0, -4.0}, 1);
    CHECK(magnitude(v3) == doctest::Approx(5.0));
}

TEST_CASE("Cosine Distance Function") {
    double_vector v1({1.0, 0.0}, 1);
    double_vector v2({0.0, 1.0}, 2);
    CHECK(cosine_distance(v1, v2) == doctest::Approx(M_PI / 2).epsilon(EPSILON)); 

    double_vector v3({2.0, 3.0}, 1);
    double_vector v4({4.0, 6.0}, 2);
    CHECK(cosine_distance(v3, v4) == doctest::Approx(0.0).epsilon(EPSILON)); 

    double_vector v5({-3.0, -4.0}, 1);
    double_vector v6({3.0, 4.0}, 2);
    CHECK(cosine_distance(v5, v6) == doctest::Approx(M_PI).epsilon(EPSILON)); 
}


TEST_CASE("All pairs distance calculation") {
    // Test case for test1.txt
    SUBCASE("Test1 --> 3D") {
        vector<double_vector> vectors1 = read_from_file("test1.txt");
        vector<my_distance> distances1 = all_pairs_distance(vectors1);
        
        bool sorted1 = is_sorted(distances1.begin(), distances1.end(), 
            [](const my_distance& left, const my_distance& right) {
                return left.cos_distance > right.cos_distance;
            });
        CHECK(sorted1); // Checking if the vector is actually sorted or not --> should return false if it's not sorted
    }

    // Test case for test2.txt
    SUBCASE("Test2 --> all 0s --> 2D") {
        vector<double_vector> vectors2 = read_from_file("test2.txt");
        vector<my_distance> distances2 = all_pairs_distance(vectors2);
        
        bool sorted2 = is_sorted(distances2.begin(), distances2.end(), 
            [](const my_distance& left, const my_distance& right) {
                return left.cos_distance > right.cos_distance;
            });
        CHECK(sorted2); // Checking if the vector is actually sorted or not --> should return false if it's not sorted
    }

    // Test case for test3.txt
    SUBCASE("Test3 --> 5D") {
        vector<double_vector> vectors3 = read_from_file("test3.txt");
        vector<my_distance> distances3 = all_pairs_distance(vectors3);
        
        bool sorted3 = is_sorted(distances3.begin(), distances3.end(), 
            [](const my_distance& left, const my_distance& right) {
                return left.cos_distance > right.cos_distance;
            });
        CHECK(sorted3); // Checking if the vector is actually sorted or not --> should return false if it's not sorted
    }

    // Test case for test4.txt
    SUBCASE("Test4 --> empty") {
        vector<double_vector> vectors4 = read_from_file("test4.txt");
        vector<my_distance> distances4 = all_pairs_distance(vectors4);
        
        CHECK(distances4.size() == vectors4.size() * (vectors4.size() - 1)); // Each vector compared to all others except itself --> even though 
                                                                             // it's an empty file, it should work the same when checking against elements
        
        bool sorted4 = is_sorted(distances4.begin(), distances4.end(), 
            [](const my_distance& left, const my_distance& right) {
                return left.cos_distance > right.cos_distance;
            });
        CHECK(sorted4); // Checking if the vector is actually sorted or not --> should return false if it's not sorted
    }
}
