#pragma once
#include "Matrix.hpp" 
#include "Vector.hpp"

class SquareMatrix : public Matrix
{
public:
    SquareMatrix(int size = 2);
    SquareMatrix(const SquareMatrix& other);
    void Transpon();
    SquareMatrix& operator=(const SquareMatrix& other);
    SquareMatrix operator*(SquareMatrix other);
    SquareMatrix& operator^(int n);
    double trace();
    SquareMatrix& Arithmetic_mean();
    double Arif(SquareMatrix& mat, int r, int c);

};
Vector Maxfromdiag(SquareMatrix matrix);
Vector tracematrix(SquareMatrix& matrix, int n);
