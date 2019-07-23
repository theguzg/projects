#include "CSVWatchList.h"
#include "stdafx.h"
#include <Windows.h>
#include <shellapi.h>

void CSVWatchList::write_to_file()
{
	ofstream f(this->filename);
	if (!f.is_open())
		throw FileException("CSV File for Watchlist can't be opened!\n");

	f << "Title,";
	f << "Genre,";
	f << "Year of release,";
	f << "Likes,";
	f << "Trailer" << endl;
	for (auto m : this->movies)
		f << m;
	f.close();
}

void CSVWatchList::display_WatchList() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations

	ShellExecuteA(NULL, NULL, "EXCEL.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
