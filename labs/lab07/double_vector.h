#ifndef _DOUBLE_VECTOR_H_
#define _DOUBLE_VECTOR_H_

#include <iostream>
#include <cmath>
#include <vector>
#include "distance.h"


using namespace std;

struct double_vector {
    int id;
    vector<vector<double>> all_vals; 
    
    double_vector(const double_vector & dv) : all_vals(dv.all_vals), id(dv.id) {};
    
    double_vector() : all_vals({}), id(0) {};
    double_vector(const vector<double>& vals, int id) : all_vals({vals}), id(id) {};
};



/**/
vector<double_vector> read_from_file(const string& in_file);
double square(const double & d);
double dot_product(const double_vector & one, const double_vector & two) ;
double magnitude(const double_vector & my_vector);
double cosine_distance(const double_vector & one, const double_vector & two);
vector<my_distance> all_pairs_distance(const vector<double_vector>& my_double_vector);




#endif