#pragma once
#include "matrix.hpp" 
#include "Vector.hpp"

class SquareMatrix : public Matrix
{
public:
    SquareMatrix(int size = 2);
    SquareMatrix(const SquareMatrix& other);
    void Transpon();
    SquareMatrix& operator=(const SquareMatrix& other);
    SquareMatrix pow(int n);
    SquareMatrix operator*(SquareMatrix other);
    SquareMatrix operator^(int n);
};
Vector Maxfromdiag(SquareMatrix matrix);
