#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>


#include "double_vector.h"
#include "distance.h"


using namespace std;


vector<double_vector> read_from_file(const string& fileName){
    vector<double_vector> my_double_vector;

    ifstream in_file;
    in_file.open(fileName);

    int id = 0;
    double from, to;
    while (in_file >> from >> to){
        double_vector d_vector = double_vector(from, to, id++);
        my_double_vector.push_back(d_vector);   
    }

    in_file.close();

    return my_double_vector;
}


double square(const double & d){
    return d*d;
}

double dot_product(const double_vector & one, const double_vector & two) {
    return one.x* two.x + one.y* two.y;
}

double magnitude(const double_vector & my_vector) {
    return sqrt(square(my_vector.x) + square(my_vector.y));
};


double cosine_distance(const double_vector & one, const double_vector & two) {
    double dot_prod = dot_product(one,two);
    double one_magnitude = magnitude(one);
    double two_magnitude = magnitude(two);

    double d = dot_prod/(one_magnitude*two_magnitude) ;
    if (d > 1.0) {
        d = 1.0;
    }
    else if (d < -1.0){
        d = -1.0;
    }

    return acos(d);
}

vector<my_distance> all_pairs_distance(vector<double_vector> my_double_vector){
    int size = my_double_vector.size();

    vector<my_distance> all_pairs_distance;

    for(int i = 0; i < size; i++){
        for (int j = 0; j < size ; j++){
            if (i != j){
                my_distance my_distance1(i, j, cosine_distance(my_double_vector[i], my_double_vector[j]));
                all_pairs_distance.push_back(my_distance1);
            }
        }
    }

    sort(all_pairs_distance.begin(), all_pairs_distance.end(), 
        [](const my_distance & left, const my_distance & right) -> bool {
            return left.cos_distance > right.cos_distance;
        });

    return all_pairs_distance;
}

