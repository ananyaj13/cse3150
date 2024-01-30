#include <iostream>
#include "linked_list.h"

using namespace std;

/*
build_new_linked_list:
	returns a pointer to the first node in the linked list
    If 0 == total_new_elements, then return null
*/
struct node * build_new_linked_list(int total_new_elements) {
    if (0 == total_new_elements) {
        return NULL;
    } else {
        struct node * root = new node;
        root->data = -1;
        struct node * linked_list = root;

        for (int i = 0 ; i < total_new_elements; i++) {
            linked_list->next = new node;
            linked_list->data = i+1;
            linked_list = linked_list->next;
        }

        return root;
    }
}
/*
get_linked_list_data_item_value:

    returns -1 if not enough nodes
*/
int get_linked_list_data_item_value(struct node * start, int node_number, int total_elements) {
    if (node_number > total_elements) {
        return -1;
    } else {
        struct node * linked_list = start;

        for (int i = 0; i < node_number -1; i++) {
            linked_list = linked_list->next;
        }

        return linked_list->data;
    }
}

void print_linked_list(struct node * start, int total_elements) {
    struct node * linked_list =  start;

    for (int i = 0; i < total_elements; i++) {
        cout << linked_list->data << endl;
        linked_list = linked_list->next;
    }
}

/*
update_data_in_linked_list:
	Returns false if node_to_update > total_elements
	Returns true otherwise
*/
bool update_data_in_linked_list(struct node * start, int node_to_update, int update_val, int total_elements) {

    if (node_to_update <= total_elements){
        struct node * current = start;
        while (current != nullptr) {
            if (current->data == node_to_update) {
                current->data = update_val;
                return true;
            }
            current = current->next;
        }
    } 
    
    return false;
}

void delete_linked_list(struct node * start){
    struct node * current = start;
    struct node * prev;

    // bool status = false;

    while (current != nullptr){
        prev = current;
        current = current->next;
        delete prev;
    }
    // if (current == NULL){
    //     status = true;
    // }

}