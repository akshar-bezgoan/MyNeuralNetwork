#include "matrix.hpp"
#include <iostream>

int main(){
    math::Matrix A(2,2);
    A(0,0) = 2;
    A(0,1) = 3;
    A(1,0) = 9;
    A(1,1) = 7;

    math::Matrix B(2,2);
    B(0,0) = 9;
    B(0,1) = 4;
    B(1,0) = 3;
    B(1,1) = 6;
    
    std::cout << "Matrix A:" << std::endl;
    std::cout << A << std::endl;
    /*
    * std::cout << "Matrix B:" << std::endl;
    * std::cout << B << std::endl;
    * std::cout << "Matrix A + B:" << std::endl;
    * std::cout << A+B << std::endl;
    * std::cout << "Matrix A - B" << std::endl;
    * std::cout << A-B << std::endl;
    */
    std::cout << "Matrix A * 5" << std::endl;
    std::cout << A*5.0 << std::endl;
    return 0;
}
