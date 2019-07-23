#include "Watchlist.h"

Watchlist::Watchlist()
{
	this->size = 0;
}

void Watchlist::addMovieWatchList(const Movie & m)
{
	movies.add(m);
	this->size++;
}

void Watchlist::removeMovieWatchList(const std::string & title)
{
	movies.remove(title);
}

bool Watchlist::isEmpty()
{
	return this->size == 0;
}

bool Watchlist::searchByTitleWatchList(const std::string & title)
{
	Movie* moviesInDynamicVector = this->movies.getAllElems();
	DynamicVector moviesByTitle;

	for (int i = 0; i < movies.getSize(); i++)
	{
		Movie m = moviesInDynamicVector[i];
		if (m.getTitle() == title)
			return true;
	}

	return false;

}
