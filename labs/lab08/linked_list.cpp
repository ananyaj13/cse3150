#include <iostream>
#include <memory>
#include "linked_list.h"

using namespace std;

void LinkedList::build_node_list(int k){
    shared_ptr<Node> traverse = root;
    for (int i = 0; i < k; i++){
        traverse->next = make_shared<Node>(new Node( nodeCount++, nullptr));
        traverse = traverse->next;
        cout << i << endl;
    }
}

LinkedList::CopyNode * LinkedList::build_copyNodes_weak_ptrs(){
    CopyNode * copy_nodes = new CopyNode[nodeCount];
    shared_ptr<Node> traverse = root;
    for (int i = 0; i < nodeCount; i++){
        copy_nodes[i].weak_node_ptr = traverse;
        traverse = traverse->next;
    }

    if (!(nodeCount > 0)){
        // cout << "copy nodes is nullptr";
        copy_nodes = nullptr;
    }

    return copy_nodes;
}

void LinkedList::delete_node_shared_ptr_list() {
    shared_ptr<Node> traverse = root;
    int i = 0;
    while(traverse){
        shared_ptr<Node> next = traverse->next;
        traverse.reset();
        // traverse = std::move(traverse->next);
        traverse = next;
        cout << "DELETE : " << i << " ";
        i += 1;
    }
    root.reset();
    cout << endl;
}

void LinkedList::print_node_array_weak_ptrs(CopyNode* copyNodes) {

    if (copyNodes == nullptr){
        cout << "empty list of weak pointers" << endl;
    }
    
    for (int i = 0; i < nodeCount; i++){
        if (std::shared_ptr<Node> spt = copyNodes[i].weak_node_ptr.lock()){
            std::cout << "std == " << copyNodes[i].weak_node_ptr << endl;
        }
        else{
            cout << "the element at index " << i << " is expired\n";
        }
    }
}

void LinkedList::print_node_list_shared_ptrs(){
    if (root){
        if (nodeCount >= 1){
            shared_ptr<Node> myNext = root;
            for (int i = 0; i < nodeCount; i++){
                myNext = myNext->next;
                // cout << myNext->data;
                cout << myNext->next << endl;
            }
            cout << endl;
        }
        else{
            cout << "empty list shared pointer" << endl;
        }
    }
    else{
        cout << "expired shared pointer" << endl;
    }
    
}

LinkedList::LinkedList() {
    nodeCount = 0;
    root = make_shared<Node>(new Node());
}

LinkedList::~LinkedList() {}



