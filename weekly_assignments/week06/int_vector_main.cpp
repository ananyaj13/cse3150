#include <iostream>
#include <fstream>
#include <vector>
#include "int_vector.h"

using namespace std;

int main() {
    vector<int_vector> vectors = readVectorsFromFile("vectors_2D.txt");

    // Print vectors in reverse order
    for (int i = vectors.size() - 1; i >= 0; --i) {
        cout << vectors[i] << endl;
    }

    return 0;
}