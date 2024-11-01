#pragma once
#include <iostream>
#pragma once

class Vector
{
	double* elements;
	size_t size;
	size_t capasity;

public:

	void Set_elem(int index, double elem);

	void Print_elem();

	Vector(double* elements_ = nullptr, size_t size_ = 0);

	Vector(Vector& other_);

	Vector(size_t size_);

	Vector operator+(const Vector& other_) const;

	Vector& operator=(const Vector& other_);

	Vector& operator+=(const Vector& other_);

	double operator*(const Vector& other_);

	Vector operator&(const Vector& other_);

	Vector& operator&=(const Vector& other_);

	bool operator==(const Vector& other_);

	bool operator!=(const Vector& other_);

	bool operator!();

	double& operator[](int index_);

	void Push_Back(double elem_);

	void Print_Vectors();
};