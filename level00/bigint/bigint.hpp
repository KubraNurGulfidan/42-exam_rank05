#pragma once
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class bigint
{
	private:
		string numbers;
		void removeZeros();
		string addNumbers(const string &s1, const string &s2) const;
	public:
		bigint();
		~bigint();
		bigint(const string &str);
		bigint(unsigned int n);
		bigint(const bigint &big);
		bigint &operator=(const bigint &big);

		bigint operator+(const bigint &big) const;
		bigint &operator+=(const bigint &big);
		bigint &operator++(); //önce arttır
		bigint operator++(int n);

		bigint operator<<(const int n);
		bigint operator>>(const int n);
		bigint operator<<=(const int n);
		bigint operator>>=(const int n);

		bigint operator<<(const bigint &big);
		bigint operator>>(const bigint &big);
		bigint operator<<=(const bigint &big);
		bigint operator>>=(const bigint &big);

		bool operator<(const bigint &big) const;
		bool operator>(const bigint &big) const;
		bool operator<=(const bigint &big) const;
		bool operator>=(const bigint &big) const;
		bool operator==(const bigint &big) const;
		bool operator!=(const bigint &big) const;

		string getNumbers() const {return numbers;}
};

ostream &operator<<(ostream &os, const bigint &big);