#pragma once
#include <sstream>
using namespace std;

class vect2
{
	private:
		int x, y;

	public:
		vect2();
		~vect2();
		vect2(const int n1, const int n2);
		vect2(const vect2 &v);
		vect2 &operator=(const vect2 &v);

		bool operator==(const vect2 &v) const;
		bool operator!=(const vect2 &v) const;

		int operator[](const int n) const;
		int &operator[](const int n);

		vect2 operator+(const vect2 &v) const;
		vect2 operator-(const vect2 &v) const;
		vect2 operator*(const vect2 &v) const;

		vect2 operator+=(const vect2 &v);
		vect2 operator-=(const vect2 &v);
		vect2 operator*=(const vect2 &v);

		vect2 &operator++(); //önce
		vect2 operator++(int n);
		vect2 &operator--(); //önce
		vect2 operator--(int n);

		vect2 operator-() const;
		vect2 operator*(const int n) const;
		vect2 &operator*=(const int n);

};
vect2 operator*(const int n, const vect2 &v);
ostream &operator<<(ostream &os, const vect2 &v);
