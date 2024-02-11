#include <iostream>
#include <stack>
#include <fstream>
#include "file_io.h"
 
using namespace std;

stack<node> reading_file(string file_name) {

  ifstream input_file;
  input_file.open(file_name);
  stack<node> s;

  while (!input_file.eof()) {
    string in_str;
    input_file >> in_str;
    int x = stoi(in_str);
    node my_node;
    my_node.number = x;
    s.push(my_node);
    cout << x << endl;
  }

  input_file.close();

  return s;  
}