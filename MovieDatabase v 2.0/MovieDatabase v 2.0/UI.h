#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;
	
public:
	UI(const Controller& c) : ctrl(c) {}

	void administrator();
	void user();

	void ui_add();
	void printAll();
	void printAllWatchList();
	void ui_remove();
	void ui_update();
	void printOneByOne();
	void printByGenre();
	void run();

private:
	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();
	void save_watchlist_to_file();
};