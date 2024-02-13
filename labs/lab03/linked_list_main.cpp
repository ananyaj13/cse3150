#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {
    int total_elements = 5;

    // Build a new linked list with 5 elements
    node *linked_list = build_new_linked_list(total_elements);

    // Print the linked list
    cout << "Linked List after creation:" << endl;
    print_linked_list(linked_list, total_elements);

    // Update data in the linked list
    int node_to_update = 3;
    int update_val = 99;
    bool update_result = update_data_in_linked_list(linked_list, node_to_update, update_val, total_elements);
    if (update_result) {
        cout << "Data in node " << node_to_update << " updated successfully." << endl;
    } else {
        cout << "Failed to update data in node " << node_to_update << "." << endl;
    }

    // Print the linked list after update
    cout << "Linked List after update:" << endl;
    print_linked_list(linked_list, total_elements);

    // Get data from a specific node
    int node_number = 2;
    int node_data = get_linked_list_data_item_value(linked_list, node_number, total_elements);
    if (node_data != -1) {
        cout << "Data in node " << node_number << " is: " << node_data << endl;
    } else {
        cout << "Node " << node_number << " doesn't exist." << endl;
    }

    // Delete the linked list to free memory
    delete_linked_list(linked_list, total_elements);

    return 0;
}
