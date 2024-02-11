#include <iostream>
#include <queue>
#include <string>

#include "queue_1.h"

using namespace std;


string names[]  = {"S. Ulam", "Alan Turing", "C. Babbage", "Grace Hopper", "Ada Lovelace"};

queue<node_2> get_queue_node(const int n) {
  queue<node_2> q;

  for (int i=0; i < n; i++) {
    if (i >= sizeof(names)) {
      node_2 my_node;
      my_node.name = "Plato";
      my_node.number = i;
      
      q.push(my_node);
    } else {
      node_2 my_node;
      my_node.name = names[i];
      my_node.number = i;
      
      q.push(my_node);
    }
  }

  return q;
}

queue<int> get_queue(const int n) {

  queue<int> q;

  for (int i=0; i < n; i++) {
    q.push(i);
  }

  return q;
}