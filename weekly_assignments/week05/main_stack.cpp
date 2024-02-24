#include <iostream>

#include "MyStack.h"



int main() {

    using namespace std;
    
    MyStack<int> mstack;

    mstack.push(1);

    cout << mstack.top() << endl;

    return 0;
}