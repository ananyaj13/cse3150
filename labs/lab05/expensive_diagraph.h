#ifndef _EXPENSIVE_DIAGRAPHS_H
#define _EXPENSIVE_DIAGRAPHS_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void updateD_0(vector<vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_1, int i, int j, int k);
void updateD_1(vector<vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_1, int i, int j, int k);
void updateD_minus_1(vector<vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_1, int i, int j, int k);

void expensiveDigraphExactPaths(vector<vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_1);

#endif