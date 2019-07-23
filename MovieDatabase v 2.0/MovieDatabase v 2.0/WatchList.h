#pragma once
#include "Movie.h"
#include "RepositoryException.h"
#include <vector>

class WatchList
{
protected:
	std::vector<Movie> movies;
	int current;

public:
	WatchList();

	void add(const Movie& m);

	void remove(const Movie& m);

	virtual int findPosByTitle(const std::string& title);

	Movie getCurrentMovie();

	void playTrailer();

	void next();

	bool isEmpty();

	std::vector<Movie> getMovies() const { return movies; }


};