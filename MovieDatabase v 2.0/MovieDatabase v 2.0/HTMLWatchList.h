#pragma once
#include <stdio.h>
#include "FileWatchList.h"

class HTMLWatchList : public FileWatchList
{
public:
	void write_to_file() override;
	/*
	Writes the watchlist to file.
	Throws: FileException - if it cannot write.
	*/

	void display_WatchList() const override;
};
