#include <iostream>
#include <vector>
#include "expensive_diagraph.h"

using namespace std;

void updateD_0(vector<vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_1, int i, int j, int k) {
    if (((D_minus_1[i][k] + D_1[k][j]) == 0) || ((D_1[i][k] + D_minus_1[k][j]) == 0))
        D_0[i][j] = 0;
}

void updateD_1(vector<vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_1, int i, int j, int k) {
    if (((D_1[i][k] + D_1[k][j]) == 1) || ((D_0[i][k] + D_1[k][j]) == 1))
        D_1[i][j] = 1;
}

void updateD_minus_1(vector<vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_1, int i, int j, int k) {
    if (((D_minus_1[i][k] + D_0[k][j]) == -1) || ((D_0[i][k] + D_minus_1[k][j]) == -1))
        D_minus_1[i][j] = -1;
    // cout << (D_minus_1[i][k] + D_0[k][j]) << endl;
    // cout << ((D_0[i][k] + D_minus_1[k][j]) == -1) << endl;
}

void expensiveDigraphExactPaths(vector<vector<int>>& D_minus_1, vector<vector<int>>& D_0, vector<vector<int>>& D_1) {
    int n = D_0.size();
    
    for (int l = 2; l <= 3 * n * n + 1; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    updateD_0(D_minus_1, D_0, D_1, i, j, k);
                    updateD_1(D_minus_1, D_0, D_1, i, j, k);
                    updateD_minus_1(D_minus_1, D_0, D_1, i, j, k);
                    
                }
            }
        }
    }
}