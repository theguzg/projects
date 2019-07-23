#include "WatchList.h"
#include "stdafx.h"

WatchList::WatchList()
{
	this->current = 0;
}

void WatchList::add(const Movie & m)
{
	this->movies.push_back(m);
}

void WatchList::remove(const Movie & m)
{
	if (findPosByTitle(m.getTitle()) == -1)
		throw InexistentMovieException();

	for (auto aux : this->movies)
	{
		if (m.getTitle() == aux.getTitle())
		{
			this->movies.erase(this->movies.begin() + findPosByTitle(m.getTitle()));
			break;
		}
	}

}

int WatchList::findPosByTitle(const std::string & title)
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

Movie WatchList::getCurrentMovie()
{
	if (this->current == this->movies.size())
		this->current = 0;
	if (this->movies.size() == NULL)
		return this->movies[this->current];
}

void WatchList::playTrailer()
{
	if (this->movies.size() >= 0)
	{
		this->current = 0;
		Movie currentMovie = this->getCurrentMovie();
		currentMovie.trailerLink();
	}
}

void WatchList::next()
{
	if (this->movies.size() == 0)
		return;
	this->current++;
	Movie currentMovie = this->getCurrentMovie();
	currentMovie.trailerLink();
}

bool WatchList::isEmpty()
{
	return this->movies.size() == 0;
}
