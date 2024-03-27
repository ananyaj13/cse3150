#ifndef _DOUBLE_VECTOR_H_
#define _DOUBLE_VECTOR_H_

#include <iostream>
#include <cmath>
#include <vector>
#include "distance.h"


using namespace std;

struct double_vector {
    int id;
    double x;
    double y;
    
    double_vector(const double_vector & dv) : x(dv.x), y(dv.y), id(dv.id) {
    };
    
    double_vector() : x(0.0), y(0.0), id(0) {};
    double_vector(double x, double y, int id) :  x(x), y(y), id(id) {};
};




/**/
vector<double_vector> read_from_file(const string& in_file);
double square(const double & d);
double dot_product(const double_vector & one, const double_vector & two) ;
double magnitude(const double_vector & my_vector);
double cosine_distance(const double_vector & one, const double_vector & two);
vector<my_distance> all_pairs_distance(vector<double_vector> my_double_vector);




#endif