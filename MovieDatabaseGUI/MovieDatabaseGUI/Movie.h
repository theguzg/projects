#pragma once

#include <string>
#include <iostream>
#include <sstream>

class Movie
{
private:
	std::string title;
	std::string genre;
	int yearOfRelease;
	int likes;
	std::string trailer;		// youtube Link

public:
	// default constructor for a song
	Movie();

	// constructor with parameters
	Movie(const std::string& title, const std::string& genre, const int& yearOfRelease, const int& likes, const std::string& trailer);

	std::string getTitle() const { return title; }
	std::string getGenre() const { return genre; }
	int getYearOfRelease() const { return yearOfRelease; }
	int getLikes() const { return likes; }
	std::string getTrailer() const { return trailer; }

	void increaseLikes();

	void setTitle(std::string val) { this->title = val; }
	void setGenre(std::string val) { this->genre = val; }
	void setYearOfRelease(int val) { this->yearOfRelease = val; }
	void setLikes(int val) { this->likes = val; }

	std::string toString(const double & i)
	{
		std::stringstream ss;
		ss << i;
		return ss.str();
	}


	bool operator==(const Movie& s);

	// Plays the current song: the page corresponding to the source link is opened in a browser.
	void play();

	friend std::istream& operator>>(std::istream& is, Movie& s);
	friend std::ostream& operator<<(std::ostream& os, const Movie& s);
};
