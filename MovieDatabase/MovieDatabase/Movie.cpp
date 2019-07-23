#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>
#include <assert.h>

Movie::Movie(): title(""), genre(""), yearOfRelease(0), likes(0), trailer("") {}

Movie::Movie(const std::string & title, const std::string & genre, const double & yearOfRelease, const double & likes, const std::string trailer)
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

void Movie::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}


