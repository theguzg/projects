#pragma once
#include <stdio.h>
#include "FileWatchList.h"
#include "RepositoryException.h"
#include <fstream>

using namespace std;

class CSVWatchList : public FileWatchList
{
public:
	CSVWatchList() {};
	void write_to_file() override;

	/*
	Writes the watchlist to file.
	Throws : FileException - if it cannot write.
	*/
	void display_WatchList() const override;
};
