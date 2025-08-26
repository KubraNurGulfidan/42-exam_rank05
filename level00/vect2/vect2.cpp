#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}
vect2::~vect2() {}
vect2::vect2(const int n1, const int n2)
{
	this->x = n1;
	this->y = n2;
}
vect2::vect2(const vect2 &v)
{
	*this = v;
}
vect2 &vect2::operator=(const vect2 &v)
{
	if(this->x != v.x || this->y != v.y)
	{
		this->x = v.x;
		this->y = v.y;
	}
	return *this;
}

bool vect2::operator==(const vect2 &v) const
{
	if(this->x == v.x && this->y == v.y)
		return true;
	return false;
}
bool vect2::operator!=(const vect2 &v) const
{
	if(*this == v)
		return false;
	return true;
}

int vect2::operator[](const int n) const
{
	if(n == 0)
		return this->x;
	return this->y;
}
int &vect2::operator[](const int n)
{
	if(n == 0)
		return this->x;
	return this->y;
}

vect2 vect2::operator+(const vect2 &v) const
{
	return vect2(this->x + v.x, this->y + v.y);	
}
vect2 vect2::operator-(const vect2 &v) const
{
	return vect2(this->x - v.x, this->y - v.y);	
}
vect2 vect2::operator*(const vect2 &v) const
{
	return vect2(this->x * v.x, this->y * v.y);	
}

vect2 vect2::operator+=(const vect2 &v)
{
	*this = *this + v;
	return *this;	
}
vect2 vect2::operator-=(const vect2 &v)
{
	*this = *this - v;
	return *this;	
}
vect2 vect2::operator*=(const vect2 &v)
{
	*this = *this * v;
	return *this;	
}

vect2 &vect2::operator++()
{
	this->x++;
	this->y++;
	return *this;
} //önce
vect2 vect2::operator++(int n)
{
	vect2 temp = *this;
	this->x++;
	this->y++;
	return temp;
}
vect2 &vect2::operator--()
{
	this->x--;
	this->y--;
	return *this;
}  //önce
vect2 vect2::operator--(int n)
{
	vect2 temp = *this;
	this->x--;
	this->y--;
	return temp;
}

vect2 vect2::operator-() const
{
	return vect2(-this->x, -this->y);
}
vect2 vect2::operator*(const int n) const
{
	return vect2(this->x * n, this->y * n);
}
vect2 &vect2::operator*=(const int n)
{
	*this = *this * n;
	return *this;
}

vect2 operator*(const int n, const vect2 &v)
{
	return vect2(v[0] * n, v[1] * n);
}
ostream &operator<<(ostream &os, const vect2 &v)
{
	os << "{" << v[0] << ", " << v[1] << "}" << endl;
	return os;
}