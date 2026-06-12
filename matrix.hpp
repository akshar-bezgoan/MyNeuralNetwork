#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <stdexcept>
/*
* Matrix multiplication
* Transpose
* Random initialization
*/

namespace math{
    class Matrix{
    private:
        size_t rows_;
        size_t cols_;
        std::vector<double> data_;
        const size_t index(size_t r, size_t c) const;
    public:
        Matrix(size_t r, size_t c);
        double& operator()(size_t r, size_t c);
        const double& operator()(size_t r, size_t c) const;
        Matrix operator+(const Matrix& B) const;
        Matrix operator-(const Matrix& B) const;
        Matrix operator*(double s) const;
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

    };


}