#include "Controller.h"
#include "stdafx.h"
#include "Validator.h"

void Controller::addMovieToRepo(const std::string & title, const std::string & genre, const double yearOfRelease, const double likes, const std::string & trailer)
{
	Movie m{ title, genre, yearOfRelease, likes, trailer };
	this->validator.validate(m);
	repo.addMovie(m);
}

void Controller::removeMovieFromRepo(const std::string & title)
{
	Movie m = repo.findMovieByTitle(title);
	repo.removeMovie(repo.findMovieByTitle(title));
}

void Controller::updateMovie(const std::string & title, const std::string & new_title, const std::string & new_genre, const double new_yearOfRelease, const double new_likes, const std::string & new_trailer)
{
	Movie m = repo.findMovieByTitle(title);

	Movie newMovie{ new_title, new_genre, new_yearOfRelease, new_likes, new_trailer };
	this->validator.validate(newMovie);
	repo.updateMovie(m, newMovie);
}

void Controller::addMovieToWatchList(const Movie & m)
{
	this->watchList->add(m);
}

void Controller::playTrailerCtrl()
{
	this->watchList->playTrailer();
}

void Controller::nextMovie()
{
	this->watchList->next();
}

void Controller::save_WatchList(const std::string & filename)
{
	if (this->watchList == nullptr)
		return;
	this->watchList->set_filename(filename);
	this->watchList->write_to_file();
}

void Controller::open_WatchList() const
{
	if (this->watchList == nullptr)
		return;
	this->watchList->display_WatchList();
}


