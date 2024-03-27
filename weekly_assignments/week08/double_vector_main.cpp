#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>

#include "double_vector.h"
#include "distance.h"

using namespace std;

int main(){
    vector<double_vector> my_double_vector;
    vector<my_distance> all_pairs;

    my_double_vector = read_from_file("vectors_2D.txt");

    for (auto vect : my_double_vector){
        cout << vect.x << " " << vect.y << " " << "cos dist w itself: " << cosine_distance(vect, vect) << endl;
    }
    cout << endl;

    all_pairs = all_pairs_distance(my_double_vector);

    for (auto dist : all_pairs){
        cout << dist.id_1 << " " << dist.id_2 << " " << "cos dist = " << dist.cos_distance << endl;
    }

    cout << endl;


     
}