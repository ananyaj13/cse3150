#include <iostream>
#include "linked_list.h"

using namespace std;

int main() {

    struct node * linked_list_one_elt = build_new_linked_list(5);
    // print_linked_list(linked_list_one_elt,4);
    int a = get_linked_list_data_item_value(linked_list_one_elt, 4, 5);

    cout << a << endl;

    bool b = delete_linked_list(linked_list_one_elt);
    cout << b << endl;
    // print_linked_list(linked_list_one_elt,2);

    return 0;
}