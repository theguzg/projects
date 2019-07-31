#include "Watchlist.h"


WatchList::WatchList()
{
	this->current = 0;
}

void WatchList::add(const Movie & m)
{
	this->moviesWatch.push_back(m);
}

void WatchList::remove(const Movie & m)
{
	if (findPosByTitle(m.getTitle()) == -1)
		throw InexistentMovieException();

	for (auto aux : this->moviesWatch)
	{
		if (m.getTitle() == aux.getTitle())
		{
			this->moviesWatch.erase(this->moviesWatch.begin() + findPosByTitle(m.getTitle()));
			break;
		}
	}

}

int WatchList::findPosByTitle(const std::string & title)
{
	int contor = 0;

	for (auto aux : this->moviesWatch)
	{
		if (aux.getTitle() == title)
			return contor;
		contor++;
	}

	return -1;
}

Movie WatchList::findMovieByTitle(const std::string & title)
{
	for (auto aux : this->moviesWatch)
	{
		if (aux.getTitle() == title)
		{
			return aux;
		}
	}

	return Movie{};
}

Movie WatchList::getCurrentMovie()
{
	if (this->current == this->moviesWatch.size())
		this->current = 0;
	if (this->moviesWatch.size() == NULL)
		return this->moviesWatch[this->current];
}

void WatchList::playTrailer()
{
	if (this->moviesWatch.size() >= 0)
	{
		this->current = 0;
		Movie currentMovie = this->getCurrentMovie();
		currentMovie.play();
	}
}

void WatchList::next()
{
	if (this->moviesWatch.size() == 0)
		return;
	this->current++;
	Movie currentMovie = this->getCurrentMovie();
	currentMovie.play();
}

bool WatchList::isEmpty()
{
	return this->moviesWatch.size() == 0;
}
