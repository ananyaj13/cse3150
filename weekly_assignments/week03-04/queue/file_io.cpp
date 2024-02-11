#include <iostream>
#include <queue>
#include <fstream>
#include "file_io.h"

using namespace std;

queue<node> reading_file(string file_name) {

  ifstream input_file;
  input_file.open(file_name);
  queue<node> q;

  while (!input_file.eof()) {
    string in_str;
    input_file >> in_str;
    int x = stoi(in_str);
    node my_node;
    my_node.number = x;
    q.push(my_node); 
    cout << x << endl;
  }

  input_file.close();

  return q;  
}