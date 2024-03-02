#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <fstream>
#include <sstream>
#include "int_vector.h"


TEST_CASE("Testing int_vector constructor") {
    SUBCASE("Constructor initializes members correctly") {
        int_vector v(1, 2, 3, 4);
        CHECK(v.id == 1);
        CHECK(v.x == 2);
        CHECK(v.y == 3);
        CHECK(v.my_size == 4);
        CHECK(v.values != nullptr);
        CHECK(v.values[0] == 0); // default initialized
        CHECK(v.values[1] == 1);
        CHECK(v.values[2] == 2);
        CHECK(v.values[3] == 3);
    }
}

TEST_CASE("Testing int_vector copy constructor") {
    SUBCASE("Copy constructor copies correctly") {
        int_vector v1(1, 2, 3, 4);
        int_vector v2 = v1;
        CHECK(v2.id == v1.id);
        CHECK(v2.x == v1.x);
        CHECK(v2.y == v1.y);
        CHECK(v2.my_size == v1.my_size);
        CHECK(v2.values != nullptr);
        CHECK(v2.values[0] == 0); // default initialized
        CHECK(v2.values[1] == 1);
        CHECK(v2.values[2] == 2);
        CHECK(v2.values[3] == 3);
    }
}

// Test case to check if vectors are read correctly from a file with multiple vectors
TEST_CASE("Test reading vectors from file with multiple vectors") {
    ofstream outFile("temp_vectors.txt");
    //writing to the file 
    outFile << "1 2\n";
    outFile << "3 4\n";
    outFile << "5 6\n";
    outFile.close();

    // read vectors from the temp file
    vector<int_vector> vectors = readVectorsFromFile("temp_vectors.txt");
    REQUIRE(vectors.size() == 3);
    CHECK(vectors[0].id == 0);
    CHECK(vectors[0].x == 1);
    CHECK(vectors[0].y == 2);
    CHECK(vectors[1].id == 1);
    CHECK(vectors[1].x == 3);
    CHECK(vectors[1].y == 4);
    CHECK(vectors[2].id == 2);
    CHECK(vectors[2].x == 5);
    CHECK(vectors[2].y == 6);
    remove("temp_vectors.txt");
}

// Test case to check if vectors are read correctly from a file with single vector
TEST_CASE("Test reading vectors from file with single vector") {
    ofstream outFile("temp_vectors.txt");
    outFile << "1 2\n"; //writing to file 
    outFile.close();

    //reading from temp file
    vector<int_vector> vectors = readVectorsFromFile("temp_vectors.txt");
    REQUIRE(vectors.size() == 1);
    CHECK(vectors[0].id == 0);
    CHECK(vectors[0].x == 1);
    CHECK(vectors[0].y == 2);
    remove("temp_vectors.txt");
}

// Test case to check if vectors are read correctly from an empty file
TEST_CASE("Test reading vectors from an empty file") {
    //empty file has no content so you open the file and close it immedietly -->
    ofstream outFile("temp_vectors.txt");
    outFile.close();

    //reading the empty temp file
    vector<int_vector> vectors = readVectorsFromFile("temp_vectors.txt");
    CHECK(vectors.size() == 0);
    remove("temp_vectors.txt");
}

// Test case to check if vectors are read correctly from a non-existent file
TEST_CASE("Test reading vectors from a non-existent file") {
    //since no real file, you don't open and close anything
    vector<int_vector> vectors = readVectorsFromFile("bob.txt");

    // check if no vectors are read
    CHECK(vectors.size() == 0);
}
