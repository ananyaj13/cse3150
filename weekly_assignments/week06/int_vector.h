#ifndef _INT_VECTOR_H_
#define _INT_VECTOR_H_

#include <iostream>


using namespace std;

struct int_vector {
    int id;
    int x;
    int y;
    int my_size;
    int * values;
    /* */
    int_vector(const int_vector & iv) : id(iv.id), x(iv.x), y(iv.y),  my_size(iv.my_size) {
        /* */
        values = new int[my_size];
        for (int i = 0; i < my_size; i++) {
            values[i] = iv.values[i];
        }
        // cout << "In copy constructor" << endl;
    };
    

    int_vector(int id, int x, int y, int my_size) : id(id), x(x), y(y), my_size(my_size) {
        values = new int[my_size];
        for (int i = 0; i < my_size; i++) {
            values[i] = i;
        }
        // cout << "In constructor" << endl;
    };

    ~int_vector() {
        // cout << "destructor" << endl;
        delete [] values;
    }
};

vector<int_vector> readVectorsFromFile(const string& filename);
ostream &operator<<(ostream &os, const int_vector &my_vector);

#endif