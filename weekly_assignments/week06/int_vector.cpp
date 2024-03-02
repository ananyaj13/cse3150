#include <iostream>
#include <fstream>
#include <vector>
#include "int_vector.h"

using namespace std;


ostream &operator<<(ostream &os, const int_vector &my_vector) {
    os << my_vector.id << ": ";
    os << my_vector.x << " " << my_vector.y;
    return os;
}

vector<int_vector> readVectorsFromFile(const string& filename) {
    ifstream file(filename);
    vector<int_vector> vectors;

    int id = 0;
    int x, y;

    while (file >> x >> y) {
        int_vector iv(id++, x, y, 2); // Assuming each vector has size 2
        vectors.push_back(iv);
        // cout << iv << endl;
    }

    // for (int_vector element : vectors){
    //     cout << element << endl;
    // }
    // cout << endl;

    return vectors;
}

