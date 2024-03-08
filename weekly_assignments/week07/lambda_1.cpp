#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(const vector<int> & vect) {
  for_each(vect.begin(), vect.end(),
	   [](int elt)
	   { cout << elt << " "; });
    cout << endl;
}


int main() {

  vector<int> vect = {3,999,1,2,17,13,-4,5,66,7,8};

  cout << "----input------------" << endl;
  for (auto v : vect) {
    cout << v << " " ;
  }
  cout << endl;

  cout << "------------------" << endl;
  
  sort(vect.begin(),
       vect.end(),
       [](const int & left, const int & right) -> bool {
	        return left > right;
       });

  for (auto v : vect) {
    cout << v << " " ;
  }  
  cout << endl;

  display(vect);

  return 0;
}