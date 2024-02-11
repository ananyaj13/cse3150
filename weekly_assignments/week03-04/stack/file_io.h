#ifndef _FILE_IO_H
#define _FILE_IO_H

#include <string>
#include <stack>

using namespace std;

struct node {
  int number;
};

stack<node> reading_file(string file_name);

#endif