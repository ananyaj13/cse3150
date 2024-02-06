#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_


struct node { 
	int data;
	struct node * next;
	struct node * tail;
};


struct node * build_new_linked_list(int total_new_elements);
int get_linked_list_data_item_value(struct node * start, int node_number, int total_elements);
void print_linked_list(struct node * start, int total_elements);

/*
update_data_in_linked_list:
	Returns false if node_to_update > total_elements
	Returns true otherwise
*/
bool update_data_in_linked_list(struct node * start, 
    int node_to_update, 
    int update_val, 
    int total_elements);

// deleting linked list:
void delete_linked_list(struct node * start);

#endif
