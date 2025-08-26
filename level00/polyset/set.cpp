#include "set.hpp"

set::set(searchable_bag &bag) : bag(bag) {}
set::set(const set &other) :bag(other.bag) {}
set &set::operator=(const set &other)
{
	if (this != &other)
		bag = other.bag;
	return *this;
}
set::~set(){}

void set::insert(int n)
{
	if(!bag.has(n))
		bag.insert(n);
}
void set::insert(int *arr, int n)
{
	if(!arr || n <= 0)
		return;
	for (int i = 0; i < n; i++)
	{
		if(!bag.has(arr[i]))
			bag.insert(arr[i]);
	}
}
void set::print() const
{
	bag.print();
}
void set::clear()
{
	bag.clear();
}
bool set::has(int value) const
{
	return bag.has(value);
}