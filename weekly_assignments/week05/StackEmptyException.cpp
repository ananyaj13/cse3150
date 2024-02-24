#include <iostream>
#include <string>

#include "StackEmptyException.h"


using namespace std;


char * StackEmptyException::what() {
    return message;
}