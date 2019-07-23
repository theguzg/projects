#pragma once
#include "Movie.h"

typedef Movie TElement;

class DynamicVector
{
private:
	TElement * elems;
	int size;
	int capacity;

public:
	// Default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	// assigment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	// adds an element to the current DynamicVector
	void add(const TElement& e);

	// update an element from the current DynamicVector

	void update(int position, const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes);

	// removes an element from the current DynamicVector

	void remove(const std::string & title);

	void like(const std::string & title);

	int getSize() const;
	TElement* getAllElems() const;

private:
	// Resizes the current DynamicVector by a given factor(real number)
	void resize(double factor = 2);
};
