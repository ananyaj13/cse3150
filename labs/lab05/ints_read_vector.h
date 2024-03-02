#ifndef _INTS_READ_H_
#define _INTS_READ_H_

#include <istream>
#include <vector>

using namespace std;

vector<int> ints_read_vector(istream & in_stream);
// vector<int> ints_read(istream & in_stream, const string & terminal);

vector<int> ints_read(istream & in_stream);
vector<int> ints_read_one_line(istream & in_stream);

#endif