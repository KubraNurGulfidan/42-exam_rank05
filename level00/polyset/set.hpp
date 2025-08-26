#pragma once

#include "searchable_bag.hpp"

class set
{
	private:
		searchable_bag &bag;

	public:
		set(searchable_bag &bag);
		set(const set &other);
		set &operator=(const set &other);
		~set();

		void insert(int n);
		void insert(int *arr, int n);
		void print() const;
		void clear();
		bool has(int value) const;

		searchable_bag &getBag() {return bag;}
};