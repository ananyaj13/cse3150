#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <queue>

#include "queue_1.h"
#include "file_io.h"
#include "pop_queue.h"

TEST_CASE("Testing Queue Made from Input Files"){
    SUBCASE("test_input_1.txt"){
        //testing the reading file part
        queue<node> s;
        int length_of_elements = 4;
        s = reading_file("test_input_1.txt");
        CHECK(s.size() == length_of_elements);

        //checking popping elements --> after popping, the result should be 0 without errors unless the prefix sum is negative
        int size_of_queue = pop_queue("test_input_1.txt");
        CHECK_FALSE(size_of_queue == 0);
    }

    SUBCASE("test_input_2.txt"){
        //testing the reading file part
        queue<node> s;
        int length_of_elements = 3;
        s = reading_file("test_input_2.txt");
        CHECK(s.size() == length_of_elements);

        //checking popping elements --> after popping, the result should be 0 without errors unless the prefix sum is negative
        int size_of_queue = pop_queue("test_input_2.txt");
        CHECK_FALSE(size_of_queue == 0);
    }

    SUBCASE("test_input_3.txt"){
        //testing the reading file part
        queue<node> s;
        int length_of_elements = 6;
        s = reading_file("test_input_3.txt");
        CHECK(s.size() == length_of_elements);

        //checking popping elements --> after popping, the result should be 0 without errors unless the prefix sum is negative
        int size_of_queue = pop_queue("test_input_3.txt");
        CHECK(size_of_queue == 0);
    }

    SUBCASE("test_input_4.txt"){
        //testing the reading file part
        queue<node> s;
        int length_of_elements = 5;
        s = reading_file("test_input_4.txt");
        CHECK(s.size() == length_of_elements);

        //checking popping elements --> after popping, the result should be 0 without errors unless the prefix sum is negative
        int size_of_queue = pop_queue("test_input_4.txt");
        CHECK(size_of_queue == 0);
    }
}

TEST_CASE("queue tester") {
    
    SUBCASE("size checking") {

        const int my_queue_size_Zero = 0;
        queue<int> s0 = get_queue(my_queue_size_Zero);
        CHECK(s0.size() == my_queue_size_Zero);

        const int my_queue_size = 6;
        queue<int> s1 = get_queue(my_queue_size);
        CHECK(s1.size() == my_queue_size);

        const int my_queue_size_node = 5;
        queue<node_2> s2 = get_queue_node(my_queue_size_node);
        CHECK(s2.size() == my_queue_size_node);

        node_2 test = s2.back();
        string last_name = test.name;
        int last_number = test.number;
        CHECK(last_name == "Ada Lovelace");
        CHECK(last_number == 4);

        node_2 test_2 = s2.front();
        string first_name = test_2.name;
        int first_number = test_2.number;
        CHECK(first_name == "S. Ulam");
        CHECK(first_number == 0);

    }; 

    SUBCASE("queue copying") {

        const int my_queue_size = 6;
        queue<int> s = get_queue(my_queue_size);
        queue<int> t = s;
        CHECK(s == t);

        s.push(99);

        CHECK_FALSE(s.size() == t.size());

        CHECK_FALSE(s == t);

    }

};