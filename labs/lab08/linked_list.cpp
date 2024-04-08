#include <iostream>
#include <memory>
#include "linked_list.h"
#include <vector>

using namespace std;

int main() {
    LinkedList list;

    list.build_node_list(5);
    cout << "Original Linked List: ";
    list.print_node_list_shared_ptrs();

    vector<LinkedList::CopyNode> copyNodes = list.build_copyNodes_weak_ptrs();

    cout << "Copy Nodes using weak_ptrs: ";
    list.print_node_array_weak_ptrs(copyNodes);
    cout << "Copy Nodes using weak_ptrs: ";
    list.print_node_array_weak_ptrs(copyNodes);

    // Deleting the main linked list
    list.delete_node_shared_ptr_list();
    cout << "After deleting the main linked list:" << endl;
    cout << "Original Linked List: ";
    list.print_node_list_shared_ptrs();
    cout << "Copy Nodes using weak_ptrs: ";
    list.print_node_array_weak_ptrs(copyNodes);

    return 0;
}