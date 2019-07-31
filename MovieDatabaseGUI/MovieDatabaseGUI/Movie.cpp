#include "Movie.h"
#include "stdafx.h"
#include <Windows.h>
#include <shellapi.h>
#include <iostream>
#include <vector>
#include <string>
#include "Utils.h"

using namespace std;

Movie::Movie() : title(""), genre(""), yearOfRelease(0), likes(0), trailer("") {}

Movie::Movie(const std::string& title, const std::string& genre, const int& yearOfRelease, const int& likes, const std::string& trailer)
{
	this->title = title;
	this->genre = genre;
	this->yearOfRelease = yearOfRelease;
	this->likes = likes;
	this->trailer = trailer;
}

void Movie::increaseLikes()
{
	this->likes++;
}

bool Movie::operator==(const Movie & m)
{
	return (this->title == m.title);
}

void Movie::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}


istream & operator>>(istream & is, Movie & m)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ' ');
	if (tokens.size() != 5)
		return is;

	m.title = tokens[0];
	m.genre = tokens[1];
	m.yearOfRelease = stod(tokens[2]);
	m.likes = stod(tokens[3]);
	m.trailer = tokens[4];

	return is;


}

ostream & operator<<(ostream & os, const Movie & m)
{
	os << m.title << " " << m.genre << " " << m.yearOfRelease << " " << m.likes << " " << m.trailer << "\n";
	return os;
}
