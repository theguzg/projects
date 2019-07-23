#include "Repository.h"
#include "Movie.h"
#include <string>
#include <assert.h>

using namespace std;

void Repository::addMovie(const Movie & m)
{
	this->movies.add(m);
}

void Repository::updateMovie(int position, const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes)
{
	this->movies.update(position, title, genre, yearOfRelease, likes);
}


void Repository::deleteMovie(const std::string & title)
{
	this->movies.remove(title);
}


void Repository::likeMovie(const std::string & title)
{
	this->movies.like(title);
}

DynamicVector Repository::displayByGenre(const std::string & genre)
{

	Movie* moviesInDynamicVector = this->movies.getAllElems();
	DynamicVector moviesByGenre;
	bool ok = false;

	if (this->movies.getSize() == 0)
		return 0;

	for (int i = 0; i < this->movies.getSize(); i++)
	{
		Movie m = moviesInDynamicVector[i];
		if (m.getGenre() == genre) {

			ok = true;
			moviesByGenre.add(m);
		}
			
			
	}

	if (ok == true)
		return moviesByGenre;
	else
		return movies;
	
}

bool Repository::searchByTitle(const std::string & title)
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



