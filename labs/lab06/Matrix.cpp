#include "Matrix.h"
#include <cmath>
#include <iostream>

const double INFINITY_REPLACEMENT = 0;

Matrix::Matrix(int size) : size(size), data(size, std::vector<double>(size, INFINITY_REPLACEMENT)) {}

void Matrix::initialize(const std::vector<std::vector<int>>& D_minus_1, const std::vector<std::vector<int>>& D_0, const std::vector<std::vector<int>>& D_1) {
    int n = D_0.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (((D_minus_1[i][k] + D_1[k][j]) == 0) || ((D_1[i][k] + D_minus_1[k][j]) == 0)){
                    data[i][j] = 1.0;
                }
                if (((D_1[i][k] + D_0[k][j]) == 1) || ((D_0[i][k] + D_1[k][j]) == 1)){
                    data[i][j] = 3*(n+1);
                }
                if (((D_minus_1[i][k] + D_0[k][j]) == -1) || ((D_0[i][k] + D_minus_1[k][j]) == -1)){
                    data[i][j] = 1.0/(3*(n+1));
                }
            }
        }
    }

    // for (int i = 0; i < n; ++i){
    //     for (int j = 0; j < n; ++j){
    //         std::cout << data[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
}

Matrix Matrix::multiply(const Matrix& other) const {
    Matrix result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            double sum = 0;
            for (int k = 0; k < size; ++k) {
                double mul = data[i][k] * other.data[k][j];
                sum += mul;
            }
            result.data[i][j] = sum;
        }
    }

    // for (int i = 0; i < size; ++i){
    //     for (int j = 0; j < size; ++j){
    //         std::cout << result.data[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    return result;
}

void Matrix::normalize(int n) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (detectNegativeOneEdge(data[i][j], n)) {
                data[i][j] = -1;
            }
            else if (detectPositiveOneEdge(data[i][j], n)) {
                data[i][j] = 1;
            }
            else if (detectZeroEdge(data[i][j], n)) {
                data[i][j] = 0;
            }
        }
    }
}

double Matrix::fractionalPart(double value) const {
    return value - std::trunc(value);
}

int Matrix::truncate(double value) const {
    return static_cast<int>(value);
}

bool Matrix::detectNegativeOneEdge(double edgeCost, int n) const {
    double check = (3 * (n + 1)) * fractionalPart(edgeCost);
    return check >= 1 && check <= 2 * n;
}

bool Matrix::detectPositiveOneEdge(double edgeCost, int n) const {
    int check = truncate(edgeCost / (3 * (n + 1)));
    return check >= 1 && check <= 2 * n;
}

bool Matrix::detectZeroEdge(double edgeCost, int n) const {
    int check = truncate(edgeCost) % (3 * (n + 1));
    return check > 0 && check <= 3 * n;
}

double Matrix::getElement(int row, int col) const {
    return data[row][col];
}
