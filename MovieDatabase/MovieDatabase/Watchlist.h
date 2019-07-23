#pragma once
#include "DynamicVector.h"
#include "Repository.h"


class Watchlist {

private:
	DynamicVector movies;
	int size = 0;

public:

	Watchlist();
	
	void addMovieWatchList(const Movie& m);
	void removeMovieWatchList(const std::string & title);

	DynamicVector getList() const { return movies; }

	bool isEmpty();
	bool searchByTitleWatchList(const std::string & title);




};