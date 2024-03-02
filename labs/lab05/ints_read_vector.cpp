#include <istream>
#include <sstream>
#include <vector>

#include "ints_read_vector.h"

using namespace std;


vector<int> ints_read_vector(istream & in_stream) {
    vector<int> res;
    for(int i; in_stream >> i; ) {
        res.push_back(i);
    }

    return res;
}


vector<int> ints_read_one_line(istream & in_stream) {
    vector<int> res;
    string line;
    
    getline(in_stream, line);
    istringstream is(line);
    string next;
    while (is >> next) {
        res.push_back(stoi(next));
    }

    return res;
}

vector<int> ints_read(istream & in_stream) {
    vector<int> res;
    for(int i; in_stream >> i; ) {
        res.push_back(i);
    }

    if (in_stream.eof())
        return res;
    
    if (in_stream.fail()) {
        in_stream.clear();
        string s;
        if (in_stream >> s) {
            return res;
        }
        in_stream.setstate(ios_base::failbit);
    }
  
    return res;

};


// vector<int> ints_read(istream & in_stream, const string & terminal) {
//     vector<int> res;
//     for(int i; in_stream >> i && std::to_string(i) != terminal; ) {
//         res.push_back(i);
//     }

//     if (in_stream.eof())
//         return res;
    
//     if (in_stream.fail()) {
//         in_stream.clear();
//         string s;
//         if (in_stream >> s && s == terminal) {
//             return res;
//         }
//         in_stream.setstate(ios_base::failbit);
//     }
  
//     return res;

// };


