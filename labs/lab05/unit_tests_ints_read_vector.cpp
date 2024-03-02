#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "ints_read_vector.h"

 
// my test casses/subcases start at line 82
TEST_CASE("ints_read") {
  
  SUBCASE("ints_read : edge cases - istringstream") {
    istringstream istr_0("");
    vector<int> vec_0 = ints_read_vector(istr_0);
    CHECK(0 == vec_0.size());

    istringstream istr_99("-99");
    vector<int> vec_99 = ints_read_vector(istr_99);
    CHECK(-99 == vec_99[0]);
    CHECK(1 == vec_99.size());

    istringstream istr_5("5");
    vector<int> vec_5 = ints_read_vector(istr_5);
    CHECK(5 == vec_5[0]);
    CHECK(1 == vec_5.size());
  };

  SUBCASE("ints_read_one_line() : edge cases - istringstream") {
    istringstream istr_0("");
    vector<int> vec_0 = ints_read_one_line(istr_0);
    CHECK(0 == vec_0.size());

    istringstream istr_5("5");
    vector<int> vec_5 = ints_read_vector(istr_5);
    CHECK(5 == vec_5[0]);
    CHECK(1 == vec_5.size());

    istringstream istr_99("-99 1 2");
    vector<int> vec_99 = ints_read_vector(istr_99);
    CHECK(-99 == vec_99[0]);
    CHECK(3 == vec_99.size());

    istringstream istr_two_lines("-99 1 2\\n3 4 5"); // escape the new-line
    vector<int> vec_one_line = ints_read_vector(istr_two_lines);
    CHECK(-99 == vec_one_line[0]);
    CHECK(3 == vec_one_line.size()); // only 1 line of 3 elements read in

  };

  SUBCASE("ints_read : edge cases - ifstream FILE") {
    const char FILE_NAME[] = "./temp.txt";
    ofstream test_file;
    test_file.open(FILE_NAME);
    test_file << "8";
    test_file.close();

    ifstream test_same_file;
    test_same_file.open(FILE_NAME); 
    
    vector<int> vec_8 = ints_read_vector(test_same_file);
     test_same_file.close();
    CHECK(1 == vec_8.size());
    CHECK(8 == vec_8[0]);

  };


  
  SUBCASE("ints_read : small cases") {

    istringstream istr("0 1 2");
    vector<int> vec = ints_read_vector(istr);
    CHECK(0 == vec[0]);
    CHECK(1 == vec[1]);
    CHECK(2 == vec[2]);

  };

// MY TEST CASES:

  SUBCASE("ints_read --> Vector with multiple elements") {
    istringstream multiElementStream("1 2 3 4 5");
    vector<int> vec = ints_read(multiElementStream);
    REQUIRE(vec.size() == 5);
    CHECK(vec[0] == 1);
    CHECK(vec[1] == 2);
    CHECK(vec[2] == 3);
    CHECK(vec[3] == 4);
    CHECK(vec[4] == 5);
  }

  SUBCASE("ints_read --> Multiple lines with multiple elements") {
      istringstream multiLineStream("1 2 3\n4 5 6\n7 8 9");
      vector<int> vec = ints_read(multiLineStream);
      REQUIRE(vec.size() == 9); // All elements from all lines are read
      CHECK(vec[0] == 1);
      CHECK(vec[1] == 2);
      CHECK(vec[2] == 3);
      CHECK(vec[3] == 4);
      CHECK(vec[4] == 5);
      CHECK(vec[5] == 6);
      CHECK(vec[6] == 7);
      CHECK(vec[7] == 8);
      CHECK(vec[8] == 9);
    }

  SUBCASE("ints_read_one_line --> Single line with multiple elements") {
    istringstream singleLineStream("5 6 7 8 9");
    vector<int> vec = ints_read_one_line(singleLineStream);
    REQUIRE(vec.size() == 5);
    CHECK(vec[0] == 5);
    CHECK(vec[1] == 6);
    CHECK(vec[2] == 7);
    CHECK(vec[3] == 8);
    CHECK(vec[4] == 9);
  }

  SUBCASE("ints_read_one_line --> Multiple lines with multiple elements") {
    istringstream multiLineStream("10 92 -3\n40 5 6");
    vector<int> vec = ints_read_one_line(multiLineStream);
    REQUIRE(vec.size() == 3); // Only the first line is read
    CHECK(vec[0] == 10);
    CHECK(vec[1] == 92);
    CHECK(vec[2] == -3);
  }

  SUBCASE("ints_read_one_line --> Multiple lines with multiple elements") {
    istringstream multiLineStream("1 2 3\n4 5 6\n7 8 9");
    vector<int> vec = ints_read_one_line(multiLineStream);
    REQUIRE(vec.size() == 3); // Only the first line is read
    CHECK(vec[0] == 1);
    CHECK(vec[1] == 2);
    CHECK(vec[2] == 3);
    //for the following statements they're suppsoed to be anything but the actual values as they dont exist in the vector
    CHECK(vec[3] != 4);
    CHECK(vec[4] != 5);
    CHECK(vec[5] != 6);
    CHECK(vec[8] != 9);
  }
}

