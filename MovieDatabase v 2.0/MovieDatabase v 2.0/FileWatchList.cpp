#include "FileWatchList.h"
#include "stdafx.h"

FileWatchList::FileWatchList() : WatchList{}, filename("") {}

void FileWatchList::set_filename(const std::string & filename)
{
	this->filename = filename;
}

