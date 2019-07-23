#pragma once
#include "Movie.h"
#include <vector>

using namespace std;

class Repository
{
private:
	vector<Movie> movies;
	string filename;

public:
	Repository(const string& filename);
	
	void addMovie(const Movie& m);
	void removeMovie(const Movie& m);
	void updateMovie(Movie& m, const Movie& newMovie);
	Movie findMovieByTitle(const string& title);
	int findPosByTitle(const string& title);

	vector<Movie> getMovies() const { return movies; }

private:
	void readFromFile();
	void writeToFile();
};
