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


void evens(const vector<int> & vect) {
  for_each(vect.begin(), vect.end(),
	   [](int elt) 
	   { if (elt % 2 == 0) { cout << elt << " "; } } );
    cout << endl;
}

void divides_by(const vector<int> & vect, const int & d ) {
  for_each(vect.begin(), vect.end(),
	   [d](int elt) 
	   { if (elt % d == 0) { cout << elt << " "; } } );
    cout << endl;
}

void divides_by_then_set_d_1(const vector<int> & vect, int & d ) {
  for_each(vect.begin(), vect.end(),
	   [&d](int elt) mutable
	   { cout << elt << " ";
	     d = 1; } );
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
       [](const int & left, const int & right) {
	 return left > right;
       });

  for (auto v : vect) {
    cout << v << " " ;
  }  
  cout << endl;

  display(vect);

  evens(vect);

  divides_by(vect,2);
  divides_by(vect,3);

  int d = 3;
  divides_by_then_set_d_1(vect,d);
  cout << "d = " << d << endl;

  return 0;
}