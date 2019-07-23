#include "Movie.h"
#include <Windows.h>
//#include <shellapi.h>
#include <vector>
#include <iostream>
#include "stdafx.h"
#include "Utils.h"

using namespace std;

Movie::Movie(): title(""), genre(""), yearOfRelease(0), likes(0), trailer("") {}

Movie::Movie(const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes, const std::string & trailer)
{
	this->title = title;
	this->genre = genre;
	this->yearOfRelease = yearOfRelease;
	this->likes = likes;
	this->trailer = trailer;
}

bool Movie::operator==(const Movie & m)
{
	if (this->title == m.getTitle())
		return true;
	return false;
}

bool Movie::trailerLink()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
	return true;
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
	os << m.title << " " << m.genre << " " << m.yearOfRelease << " " << m.likes << " " << m.trailer << '\n';
	return os;
	
}
