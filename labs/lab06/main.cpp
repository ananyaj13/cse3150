#include "Matrix.h"
#include <iostream>

int main() {
    std::vector<std::vector<int>> D_0 = {{0, 2, 2, 2},
                                 {2, 0, 2, 2},
                                 {2, 2, 0, 2},
                                 {2, 2, 2, 0}};

    std::vector<std::vector<int>> D_minus1 = {{-1, 2, 2, 2},
                                     {2, 2, 2, 2},
                                     {2, 2, 2, 2},
                                     {2, 2, 2, 2}};

    std::vector<std::vector<int>> D_plus1 = {{2, 1, 2, 2},
                                    {2, 2, 1, 2},
                                    {2, 2, 2, 1},
                                    {1, 2, 2, 2}};


    int n = D_0.size();
    
    Matrix graph(n);
    graph.initialize(D_minus1, D_0, D_plus1);
    Matrix result = graph.multiply(graph);
    result.normalize(n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << result.getElement(i, j) << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
