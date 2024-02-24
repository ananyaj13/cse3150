#include <iostream>
#include <cstring>

#include "MyStack.h"

using namespace std;

template<typename T>
MyStack<T>::MyStack() {
    topOfStack = 0;
}

template<typename T>
bool MyStack<T>::isEmpty() {
    if (0 == topOfStack) {
        return true;
    } else {
        return false;
    }
};

template<typename T>
void MyStack<T>::push(T e) {
    topOfStack += 1;
    my_arr[topOfStack] = e;
};

template<typename T>
void MyStack<T>::pop () {
    try {
        topOfStack -= 1;
        cout << topOfStack << endl;
        if (topOfStack < 0) {
            string s = "pop empty stack";
            char * msg = new char[s.size()+1];
            strcpy(msg, s.c_str());
            throw StackEmptyException( msg );
        }
    } catch ( StackEmptyException & ex ) {
        cerr << ex.what() << endl;
    }
};


template<typename T>
T MyStack<T>::top() {
    return my_arr[topOfStack];
}

template<typename T>
int  MyStack<T>::size() {
    return topOfStack;
};