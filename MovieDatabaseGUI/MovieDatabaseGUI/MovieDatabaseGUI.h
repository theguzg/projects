#pragma once

#include <QtWidgets/QMainWindow>
#include "Controller.h"
#include "ui_MovieDatabaseGUI.h"

class MovieDatabaseGUI : public QMainWindow
{
	Q_OBJECT

public:

	int undoVariable = 0;
	bool redoVariable = false;
	Movie undoMovie;
	Movie newMovie;

	MovieDatabaseGUI(Controller& c, QWidget *parent);

	void populate();
	void populateShort();
	void addButtonHandler();
	void removeButtonHandler();
	void updateButtonHandler();
	void filterButtonHandler();
	void moveToWatchList();
	void playButtonHandler();
	void nextButtonHandler();
	void deleteWatchListButtonHandler();
	void redoButtonHandler();
	void undoButtonHandler();
	void saveButtonHandler();


private:

	Ui::MovieDatabaseGUIClass ui;
	Controller ctrl;



};


