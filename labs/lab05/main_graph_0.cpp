#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

std::ostream &operator<<(std::ostream &os, const std::vector<int> &input)
{
    for (auto const & i: input) {
        os << i << " ";
    }
    return os;
}

int main() {
    using namespace std;

    ifstream in_file;
    
    in_file.open("vector.txt");

    vector<int> my_vector;

    for (string str; in_file >> str;) {
        my_vector.push_back(stoi(str));
    }
    cout << my_vector << endl;
  
    in_file.close();

    return 0;
}