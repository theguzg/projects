#include "Repository.h"
#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>
#include "RepositoryException.h"


Repository::Repository(const string & filename)
{
	this->filename = filename;
	this->readFromFile();
}

void Repository::addMovie(const Movie & m)
{
	if (findPosByTitle(m.getTitle()) != -1)
		throw DuplicateMovieException();
	this->movies.push_back(m);
	this->writeToFile();

}

void Repository::removeMovie(const Movie & m)
{
	if (findPosByTitle(m.getTitle()) == -1)
		throw InexistentMovieException();

	for (auto aux : this->movies)
	{
		if (m.getTitle() == aux.getTitle())
		{
			this->movies.erase(this->movies.begin() + findPosByTitle(m.getTitle()));
			this->writeToFile();
			break;
		}
	}

}

void Repository::updateMovie(Movie & m, const Movie & newMovie)
{
	if (findPosByTitle(m.getTitle()) == -1)
		throw InexistentMovieException();

	for (auto aux : this->movies)
	{
		if (m.getTitle() == aux.getTitle())
		{
			this->movies[findPosByTitle(aux.getTitle())] = newMovie;
			this->writeToFile();
			break;
		}
	}
}

Movie Repository::findMovieByTitle(const string & title)
{
	for (auto aux : this->movies)
	{
		if (aux.getTitle() == title)
		{
			return aux;
		}
	}

	return Movie{};
}

int Repository::findPosByTitle(const string & title)
{
	int contor = 0;

	for (auto aux : this->movies)
	{
		if (aux.getTitle() == title)
			return contor;
		contor++;
	}

	return -1;
}

void Repository::readFromFile()
{
	ifstream f(this->filename);

	if (!f.is_open())
		throw FileException("This file could not be opened!");

	Movie m;

	while (f >> m)
	{
		this->movies.push_back(m);
	}
	f.close();

}

void Repository::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("This file could not be opened!");

	for (auto m : this->movies)
	{
		f << m;
	}

	f.close();
}
