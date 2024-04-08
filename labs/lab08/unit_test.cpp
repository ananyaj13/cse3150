#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"
#include <iostream>
#include <sstream>

using namespace std;

TEST_CASE("LinkedList Tests") {
    LinkedList list;

    SUBCASE("Build and Print Main Linked List") {
        SUBCASE("input 5"){
            list.build_node_list(5);
            stringstream captured_output;
            streambuf* original_cout = cout.rdbuf(captured_output.rdbuf());
            list.print_node_list_shared_ptrs();
            cout.rdbuf(original_cout);
            string actual_output = captured_output.str();
            string expected_output = "1 2 3 4 5 \n";
            CHECK(expected_output == actual_output);
        }
        SUBCASE("input 3"){
            list.build_node_list(3);
            stringstream captured_output;
            streambuf* original_cout = cout.rdbuf(captured_output.rdbuf());
            list.print_node_list_shared_ptrs();
            cout.rdbuf(original_cout);
            string actual_output = captured_output.str();
            string expected_output = "1 2 3 \n";
            CHECK(expected_output == actual_output);
        }
    }

    SUBCASE("Build and Print CopyNodes with Weak Pointers") {
        SUBCASE("input 5"){
            list.build_node_list(5);
            vector<LinkedList::CopyNode> copyNodes = list.build_copyNodes_weak_ptrs();
            stringstream captured_output;
            streambuf* original_cout = cout.rdbuf(captured_output.rdbuf());
            list.print_node_array_weak_ptrs(copyNodes);
            cout.rdbuf(original_cout);
            string actual_output = captured_output.str();
            string expected_output = "1 2 3 4 5 \n";
            CHECK(expected_output == actual_output);
        }

        SUBCASE("input 3"){
            list.build_node_list(3);
            vector<LinkedList::CopyNode> copyNodes = list.build_copyNodes_weak_ptrs();
            stringstream captured_output;
            streambuf* original_cout = cout.rdbuf(captured_output.rdbuf());
            list.print_node_array_weak_ptrs(copyNodes);
            cout.rdbuf(original_cout);
            string actual_output = captured_output.str();
            string expected_output = "1 2 3 \n";
            CHECK(expected_output == actual_output);
        }
    }

    SUBCASE("Delete Main Linked List") { 
        SUBCASE("input 5"){
            list.build_node_list(5);
            list.delete_node_shared_ptr_list();
            stringstream captured_output;
            streambuf* original_cout = cout.rdbuf(captured_output.rdbuf());
            list.print_node_list_shared_ptrs();
            cout.rdbuf(original_cout);
            string actual_output = captured_output.str();
            string expected_output = "\n";
            CHECK(expected_output == actual_output);
        }
        SUBCASE("input 1"){
            list.build_node_list(1);
            list.delete_node_shared_ptr_list();
            stringstream captured_output;
            streambuf* original_cout = cout.rdbuf(captured_output.rdbuf());
            list.print_node_list_shared_ptrs();
            cout.rdbuf(original_cout);
            string actual_output = captured_output.str();
            string expected_output = "\n";
            CHECK(expected_output == actual_output);
        }
    }

    SUBCASE("Check CopyNodes after Deleting Main Linked List") {
        SUBCASE("input 5"){
            list.build_node_list(5);
            vector<LinkedList::CopyNode> copyNodes = list.build_copyNodes_weak_ptrs();
            list.delete_node_shared_ptr_list();
            stringstream captured_output;
            streambuf* original_cout = cout.rdbuf(captured_output.rdbuf());
            list.print_node_array_weak_ptrs(copyNodes);
            cout.rdbuf(original_cout);
            string actual_output = captured_output.str();
            string expected_output = "nullptr nullptr nullptr nullptr nullptr \n";
            CHECK(expected_output == actual_output);
        }
        SUBCASE("input 1"){
            list.build_node_list(1);
            vector<LinkedList::CopyNode> copyNodes = list.build_copyNodes_weak_ptrs();
            list.delete_node_shared_ptr_list();
            stringstream captured_output;
            streambuf* original_cout = cout.rdbuf(captured_output.rdbuf());
            list.print_node_array_weak_ptrs(copyNodes);
            cout.rdbuf(original_cout);
            string actual_output = captured_output.str();
            string expected_output = "nullptr \n";
            CHECK(expected_output == actual_output);
        }
        SUBCASE("input 3"){
            list.build_node_list(3);
            vector<LinkedList::CopyNode> copyNodes = list.build_copyNodes_weak_ptrs();
            list.delete_node_shared_ptr_list();
            stringstream captured_output;
            streambuf* original_cout = cout.rdbuf(captured_output.rdbuf());
            list.print_node_array_weak_ptrs(copyNodes);
            cout.rdbuf(original_cout);
            string actual_output = captured_output.str();
            string expected_output = "nullptr nullptr nullptr \n";
            CHECK(expected_output == actual_output);
        }
    }

    SUBCASE("Check CopyNodes with Empty Main Linked List") {
        vector<LinkedList::CopyNode> copyNodes = list.build_copyNodes_weak_ptrs();
        stringstream captured_output;
        streambuf* original_cout = cout.rdbuf(captured_output.rdbuf());
        list.print_node_array_weak_ptrs(copyNodes);
        cout.rdbuf(original_cout);
        string actual_output = captured_output.str();
        string expected_output = "\n";
        CHECK(expected_output == actual_output);
    }

    SUBCASE("Check CopyNodes with Main Linked List After Deletion") {
        list.build_node_list(5);
        vector<LinkedList::CopyNode> copyNodes = list.build_copyNodes_weak_ptrs();
        list.delete_node_shared_ptr_list();
        vector<LinkedList::CopyNode> copyNodesAfterDeletion = list.build_copyNodes_weak_ptrs();
        CHECK(copyNodesAfterDeletion.empty());
    }

    SUBCASE("Build Main Linked List with Zero Nodes") {
        list.build_node_list(0);
        stringstream captured_output;
        streambuf* original_cout = cout.rdbuf(captured_output.rdbuf());
        list.print_node_list_shared_ptrs();
        cout.rdbuf(original_cout);
        string actual_output = captured_output.str();
        string expected_output = "\n";
        CHECK(expected_output == actual_output);
    }

    SUBCASE("Build CopyNodes with Zero Nodes in Main Linked List") {
        list.build_node_list(0);
        stringstream captured_output;
        streambuf* original_cout = cout.rdbuf(captured_output.rdbuf());
        list.print_node_array_weak_ptrs(list.build_copyNodes_weak_ptrs());
        cout.rdbuf(original_cout);
        string actual_output = captured_output.str();
        string expected_output = "\n";
        CHECK(expected_output == actual_output);
    }
}
