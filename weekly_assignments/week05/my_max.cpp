#include <iostream>

using namespace std;


template<typename T>
T my_max(const T & x, const T & y) {
    return (x > y) ? x : y;
}


int main() {
    // The max returns a float, but it is cast into an int??
    int z = my_max(3.009, 2.0);

    cout << z << endl;

}