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
	//Default constructor for a movie
	Movie();

	//Constructor with parameters
	Movie(const std::string& title, const std::string& genre, const double& yearOfRelease, const double& likes, const std::string trailer);

	std::string getTitle() const { return title; }
	std::string getGenre() const { return genre; }
	double getYearOfRelease() const { return yearOfRelease; }
	double getLikes() const { return likes; }
	std::string getTrailer() const { return trailer; }

	void setTitle(const std::string& title) { this->title = title; }
	void setGenre(const std::string& genre) { this->genre = genre; }
	void setYearOfRelease(const double& yearOfRelease) { this->yearOfRelease = yearOfRelease; }
	void setLikes(const double& likes) { this->likes = likes; }

	void increaseLikes();


	


	//Plays the current trailer
	void play();


};
