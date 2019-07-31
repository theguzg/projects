#pragma once
#include "Movie.h"
#include "RepositoryException.h"
#include <vector>

class WatchList
{
protected:
	std::vector<Movie> moviesWatch;
	int current;

public:
	WatchList();

	void add(const Movie& m);

	void remove(const Movie& m);

	virtual int findPosByTitle(const std::string& title);

	virtual Movie findMovieByTitle(const std::string& title);

	Movie getCurrentMovie();

	void playTrailer();

	void next();

	bool isEmpty();

	std::vector<Movie> getAll() const { return moviesWatch; }


};