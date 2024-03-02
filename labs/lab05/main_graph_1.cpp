#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

#include "ints_read.h"
#include "ints_write.h"



int main() {

    using namespace std;

    ifstream in_file;
    in_file.open("vector.txt");

    vector<int> my_vector;
    my_vector = ints_read(in_file);

    cout << my_vector << endl;
    in_file.close();

    return 0;
}