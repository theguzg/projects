#include "Controller.h"

void Controller::addMovieToRepository(const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes, const std::string trailer)
{
	Movie m{ title, genre, yearOfRelease, likes, trailer };
	this->repo.addMovie(m);
}

void Controller::updateMovieFromRepository(int position, const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes)
{
	this->repo.updateMovie(position, title, genre, yearOfRelease, likes);
}

void Controller::deleteMovieFromRepository(const std::string & title)
{
	this->repo.deleteMovie(title);
}

void Controller::addMovieToWatchList(const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes, const std::string trailer)
{
	Movie m{ title, genre, yearOfRelease, likes, trailer };
	this->watchList.addMovieWatchList(m);
}

void Controller::deleteMovieFromWatchList(const std::string & title)
{
	this->watchList.removeMovieWatchList(title);
}

DynamicVector Controller::displaySongs(const std::string & genre)
{
	DynamicVector moviesInRepo = this->repo.displayByGenre(genre);
	return moviesInRepo;
}

void Controller::likeMovieFromRepository(const std::string & title)
{
	this->repo.likeMovie(title);
}

bool Controller::searchMovieByTitleInRepo(const std::string & title)
{
	return this->repo.searchByTitle(title);
}

bool Controller::searchMovieByTitleInWatchList(const std::string & title)
{
	return this->watchList.searchByTitleWatchList(title);
}




