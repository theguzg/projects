#pragma once
#include "FileWatchlist.h"
#include <string>

class CSVWatchlist : public FileWatchList
{
public:
	/*
	Writes the playlist to file.
	Throws: FileException - if it cannot write.
	*/
	void write_to_file() override;

	/*
	Displays the playlist using Microsoft Excel.
	*/
	void display_WatchList() const override;
};

