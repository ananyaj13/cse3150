#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
public:
    Matrix(int size); // Assuming a square matrix
    void initialize(const std::vector<std::vector<int>>& D_minus_1, const std::vector<std::vector<int>>& D_0, const std::vector<std::vector<int>>& D_1);
    Matrix multiply(const Matrix& other) const;
    void normalize(int n);
    double getElement(int row, int col) const;

private:
    std::vector<std::vector<double>> data;
    int size;
    double fractionalPart(double value) const;
    int truncate(double value) const;
    bool detectNegativeOneEdge(double edgeCost, int n) const;
    bool detectPositiveOneEdge(double edgeCost, int n) const;
    bool detectZeroEdge(double edgeCost, int n) const;
};

#endif
