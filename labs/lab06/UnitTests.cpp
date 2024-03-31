#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Matrix.h"

TEST_CASE("Test Matrix Multiplication") {
    std::vector<std::vector<int>> D_0 = {{0, 2, 2, 2},
                                         {2, 0, 2, 2},
                                         {2, 2, 0, 2},
                                         {2, 2, 2, 0}};

    std::vector<std::vector<int>> D_minus1 = {{-1, 2, 2, 2},
                                               {2, 2, 2, 2},
                                               {2, 2, 2, 2},
                                               {2, 2, 2, 2}};

    std::vector<std::vector<int>> D_plus1 = {{2, 1, 2, 2},
                                              {2, 2, 1, 2},
                                              {2, 2, 2, 1},
                                              {1, 2, 2, 2}};

    Matrix graph(4);
    graph.initialize(D_minus1, D_0, D_plus1);

    Matrix result = graph.multiply(graph);

    CHECK(result.getElement(0, 0) <= 1.0);
    CHECK(result.getElement(1, 1) == doctest::Approx(0));
    CHECK(result.getElement(2, 2) == doctest::Approx(0));
    CHECK(result.getElement(3, 3) == doctest::Approx(0));
}

TEST_CASE("Test Matrix Normalization") {
    std::vector<std::vector<int>> D_0 = {{0, 2, 2, 2},
                                         {2, 0, 2, 2},
                                         {2, 2, 0, 2},
                                         {2, 2, 2, 0}};

    std::vector<std::vector<int>> D_minus1 = {{-1, 2, 2, 2},
                                               {2, 2, 2, 2},
                                               {2, 2, 2, 2},
                                               {2, 2, 2, 2}};

    std::vector<std::vector<int>> D_plus1 = {{2, 1, 2, 2},
                                              {2, 2, 1, 2},
                                              {2, 2, 2, 1},
                                              {1, 2, 2, 2}};

    Matrix graph(4);
    graph.initialize(D_minus1, D_0, D_plus1);
    graph.normalize(4);

    CHECK(graph.getElement(0, 0) == -1);
    CHECK(graph.getElement(1, 1) == 0);
    CHECK(graph.getElement(2, 2) == 0);
    CHECK(graph.getElement(3, 3) == 0);
}

TEST_CASE("Test Matrix Initialization") {
    std::vector<std::vector<int>> D_0 = {{0, 1},
                                         {1, 0}};
    std::vector<std::vector<int>> D_minus1 = {{-1, 2},
                                               {2, -1}};
    std::vector<std::vector<int>> D_plus1 = {{1, 2},
                                              {2, 1}};
    Matrix graph(2);
    graph.initialize(D_minus1, D_0, D_plus1);
    
    CHECK(graph.getElement(0, 0) < 1.0); //when initializint this should be less than 1 because of the formuals professor provided
    CHECK(graph.getElement(0, 1) == 0);
    CHECK(graph.getElement(1, 0) == 0);
    CHECK(graph.getElement(1, 1) < 1.0); //same as the (0,0) where it should be a decimal value ad below 1
}

TEST_CASE("Test Matrix Multiplication with Identity Matrix") {
    // Test multiplication with identity matrix
    std::vector<std::vector<int>> D_0 = {{0, 1},
                                         {1, 0}};
    std::vector<std::vector<int>> D_minus1 = {{-1, 2},
                                               {2, -1}};
    std::vector<std::vector<int>> D_plus1 = {{1, 2},
                                              {2, 1}};
    Matrix graph(2);
    graph.initialize(D_minus1, D_0, D_plus1);

    Matrix identity(2);
    identity.initialize({{0, 0},
                         {0, 0}},
                         {{0, 0},
                         {0, 0}},
                         {{1, 0},
                         {0, 1}});

    Matrix result = graph.multiply(identity);
    
    CHECK(result.getElement(0, 0) < 1); //when you multiply this should be less than 1 --> a decimal value it should be 
    CHECK(result.getElement(0, 1) == 1);
    CHECK(result.getElement(1, 0) == 1);
    CHECK(result.getElement(1, 1) == 1);
}

TEST_CASE("Test Matrix Initialization with Negative Values") {
    std::vector<std::vector<int>> D_0 = {{0, -1},
                                         {-1, 0}};
    std::vector<std::vector<int>> D_minus1 = {{-1, -2},
                                               {-2, -1}};
    std::vector<std::vector<int>> D_plus1 = {{1, 2},
                                              {2, 1}};
    Matrix graph(2);
    graph.initialize(D_minus1, D_0, D_plus1);
    
    CHECK(graph.getElement(0, 0) == 9); 
    CHECK(graph.getElement(0, 1) == 0);
    CHECK(graph.getElement(1, 0) == 0);
    CHECK(graph.getElement(1, 1) < 1 );
}

TEST_CASE("Test Matrix Multiplication with Zero Matrix") {
    std::vector<std::vector<int>> D_0 = {{0, 0},
                                         {0, 0}};
    std::vector<std::vector<int>> D_minus1 = {{0, 0},
                                               {0, 0}};
    std::vector<std::vector<int>> D_plus1 = {{0, 0},
                                              {0, 0}};
    Matrix graph(2);
    graph.initialize(D_minus1, D_0, D_plus1);

    Matrix result = graph.multiply(graph);
    //the following is 0 cost but because when its 0 cost the value is 1, the matrix multiplication should cause all values to be 2
    CHECK(result.getElement(0, 0) == 2);
    CHECK(result.getElement(0, 1) == 2);
    CHECK(result.getElement(1, 0) == 2);
    CHECK(result.getElement(1, 1) == 2);
}

TEST_CASE("Test Matrix Normalization with Zero Edge Cost") {
    std::vector<std::vector<int>> D_0 = {{0, 0},
                                         {0, 0}};
    std::vector<std::vector<int>> D_minus1 = {{0, 0},
                                               {0, 0}};
    std::vector<std::vector<int>> D_plus1 = {{0, 0},
                                              {0, 0}};
    Matrix graph(2);
    graph.initialize(D_minus1, D_0, D_plus1);
    graph.normalize(2);

    CHECK(graph.getElement(0, 0) == 0);
    CHECK(graph.getElement(0, 1) == 0);
    CHECK(graph.getElement(1, 0) == 0);
    CHECK(graph.getElement(1, 1) == 0);
}
