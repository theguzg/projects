#pragma once
#include "Movie.h"
#include <vector>

using namespace std;

template <typename T>
class Comparator
{
public:
	virtual bool compare(const T& elem1, const T& elem2) const = 0;
};

class ComparatorAscendingByTitle : public Comparator <Movie>
{
public:
	bool compare(const Movie& m1, const Movie& m2) const override { return m1.getTitle() < m2.getTitle(); }
};

class ComparatorDescendingByLikes : public Comparator <Movie>
{
public:
	bool compare(const Movie& m1, const Movie& m2) const override { return m1.getLikes() > m2.getLikes(); }
};

template <typename T>
vector<T> sortF(vector<T> arr, Comparator<T>& comp)
{
	vector<T> reserve = arr;
	T aux;

	for(int i = 0; i < reserve.getSize()-1; i++)
		for (int j = i + 1; j < reserve.getSize(); j++)
		{
			Movie m1 = reserve.getAllElems()[i];
			Movie m2 = reserve.getAllElems()[j];

			if (comp.compare(m1, m2) == false)
			{
				aux = m1;
				m1 = m2;
				m2 = aux;
			}
		}
	return reserve;
}