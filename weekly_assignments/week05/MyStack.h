#ifndef _MYSTACK_H_
#define _MYSTACK_H_

#include <iostream>
#include <cstring>

#include "StackEmptyException.h"

const int MAX_SIZE = 10 ;

template<typename T>
struct MyStack {

    private:
        T my_arr[MAX_SIZE] ;
        int topOfStack;
    public:
        MyStack();
        bool isEmpty() ;
        void push(T e) ;
        void pop();
        T top();
        int size();
} ;

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


#endif