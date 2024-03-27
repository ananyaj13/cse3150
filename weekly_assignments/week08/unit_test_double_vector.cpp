#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <cmath>
#include "double_vector.h"
#include "distance.h"

#define EPSILON 0.0001

using namespace std;

TEST_CASE("double vector testing --> in class"){
    SUBCASE("basic cases"){
        double_vector dv = double_vector(1.0, 1.0, 0); 
        CHECK(2.0 == dot_product(dv, dv));

        double actual_magnitude = magnitude(dv);
        double srt = sqrt(2.0);
        double answer = fabs(srt - actual_magnitude);
        CHECK(answer < EPSILON);

        double_vector a = double_vector(1.0 , 0.0, 0); 
        double_vector b = double_vector(-1.0 , 0.0, 1); 
        double answer_acos_a_b = cosine_distance(a, b);
        CHECK(M_PI == answer_acos_a_b);

        double_vector c = double_vector(2.7, 7.0, 2); 
        double_vector c_id = c;
        double answer_acod_c_c_id = cosine_distance(c, c_id);
        double actual_dot_prod_c = dot_product(c, c_id);
        CHECK(56.29 == actual_dot_prod_c);

        double actual_magnitude_c = magnitude(c);
        double actual_magnitude_c_id = magnitude(c_id);
        CHECK(actual_magnitude_c == actual_magnitude_c_id);
    }
}

TEST_CASE("Square function") {
    CHECK(square(2.0) == doctest::Approx(4.0));
    CHECK(square(-3.0) == doctest::Approx(9.0));
    CHECK(square(0.0) == doctest::Approx(0.0));
}

TEST_CASE("Dot product function") {
    double_vector v1(1.0, 2.0, 1);
    double_vector v2(3.0, 4.0, 2);
    CHECK(dot_product(v1, v2) == doctest::Approx(11.0));


    double_vector v3(1.0, 0.0, 1);
    double_vector v4(0.0, 1.0, 2);
    CHECK(dot_product(v3, v4) == doctest::Approx(0.0));


    double_vector v5(2.0, 3.0, 3);
    double_vector v6(-2.0, -3.0, 4);
    CHECK(dot_product(v5, v6) == doctest::Approx(-13.0));

    double_vector v7(3.0, 4.0, 5);
    double_vector v8(6.0, 8.0, 6);
    CHECK(dot_product(v7, v8) == doctest::Approx(50.0));
}  

TEST_CASE("Magnitude function") {
    double_vector v(3.0, 4.0, 3);
    CHECK(magnitude(v) == doctest::Approx(5.0));

    double_vector v2(0.0, 0.0, 2);
    CHECK(magnitude(v2) == doctest::Approx(0.0));

    double_vector v3(-3.0, -4.0, 3);
    CHECK(magnitude(v3) == doctest::Approx(5.0));
}

TEST_CASE("Cosine distance function") {
    double_vector v1(1.0, 0.0, 4);
    double_vector v2(0.0, 1.0, 5);
    CHECK(cosine_distance(v1, v2) == doctest::Approx(acos(0.0)).epsilon(1e-5)); // Should be pi/2

    double_vector v3(2.0, 3.0, 6);
    double_vector v4(4.0, 6.0, 7);
    CHECK(cosine_distance(v3, v4) == doctest::Approx(0.0).epsilon(1e-5)); // Should be 0.0

    double_vector v5(-3.0, -4.0, 8);
    double_vector v6(3.0, 4.0, 9);
    CHECK(cosine_distance(v5, v6) == doctest::Approx(M_PI).epsilon(1e-5)); // Should be pi

}

TEST_CASE("Reading vectors from file") {
    vector<double_vector> vectors = read_from_file("test1.txt");
    CHECK(vectors.size() == 10); 


    vector<double_vector> vectors2 = read_from_file("test2.txt");
    CHECK(vectors2.size() == 5); 


    vector<double_vector> vectors3 = read_from_file("test3.txt");
    CHECK(vectors3.size() == 5); 


    vector<double_vector> vectors4 = read_from_file("test4.txt");
    CHECK(vectors4.size() == 0); 

}

TEST_CASE("All pairs distance calculation") {
    // Test case for test1.txt
    SUBCASE("Test1") {
        vector<double_vector> vectors1 = read_from_file("test1.txt");
        vector<my_distance> distances1 = all_pairs_distance(vectors1);
        
        CHECK(distances1.size() == vectors1.size() * (vectors1.size() - 1)); // Each vector compared to all others except itself
        
        bool sorted1 = true;
        for (size_t i = 0; i < distances1.size() - 1; ++i) {
            if (distances1[i].cos_distance < distances1[i + 1].cos_distance) {
                sorted1 = false;
                break;
            }
        }
        CHECK(sorted1); //Checking if the vector is actually sorted or not --> should return false if it's not sorted
    }

    // Test case for test2.txt
    SUBCASE("Test2") {
        vector<double_vector> vectors2 = read_from_file("test2.txt");
        vector<my_distance> distances2 = all_pairs_distance(vectors2);
        
        CHECK(distances2.size() == vectors2.size() * (vectors2.size() - 1)); // Each vector compared to all others except itself
        
        bool sorted2 = true;
        for (size_t i = 0; i < distances2.size() - 1; ++i) {
            if (distances2[i].cos_distance < distances2[i + 1].cos_distance) {
                sorted2 = false;
                break;
            }
        }
        CHECK(sorted2); //Checking if the vector is actually sorted or not --> should return false if it's not sorted
    }

    // Test case for test3.txt
    SUBCASE("Test3") {
        vector<double_vector> vectors3 = read_from_file("test3.txt");
        vector<my_distance> distances3 = all_pairs_distance(vectors3);
        
        CHECK(distances3.size() == vectors3.size() * (vectors3.size() - 1)); // Each vector compared to all others except itself
        
        bool sorted3 = true;
        for (size_t i = 0; i < distances3.size() - 1; ++i) {
            if (distances3[i].cos_distance < distances3[i + 1].cos_distance) {
                sorted3 = false;
                break;
            }
        }
        CHECK(sorted3); //Checking if the vector is actually sorted or not --> should return false if it's not sorted
    }

    // Test case for test4.txt
    SUBCASE("Test4") {
        vector<double_vector> vectors4 = read_from_file("test4.txt");
        vector<my_distance> distances4 = all_pairs_distance(vectors4);
        
        CHECK(distances4.size() == vectors4.size() * (vectors4.size() - 1)); // Each vector compared to all others except itself --> even though 
                                                                             // it's an empty file, it should work the same when checking against elements
        bool sorted4 = true;
        if (distances4.size() > 0){ // This checks is there are any elements in the vector before proceeding to compare 
            for (size_t i = 0; i < distances4.size() - 1; ++i) {
                if (distances4[i].cos_distance < distances4[i + 1].cos_distance) {
                    sorted4 = false;
                    break;
                }
            }
        } 
        else{
            sorted4 = false;
        }

    }
}
