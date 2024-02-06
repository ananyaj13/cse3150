#include "fisher_yates.h"
#include "rand_array.h"
#include <iostream>

using namespace std;

int main(){
    string n_string;
    cout << "Enter a value 'n': " << endl;
    cin >> n_string;

    int n;
    n = stoi(n_string);

    int* arr = createArray(n);

    //running a thousand instances to check the ratio
    double oof = thousand_instances(arr, 2*n);

    delete[] arr;

    return 0;

}