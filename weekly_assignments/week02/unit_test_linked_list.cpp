#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "linked_list.h"



int zero_linked_list_elts = 0;
struct node * zero_linked_list_elts_null_node = NULL;
struct node * zero_linked_list = build_new_linked_list(0);

int one_element_linked_list = 1;
int data_value_of_initial_linked_list_elt = 1;
struct node * linked_list_one_elt = build_new_linked_list(one_element_linked_list);

int two_element_linked_list = 2;
int data_value_of_second_elt = 2;
struct node * linked_list_two_elts = build_new_linked_list(two_element_linked_list);

int five_element_linked_list = 5;
int data_value_of_fourth_elt = 5;
struct node * linked_list_five_elts = build_new_linked_list(five_element_linked_list);


TEST_CASE("empty list"){
    //creating an empty list should return NULL
    SUBCASE("creating an empty linked tree"){
        CHECK_EQ(build_new_linked_list(zero_linked_list_elts), zero_linked_list_elts_null_node);
    }

    SUBCASE("getting values in empty list"){
        int empty_data = get_linked_list_data_item_value(zero_linked_list, 1, 0);
        CHECK(empty_data == -1);
    }

    SUBCASE("updating the empty list and checking the updated value"){
        bool result = update_data_in_linked_list(zero_linked_list, 1, 5, 0);
        CHECK(result == false);
        int empty_data_updated = get_linked_list_data_item_value(zero_linked_list, 1, 0);
        CHECK(empty_data_updated == -1);
    }

    SUBCASE("deleting the empty linked list without crashing"){
        //if the list deletes without crashing, then this case will pass 
        CHECK_NOTHROW(delete_linked_list(zero_linked_list));
    }

}

TEST_CASE("one element list"){

    SUBCASE("getting values in empty list"){
        int one_data = get_linked_list_data_item_value(linked_list_one_elt, 1, 1);
        CHECK(one_data == 1);
    }

    SUBCASE("updating the list and checking the updated value"){
        bool result = update_data_in_linked_list(linked_list_one_elt, 1, 5, 1);
        CHECK(result == true);
        int one_data_updated = get_linked_list_data_item_value(linked_list_one_elt, 1, 1);
        CHECK(one_data_updated == 5);
    }

    SUBCASE("deleting the empty linked list without crashing"){
        //if the list deletes without crashing, then this case will pass 
        CHECK_NOTHROW(delete_linked_list(linked_list_one_elt));
    }

}

TEST_CASE("two element list"){

    SUBCASE("getting values in  list"){
        int two_data = get_linked_list_data_item_value(linked_list_two_elts, 2, 2);
        CHECK(two_data == 2);
    }

    SUBCASE("updating the list and checking the updated value"){
        bool result = update_data_in_linked_list(linked_list_two_elts, 2, 1, 2);
        CHECK(result == true);
        int two_data_updated = get_linked_list_data_item_value(linked_list_two_elts, 2, 2);
        CHECK(two_data_updated == 1);


        result = update_data_in_linked_list(linked_list_two_elts, 1, 2, 2);
        CHECK(result == true);
        two_data_updated = get_linked_list_data_item_value(linked_list_two_elts, 1, 2);
        CHECK(two_data_updated == 2);
    }

    SUBCASE("deleting the linked list without crashing"){
        //if the list deletes without crashing, then this case will pass 
        CHCK_NOTHROW(delete_linked_list(linked_list_two_elts));
    }

}

TEST_CASE("five element list"){

    SUBCASE("getting values in list"){
        int five_data = get_linked_list_data_item_value(linked_list_five_elts, 5, 5);
        CHECK(five_data == 5);
    }

    SUBCASE("updating the list"){
        bool result = update_data_in_linked_list(linked_list_five_elts, 4, 100, 5);
        CHECK(result == true);
        int five_data_updated = get_linked_list_data_item_value(linked_list_five_elts, 4, 5);
        CHECK(five_data_updated == 100);

        result = update_data_in_linked_list(linked_list_five_elts, 1, 50, 5);
        CHECK(result == true);
        five_data_updated = get_linked_list_data_item_value(linked_list_five_elts, 1, 5);
        CHECK(five_data_updated == 50);

        result = update_data_in_linked_list(linked_list_five_elts, 2, 0, 5);
        CHECK(result == true);
        five_data_updated = get_linked_list_data_item_value(linked_list_five_elts, 2, 5);
        CHECK(five_data_updated == 0);

        result = update_data_in_linked_list(linked_list_five_elts, 5, 500, 5);
        CHECK(result == true);
        five_data_updated = get_linked_list_data_item_value(linked_list_five_elts, 5, 5);
        CHECK(five_data_updated == 500);
    }

    SUBCASE("deleting the linked list without crashing"){
        //if the list deletes without crashing, then this case will pass 
        CHECK_NOTHROW(delete_linked_list(linked_list_five_elts));
    }

}


