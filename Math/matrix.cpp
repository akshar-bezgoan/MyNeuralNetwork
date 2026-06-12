#include <iostream>
#include "matrix.hpp"


math::Matrix::Matrix(size_t r, size_t c){
    rows_ = r;
    cols_ = c;
    data_.resize(rows_ * cols_);
}

const size_t math::Matrix::index(size_t r, size_t c) const{
    return r * cols_ + c;
}

double& math::Matrix::operator()(size_t r, size_t c){
    return data_[index(r,c)];
}

const double& math::Matrix::operator()(size_t r, size_t c) const{
    return data_[index(r,c)];
}

math::Matrix math::Matrix::operator+(const Matrix& B) const {
    if (rows_ != B.rows_ || cols_ != B.cols_) {
        throw std::invalid_argument("Matrix dimensions must match");
    }

    Matrix C(rows_, cols_);

    size_t N = data_.size();

    unsigned int T = std::thread::hardware_concurrency();

    if (T == 0) T = 4;
    std::vector<std::thread> threads;
    threads.reserve(T);
    size_t chunk = (N + T - 1) / T;

    for (unsigned int t = 0; t < T; t++) {
        size_t start = t * chunk;
        size_t end = std::min(start + chunk, N);
        threads.emplace_back([this, &B, &C, start, end]() {
            for (size_t i = start; i < end; i++) {
                C.data_[i] = this->data_[i] + B.data_[i];
            }
        });
    }

    for (auto& th : threads) {
        th.join();
    }

    return C;
}

math::Matrix math::Matrix::operator-(const Matrix& B) const {
    if (rows_ != B.rows_ || cols_ != B.cols_) {
        throw std::invalid_argument("Matrix dimensions must match");
    }

    Matrix C(rows_, cols_);

    size_t N = data_.size();

    unsigned int T = std::thread::hardware_concurrency();

    if (T == 0) T = 4;
    std::vector<std::thread> threads;
    threads.reserve(T);
    size_t chunk = (N + T - 1) / T;

    for (unsigned int t = 0; t < T; t++) {
        size_t start = t * chunk;
        size_t end = std::min(start + chunk, N);
        threads.emplace_back([this, &B, &C, start, end]() {
            for (size_t i = start; i < end; i++) {
                C.data_[i] = this->data_[i] - B.data_[i];
            }
        });
    }

    for (auto& th : threads) {
        th.join();
    }

    return C;
}

std::ostream& math::operator<<(std::ostream& os, const Matrix& m){
    for (size_t r = 0; r < m.rows_; r++) {
        for (size_t c = 0; c < m.cols_; c++) {
            os << m(r, c) << " ";
        }
        os << "\n";
    }

    return os;
}