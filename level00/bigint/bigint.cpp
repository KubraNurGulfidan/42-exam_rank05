#include "bigint.hpp"

bigint::bigint() : numbers("0") {}
bigint::~bigint() {}
bigint::bigint(const string &str)
{
	if(str.empty() || !all_of(str.begin(), str.end(), ::isdigit))
		bigint("0");
	else
	{
		numbers =str;
		reverse(numbers.begin(), numbers.end());
		removeZeros();
	}
}
bigint::bigint(unsigned int n)
{
	stringstream ss;
	ss << n;
	numbers = ss.str();
	reverse(numbers.begin(), numbers.end());
}
bigint::bigint(const bigint &big)
{
	*this = big;
}
bigint &bigint::operator=(const bigint &big)
{
	if(this->numbers != big.numbers)
		this->numbers = big.numbers;
	return *this;	
}

void bigint::removeZeros()
{
	while (numbers.size() > 1 && numbers.back() == '0')
		numbers.pop_back();
}
string bigint::addNumbers(const string &s1, const string &s2) const
{
	int sum = 0, elde = 0;
	string result = "";
	size_t size = max(s1.size(), s2.size());

	for (size_t i = 0; i < size; i++)
	{
		sum += i < s1.size() ? s1[i] - '0' : 0;
		sum += i < s2.size() ? s2[i] - '0' : 0;
		sum += elde;
		elde = sum / 10;
		result.push_back(sum % 10 + '0');
		sum = 0;
	}
	if(elde > 0)
		result.push_back(elde % 10 + '0');
	return result;
}

bigint bigint::operator+(const bigint &big) const
{
	string result;
	result = addNumbers(this->numbers, big.numbers);
	reverse(result.begin(), result.end());
	return bigint(result);
}
bigint &bigint::operator+=(const bigint &big)
{
	*this = *this + big;
	return *this;
}
bigint &bigint::operator++()
{
	this->numbers = addNumbers(this->numbers, "1");
	return *this;
} //önce arttır
bigint bigint::operator++(int n)
{
	(void)n;
	bigint temp = *this;
	this->numbers = addNumbers(this->numbers, "1");
	return temp;
}

bigint bigint::operator<<(const int n)
{
	string str = this->numbers;
	reverse(str.begin(), str.end());
	for(int i = 0; i < n; i++)
		str.push_back('0');
	return bigint(str);
}
bigint bigint::operator>>(const int n)
{
	string str = this->numbers;
	reverse(str.begin(), str.end());
	for(int i = 0; i < n; i++)
	{
		if(str.empty())
			return bigint("0");
		str.pop_back();
	}
	return bigint(str);
}
bigint bigint::operator<<=(const int n)
{
	*this = *this << n;
	return *this;
}
bigint bigint::operator>>=(const int n)
{
	*this = *this >> n;
	return *this;
}

bigint bigint::operator<<(const bigint &big)
{
	string str = big.numbers;
	reverse(str.begin(), str.end());
	int nbr = stoi(str);
	return *this << nbr;
}
bigint bigint::operator>>(const bigint &big)
{
	string str = big.numbers;
	reverse(str.begin(), str.end());
	int nbr = stoi(str);
	return *this >> nbr;
}
bigint bigint::operator<<=(const bigint &big)
{
	*this = *this << big;
	return *this;
}
bigint bigint::operator>>=(const bigint &big)
{
	*this = *this >> big;
	return *this;
}

bool bigint::operator<(const bigint &big) const
{
	if(numbers.size() != big.numbers.size())
		return numbers.size() < big.numbers.size();
	return lexicographical_compare(numbers.rbegin(), numbers.rend(), big.numbers.rbegin(), big.numbers.rend());
}
bool bigint::operator>(const bigint &big) const
{
	if(numbers.size() != big.numbers.size())
		return numbers.size() > big.numbers.size();
	return lexicographical_compare(numbers.rbegin(), numbers.rend(), big.numbers.rbegin(), big.numbers.rend());
}
bool bigint::operator<=(const bigint &big) const
{
	if (*this < big || *this == big)
		return true;
	return false;
}
bool bigint::operator>=(const bigint &big) const
{
	if (*this > big || *this == big)
		return true;
	return false;
}
bool bigint::operator==(const bigint &big) const
{
	if (*this < big || *this > big)
		return false;
	return true;
}
bool bigint::operator!=(const bigint &big) const
{
	if(*this == big)
		return false;
	return true;
}

ostream &operator<<(ostream &os, const bigint &big)
{
	string str = big.getNumbers();
	reverse(str.begin(), str.end());
	os << str;
	return os;
}