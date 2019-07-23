#include "HTMLWatchList.h"
#include "stdafx.h"
#include "RepositoryException.h"
#include <fstream>
#include <Windows.h>
#include <shellapi.h>

using namespace std;

void HTMLWatchList::write_to_file()
{
	ofstream f(this->filename);
	if (!f.is_open())
		throw FileException("HTML file for Watchlist can't be opened! \n");
	f << "<!DOCTYPE html>" << endl;
	f << "<html>" << endl;
	f << "<head>" << endl;
	f << "<title>Watchlist</title>" << endl;
	f << "</head>" << endl;
	f << "<body>" << endl;
	f << "<table border=\"1\", style=\"width:100%\">" << endl;
	f << "<tr style=\"text-align:center;font-size:120%;\">" << endl;
	f << "<td>" << "<b>Title</b>" << "</td>" << endl;
	f << "<td>" << "<b>Genre</b>" << "</td>" << endl;
	f << "<td>" << "<b>Year of release</b>" << "</td>" << endl;
	f << "<td>" << "<b>Likes</b>" << "</td>" << endl;
	f << "<td>" << "<b>Trailer</b>" << "</td>" << endl;
	f << "</tr>" << endl;
	for (auto m : this->movies)
	{
		f << "<tr style=\"text-align:center;\">" << endl;
		f << "<td>" << m.getTitle() << "</td>" << endl;
		f << "<td>" << m.getGenre() << "</td>" << endl;
		f << "<td>" << m.getYearOfRelease() << "</td>" << endl;
		f << "<td>" << m.getLikes() << "</td>" << endl;
		f << "<td>" << "<a href = \" " << m.getTrailer() << "\">Link</a>" << "</td>" << endl;
		f << "</tr>" << endl;
	}
	f.close();
}

void HTMLWatchList::display_WatchList() const
{
	string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
