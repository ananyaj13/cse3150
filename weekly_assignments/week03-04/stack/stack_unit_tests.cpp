#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <stack>

#include "stack_1.h"
#include "file_io.h"
#include "pop_stack.h"

TEST_CASE("Testing Stack Made from Input Files"){
    SUBCASE("test_input_1.txt"){
        //testing the reading file part
        stack<node> s;
        int length_of_elements = 4;
        s = reading_file("test_input_1.txt");
        CHECK(s.size() == length_of_elements);

        //checking popping elements --> after popping, the result should be 0 without errors unless the prefix sum is negative
        int size_of_stack = pop_stack("test_input_1.txt");
        CHECK_FALSE(size_of_stack == 0);
    }

    SUBCASE("test_input_2.txt"){
        //testing the reading file part
        stack<node> s;
        int length_of_elements = 3;
        s = reading_file("test_input_2.txt");
        CHECK(s.size() == length_of_elements);

        //checking popping elements --> after popping, the result should be 0 without errors unless the prefix sum is negative
        int size_of_stack = pop_stack("test_input_2.txt");
        CHECK_FALSE(size_of_stack == 0);
    }

    SUBCASE("test_input_3.txt"){
        //testing the reading file part
        stack<node> s;
        int length_of_elements = 5;
        s = reading_file("test_input_3.txt");
        CHECK(s.size() == length_of_elements);

        //checking popping elements --> after popping, the result should be 0 without errors unless the prefix sum is negative
        int size_of_stack = pop_stack("test_input_3.txt");
        CHECK(size_of_stack == 0);
    }

    SUBCASE("test_input_4.txt"){
        //testing the reading file part
        stack<node> s;
        int length_of_elements = 5;
        s = reading_file("test_input_4.txt");
        CHECK(s.size() == length_of_elements);

        //checking popping elements --> after popping, the result should be 0 without errors unless the prefix sum is negative
        int size_of_stack = pop_stack("test_input_4.txt");
        CHECK(size_of_stack == 0);
    }
}


TEST_CASE("Stack tester") {
    
    SUBCASE("size checking") {

        const int my_stack_size_Zero = 0;
        stack<int> s0 = get_stack(my_stack_size_Zero);
        CHECK(s0.size() == my_stack_size_Zero);

        const int my_stack_size = 6;
        stack<int> s1 = get_stack(my_stack_size);
        CHECK(s1.size() == my_stack_size);

        const int my_stack_size_node = 5;
        stack<node_2> s2 = get_stack_node(my_stack_size_node);
        CHECK(s2.size() == my_stack_size_node);

        node_2 test = s2.top();
        string top_name = test.name;
        int top_number = test.number;
        CHECK(top_name == "Ada Lovelace");
        CHECK(top_number == 4);

    }; 

    SUBCASE("stack copying") {

        const int my_stack_size = 6;
        stack<int> s = get_stack(my_stack_size);
        stack<int> t = s;
        CHECK(s == t);

        s.push(99);

        CHECK_FALSE(s.size() == t.size());

        CHECK_FALSE(s == t);

    }

};