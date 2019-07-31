#pragma once
#include "Repository.h"
#include "WatchList.h"
#include "MovieValidator.h"
#include "FileWatchList.h"

class Controller
{
private:
	Repository repo;
	FileWatchList* watchList;
	MovieValidator validator;

public:
	Controller(const Repository& r, FileWatchList* w) : repo{ r }, watchList{ w } {}

	Repository getRepo() const { return repo; }

	WatchList* getWatchList() const { return watchList; }

	void addMovieToRepo(const std::string& title, const std::string& genre, const int yearOfRelease, const int likes, const std::string & trailer);
	void removeMovieFromRepo(const std::string & title);
	void updateMovie(const std::string& title, const std::string& new_title, const std::string& new_genre, const int new_yearOfRelease, const int new_likes, const std::string & new_trailer);

	void addMovieToWatchList(const Movie& m);
	void removeMovieFromWatchList(const Movie& m);
	void playTrailerCtrl();
	void nextMovie();

	void likeMovieFromRepo(Movie m);

    bool checkGenre(const Movie & m,const std::string & genre);

	//std::vector<Movie> getAllMovies() const { return this->repo.getMovies(); }
	//std::vector<Movie> getMoviesFromWatchList() { return this->watchList.getAll(); }

	void save_WatchList(const std::string & filename);
	void open_WatchList() const;
};
