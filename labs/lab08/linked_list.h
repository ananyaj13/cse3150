#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct LinkedList {
public:
    struct Node {
        int data;
        shared_ptr<Node> next;

        Node() : data(0), next(nullptr) {}
        Node(int val) : data(val), next(nullptr) {}
    };

    struct CopyNode {
        weak_ptr<Node> weak_node_ptr;

        CopyNode(shared_ptr<Node> ptr) : weak_node_ptr(ptr) {}
    };

    LinkedList() : root(nullptr), nodeCount(0) {}

    /* Builds the linked list of shared_ptrs */
    void build_node_list(int k) {
        if (k <= 0)
            return;

        root = make_shared<Node>(1);
        shared_ptr<Node> current = root;

        for (int i = 2; i <= k; ++i) {
            current->next = make_shared<Node>(i);
            current = current->next;
        }

        nodeCount = k;
    }

    /* Builds weak_ptrs to linked-list nodes */
    vector<CopyNode> build_copyNodes_weak_ptrs() {
        vector<CopyNode> copyNodes;
        shared_ptr<Node> current = root;

        for (int i = 0; i < nodeCount; ++i) {
            copyNodes.push_back(CopyNode(current));
            current = current->next;
        }

        return copyNodes;
    }

    /* Deletes the linked list of shared_ptrs */
    void delete_node_shared_ptr_list() {
        root = nullptr; // All shared_ptrs will be destroyed automatically
        nodeCount = 0;
    }

    /* Prints a linked list of shared_ptrs */
    void print_node_list_shared_ptrs() {
        shared_ptr<Node> current = root;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    /* Prints a linked list of weak_ptrs */
    void print_node_array_weak_ptrs(const vector<CopyNode>& copyNodes) {
        for (const auto& copyNode : copyNodes) {
            auto sharedPtr = copyNode.weak_node_ptr.lock();
            if (sharedPtr)
                cout << sharedPtr->data << " ";
            else
                cout << "nullptr ";
        }
        cout << endl;
    }

    ~LinkedList() {
        delete_node_shared_ptr_list();
    }

private:
    shared_ptr<Node> root;
    int nodeCount;
};
#endif