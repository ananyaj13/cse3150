#ifndef __STACK_1_H
#define __STACK_1_H

#include <queue>

using namespace std;

struct node_2 {
  string name;
  int number;
};


queue<int> get_queue(const int n);
queue<node_2> get_queue_node(const int n);

#endif