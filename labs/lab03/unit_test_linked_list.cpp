#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "linked_list.h"


TEST_CASE("Testing build_new_linked_list function") {
    SUBCASE("Test with total_new_elements = 0") {
        node *result = build_new_linked_list(0);
        CHECK(result == nullptr);
    }

    SUBCASE("Test with total_new_elements = 5") {
        int total_new_elements = 5;
        node *result = build_new_linked_list(total_new_elements);
        CHECK(result != nullptr);

        // Verify the first node
        CHECK(result->data == 1);

        // Verify the last node
        node *current = result;
        for (int i = 1; i < total_new_elements; ++i) {
            CHECK(current->jumper != nullptr);
            current = current->jumper;
        }
        CHECK(current->jumper->data == 5);
    }
}

TEST_CASE("Testing get_linked_list_data_item_value function") {
    int total_elements = 5;
    node *linked_list = build_new_linked_list(total_elements);

    SUBCASE("Test with valid node number") {
        int node_number = 3;
        int expected_data = node_number;
        int result = get_linked_list_data_item_value(linked_list, node_number, total_elements);
        CHECK(result == expected_data);
    }

    SUBCASE("Test with invalid node number") {
        int node_number = 10; 
        int result = get_linked_list_data_item_value(linked_list, node_number, total_elements);
        CHECK(result == -1);
    }

    delete_linked_list(linked_list, total_elements);
}

TEST_CASE("Testing update_data_in_linked_list function") {
    int total_elements = 5;
    node *linked_list = build_new_linked_list(total_elements);

    SUBCASE("Test with valid node to update") {
        int node_to_update = 3;
        int update_val = 99;
        bool result = update_data_in_linked_list(linked_list, node_to_update, update_val, total_elements);
        CHECK(result == true);

        // verify
        int updated_data = get_linked_list_data_item_value(linked_list, node_to_update, total_elements);
        CHECK(updated_data == update_val);
    }

    SUBCASE("Test with invalid node to update") {
        int node_to_update = 10; 
        int update_val = 99;
        bool result = update_data_in_linked_list(linked_list, node_to_update, update_val, total_elements);
        CHECK(result == false);
    }

    delete_linked_list(linked_list, total_elements);
}
