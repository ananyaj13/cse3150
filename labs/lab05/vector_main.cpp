#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct int_vector {
  int id;
  int x;
  int y;
};


int main() {

  ifstream in_file;
  in_file.open("vectors_2D.txt");

  vector<int_vector> vect;

  int id{0};
  string x, y;
  while (in_file >> x >> y) {
    cout << x << " " << y << " " << endl;
    int_vector i_v;
    i_v.x = stoi(x);
    i_v.y = stoi(y);
    i_v.id = id++;
    vect.push_back(i_v);
  }
  cout << endl;
  cout << "------------------" << endl;

  for (auto v : vect) {
    cout << v.id << ": "  << v.x << " to " << v.y << endl;
  }

  cout << "------------------" << endl;
  cout << "Sorted:" << endl;
  
  sort(vect.begin(),
       vect.end(),
       [](const int_vector & left, const int_vector & right) {
	        return left.id > right.id;
       });

  for (auto v : vect) {
    cout << v.id << ": ("  << v.x << ", " << v.y << ") " << endl;
  }  
       
  in_file.close();

  return 0;
}