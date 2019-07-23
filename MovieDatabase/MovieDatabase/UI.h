#pragma once

#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	static void printMenu();
	static void printAdministratorMenu();
	static void printUserMenu();
	static void printCommandMenu();

	//Administrator mode
	void addMovieToRepo();
	void updateMovieFromRepo();
	void deleteMovieFromRepo();
	void displayAllMoviesRepo();

	//User mode	
	void deleteMovieWatchListUI();
	void displayAllMoviesWatchList();
	void diplayByGenre();


};
