#ifndef __STACK_1_H
#define __STACK_1_H

#include <stack>

using namespace std;

struct node_2 {
  string name;
  int number;
};


stack<int> get_stack(const int n);
stack<node_2> get_stack_node(const int n);

#endif