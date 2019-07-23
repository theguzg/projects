#pragma once

#include "Repository.h"
#include "Watchlist.h"

class Controller
{
private:
	Repository repo;
	Watchlist watchList;

public:
	Controller(const Repository& r) : repo{ r } {}
	Repository getRepo() const { return repo; }

	Controller(const Watchlist& w) : watchList{ w } {}
	Watchlist getWatchList() const { return watchList; }

	//Administrator mode
	void addMovieToRepository(const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes, const std::string trailer);
	void updateMovieFromRepository(int position, const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes);
	void deleteMovieFromRepository(const std::string & title);

	//User mode

	void addMovieToWatchList(const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes, const std::string trailer);
	void deleteMovieFromWatchList(const std::string & title);
	DynamicVector displaySongs(const std::string & genre);
	void likeMovieFromRepository(const std::string & title);

	//Add and delete validation
	bool searchMovieByTitleInRepo(const std::string & title);
	bool searchMovieByTitleInWatchList(const std::string & title);

	


};
