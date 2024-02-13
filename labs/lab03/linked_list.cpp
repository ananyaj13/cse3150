#include <iostream>
#include "linked_list.h"
#include <stack>

using namespace std;

/*
build_new_linked_list:
	returns a pointer to the first node in the linked list
    If 0 == total_new_elements, then return null
*/
node * build_new_linked_list(int total_new_elements) {
    
    if (0 == total_new_elements) {
        return NULL;
    } 
    
    else {
        node* arr = new node[total_new_elements];
        struct node * root = &arr[0];

        for (int i = 0 ; i < total_new_elements; i++) { 
            struct node * linked_list = &arr[i];
            linked_list->data = i+1;
            linked_list->jumper = nullptr;
        }

        struct node * jump = &arr[ (total_new_elements-1) ];

        for (int j = 0; j < total_new_elements; j++){
            arr[j].jumper = jump;
        }

        return arr;
    }
}
/*
get_linked_list_data_item_value:

    returns -1 if not enough nodes
*/
int get_linked_list_data_item_value(node * arr, int node_number, int total_elements) {
    if (node_number > total_elements) {
        return -1;
    } else {
        struct node * linked_list = &arr[node_number - 1];

        // for (int i = 0; i < node_number -1; i++) {
        //     linked_list = linked_list->next;
        // }

        return linked_list->data;
    }
}

void print_linked_list(node * arr, int total_elements) {

    for (int i = 0; i < total_elements; i++) {
        struct node * linked_list =  &arr[i];
        cout << "linked list data: " << linked_list->data  << ", linked list jumper val: " << linked_list->jumper->data << endl;
    }
}

/*
update_data_in_linked_list:
	Returns false if node_to_update > total_elements
	Returns true otherwise
*/
bool update_data_in_linked_list(node * arr, int node_to_update, int update_val, int total_elements) {

    if (node_to_update <= total_elements){
        int  i = 0;
        struct node* linked_list = &arr[i];
        while (i < total_elements && linked_list->data != node_to_update) {
            i++;
            linked_list = &arr[i];
        }
        if (linked_list->data == node_to_update){
            linked_list->data = update_val;
            return true;
        }
        
    } 
    
    return false;
}

void delete_linked_list(node * arr, int total_elements){

    // for (int i = 0; i < total_elements; i++){
    //     delete &arr[i];
    // }

    delete[] arr;
    cout << "deleted" << endl;
}