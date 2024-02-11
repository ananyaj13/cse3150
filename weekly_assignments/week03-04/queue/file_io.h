#ifndef _FILE_IO_H
#define _FILE_IO_H

#include <string>
#include <queue>

using namespace std;

struct node { 
  int number;
};

queue<node> reading_file(string file_name);

#endif 