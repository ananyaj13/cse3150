#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto square = [](int x) -> int {
    return x*x;
};

int main() {

    cout << square(3) << endl;

}