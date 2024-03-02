#ifndef _MY_FIND_H_
#define _MY_FIND_H_

#include <iostream>
#include <vector>


bool greaterThan(const int & a, const int & b) {
    bool my_value;
    if (a - b > 0.005) {
        return true;
    } else {
        return false;
    }
}

template<typename T, bool (*cmp)(const T & a, const T & b)>
bool myfind(std::vector<T> x, int v) {
    int small = 0, large = x.size() -1;

    while (small <= large) {
        int mid = (small + large)/2;
        if (v == x[mid]) return true;
        else {
            bool lessThan = !cmp(v,x[mid]);
            if (lessThan) large = mid -1;
            else small = mid + 1;
        }
    }

    return false;
}



#endif