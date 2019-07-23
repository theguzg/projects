#pragma once
#include "Movie.h"
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector movies;
	

public:
	/*
		Default constructor
		Initializes an object of the type repository
	*/
	Repository() {}

	/*
		Adds a movie to the repository
		Input: m - movie
		Output: the movie is added to the repository
	*/
	void addMovie(const Movie& m);


	/*
		Updates a movie from the repository
		Input: position - integer, title - string, genre - strinng, yearOfRelease - double, likes- double
		Output: the movie is updated in the repository with it's new entities
	*/

	void updateMovie(int position, const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes);

	/*
		Deletes a movie from the repository
		Input: position - integer
		Output: the movie is deleted from the repository
	*/

	void deleteMovie(const std::string & title);

	/*
		Finds a movie, by genre
		Input: genre - string
		Output: all the songs if nothing was found for the given genre
	*/

	void likeMovie(const std::string & title);

	DynamicVector displayByGenre(const std::string& genre);

	bool searchByTitle(const std::string & title);

	DynamicVector getMovies() const { return movies; }



};
