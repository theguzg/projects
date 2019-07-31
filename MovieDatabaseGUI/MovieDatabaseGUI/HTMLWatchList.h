#pragma once
#include <stdio.h>
#include "FileWatchlist.h"

class HTMLWatchList : public FileWatchList
{
public:
	void write_to_file() override;

	void display_WatchList() const override;
};