#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>


#include "double_vector.h"
#include "distance.h"


using namespace std;

 
vector<double_vector> read_from_file(const string& fileName) {
    vector<double_vector> my_double_vector;

    ifstream in_file(fileName);
    if (!in_file.is_open()) {
        cerr << "Error opening file " << fileName << endl;
        return my_double_vector;
    }

    int id = 0;
    string line;
    while (getline(in_file, line)) {
        istringstream iss(line);
        double val;
        vector<double> vals;
        while (iss >> val) {
            vals.push_back(val);
        }
        my_double_vector.push_back(double_vector(vals, id++));
    }

    in_file.close();

    return my_double_vector;
}


double square(const double & d){
    return d*d;
}

double dot_product(const double_vector& one, const double_vector& two) {
    double result = 0.0;
    const vector<double>& vec1 = one.all_vals[0];
    const vector<double>& vec2 = two.all_vals[0];

    for (size_t i = 0; i < vec1.size(); ++i) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

double magnitude(const double_vector& my_vector) {
    const vector<double>& coords = my_vector.all_vals[0];
    double result = 0.0;
    for (double coord : coords) {
        result += coord * coord;
    }
    return sqrt(result);
}


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

vector<my_distance> all_pairs_distance(const vector<double_vector>& my_double_vector) {
    int size = my_double_vector.size();

    vector<my_distance> all_pairs_distance;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) { 
            my_distance my_distance1(i, j, cosine_distance(my_double_vector[i], my_double_vector[j]));
            all_pairs_distance.push_back(my_distance1);
        }
    }

    sort(all_pairs_distance.begin(), all_pairs_distance.end(),
        [](const my_distance& left, const my_distance& right) -> bool {
            return left.cos_distance > right.cos_distance;
        });

    return all_pairs_distance;
}


