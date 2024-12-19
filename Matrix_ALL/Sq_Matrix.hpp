
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
    SquareMatrix& operator+=(const SquareMatrix& other_);
    SquareMatrix Pow11(int power_);
    friend ostream& operator <<(ostream& stream, SquareMatrix& mat);
    friend istream& operator >>(istream& in_, SquareMatrix& mat);
    friend ifstream& operator>>(ifstream& in_, SquareMatrix& mat);

};
Vector Maxfromdiag(SquareMatrix matrix);
Vector tracematrix(SquareMatrix& matrix, int n);
ostream& operator <<(ostream& stream, SquareMatrix& mat);
istream& operator >>(istream& in_, SquareMatrix& mat);
ifstream& operator>>(ifstream& in_, SquareMatrix& mat);
