#include <iostream>
#include <memory>
#include "linked_list.h"

using namespace std;

int main() {
    // Create a LinkedList object
    cout << "list 1" << endl;
    LinkedList list;
    list.build_node_list(5);
    std::cout << "Printing linked list of shared_ptrs:" << std::endl;
    list.print_node_list_shared_ptrs();
    LinkedList::CopyNode *copyNodes = list.build_copyNodes_weak_ptrs();
    std::cout << "Printing linked list of weak_ptrs:" << std::endl;
    list.print_node_array_weak_ptrs(copyNodes);
    list.delete_node_shared_ptr_list();

    cout << endl;

    cout << "list 2" << endl;
    LinkedList list2;
    LinkedList::CopyNode *copyNodes2 = list2.build_copyNodes_weak_ptrs();
    list2.print_node_list_shared_ptrs(); 
    list2.print_node_array_weak_ptrs(copyNodes2); 

    cout << endl;

    cout << "list 3" << endl;
    LinkedList list3;
    list3.build_node_list(3);
    LinkedList::CopyNode *copyNodes3 = list3.build_copyNodes_weak_ptrs();
    list3.print_node_list_shared_ptrs(); 
    list3.print_node_array_weak_ptrs(copyNodes3); 

    cout << endl;

    cout << "list 4" << endl;
    LinkedList list4;
    list4.build_node_list(3);
    list4.print_node_list_shared_ptrs(); 
    LinkedList::CopyNode* copyNodes4 = list4.build_copyNodes_weak_ptrs();
    list4.delete_node_shared_ptr_list();
    list4.print_node_list_shared_ptrs(); // Expected output: expired shared pointer
    list4.print_node_array_weak_ptrs(copyNodes4); // Expected output: all pointers should be expired

    return 0;
}