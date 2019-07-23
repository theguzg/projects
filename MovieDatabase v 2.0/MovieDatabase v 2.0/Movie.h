#pragma once

#include <iostream>

class Movie 
{
private:
	std::string title;
	std::string genre;
	double yearOfRelease;
	double likes;
	std::string trailer;

public:
	//default constructor
	Movie();
	//constructor with parameters
	Movie(const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes, const std::string & trailer);

	std::string getTitle() const { return title; }
	std::string getGenre() const { return genre; }
	double getYearOfRelease() const { return yearOfRelease; }
	double getLikes() const { return likes; }
	std::string getTrailer() const { return trailer; }

	bool operator==(const Movie& m);
	bool trailerLink();

	friend std::istream& operator>>(std::istream& is, Movie & m);
	friend std::ostream& operator<<(std::ostream& os, const Movie & m);
};
