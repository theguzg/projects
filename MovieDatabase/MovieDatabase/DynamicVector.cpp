#include "DynamicVector.h"

DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

DynamicVector::DynamicVector(const DynamicVector & v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

}

DynamicVector::~DynamicVector()
{
	delete[] this->elems;
}

DynamicVector & DynamicVector::operator=(const DynamicVector & v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}


void DynamicVector::add(const TElement & e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

void DynamicVector::update(int position, const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes)
{
	elems[position].setTitle(title);
	elems[position].setGenre(genre);
	elems[position].setYearOfRelease(yearOfRelease);
	elems[position].setLikes(likes);
}


void DynamicVector::remove(const std::string & title)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->elems[i].getTitle() == title)
		{
			for (int j = i; j < this->size - 1; j++)
			{
				this->elems[j] = this->elems[j + 1];
			}

			this->size--;
			return;
		}
	}

}

void DynamicVector::like(const std::string & title)
{

	for (int i = 0; i < this->size; i++)
	{
		if (this->elems[i].getTitle() == title)
		{
			elems[i].increaseLikes();
			return;
		}
	}
}

void DynamicVector::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}


TElement* DynamicVector::getAllElems() const
{
	return this->elems;
}

int DynamicVector::getSize() const
{
	return this->size;
}



