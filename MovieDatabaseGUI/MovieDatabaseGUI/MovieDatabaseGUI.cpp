#include "MovieDatabaseGUI.h"
#include "RepositoryException.h"
#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include "Undo.h"
#include "Redo.h"


MovieDatabaseGUI::MovieDatabaseGUI(Controller& c, QWidget *parent)
	: ctrl{ c }, QMainWindow(parent)
{
	ui.setupUi(this);
	populate();

	

	//Clicking the add button
	QObject::connect(ui.addMovieButton, &QPushButton::clicked, this, [this]() {addButtonHandler(); });

	//Clicking the remove button
	QObject::connect(ui.deleteMovieButton, &QPushButton::clicked, this, [this]() {removeButtonHandler(); });

	//Clicking the update button
	QObject::connect(ui.updateButton, &QPushButton::clicked, this, [this]() {updateButtonHandler(); });

	//Clicking ">" button
	QObject::connect(ui.addToWatchListButton, &QPushButton::clicked, this, [this]() {moveToWatchList(); });

	//Clicking the play button
	QObject::connect(ui.playWatchList, &QPushButton::clicked, this, [this]() {playButtonHandler(); });

	//Clicking the next button
	QObject::connect(ui.nextWatchList, &QPushButton::clicked, this, [this]() {nextButtonHandler(); });

	//Clicking the filter button
	QObject::connect(ui.filterMoviesButton, &QPushButton::clicked, this, [this]() {filterButtonHandler(); });

	//Clicking "detailed" or "short" on the combo box
	QObject::connect(ui.comboBox, &QComboBox::currentTextChanged, this, [this]() {populate(); });

	//Clicking the delete button bellow the watch list
	QObject::connect(ui.removeWatchListButton, &QPushButton::clicked, this, [this]() {deleteWatchListButtonHandler(); });
	
	//Clicking the save button 
	QObject::connect(ui.saveWatchList, &QPushButton::clicked, this, [this]() {saveButtonHandler(); });

	//Clicking the undo button
	QObject::connect(ui.undoButton, &QPushButton::clicked, this, [this]() {undoButtonHandler(); });

	//Clicking the undo button
	QObject::connect(ui.redoButton, &QPushButton::clicked, this, [this]() {redoButtonHandler(); });


}

void MovieDatabaseGUI::populate()
{
	string comboText = ui.comboBox->currentText().toStdString();

	ui.repoList->clear();
	for (auto x : ctrl.getRepo().getMovies())
	{
		if (comboText.compare("Detailed") == 0)
		{
			string s = x.getTitle();
			s += "| ";
			s += x.getGenre();
			s += "| ";
			s += to_string(x.getYearOfRelease());
			s += "| ";
			s += to_string(x.getLikes());
			s += "| ";
			s += x.getTrailer();
			ui.repoList->addItem(s.c_str());

		}
		else 
		{
			string s = x.getTitle();
			ui.repoList->addItem(s.c_str());

		}
	}
}

void MovieDatabaseGUI::populateShort()
{
	ui.repoList->clear();
	for (auto x : ctrl.getRepo().getMovies())
	{
		string s = x.getTitle();
		ui.repoList->addItem(s.c_str());
	}
}

void MovieDatabaseGUI::addButtonHandler()
{
	string title = ui.titleEdit->text().toStdString();
	string genre = ui.genreEdit->text().toStdString();
	int yearOfRelease = ui.yearOfReleaseEdit->text().toInt();
	int likes = ui.likesEdit->text().toInt();
	string trailer = ui.trailerEdit->text().toStdString();

	Movie m{ title, genre, yearOfRelease, likes, trailer };
	undoMovie = m;

	try
	{
		ctrl.addMovieToRepo(title, genre, yearOfRelease, likes, trailer);
		populate();
		ui.updateLabel->setText("Movie added!");
		undoVariable = 1;
		redoVariable = true;
	}
	catch (MovieException& e)
	{
		string x;
		for (auto m : e.getErrors())
			x += m;
		ui.updateLabel->setText(x.c_str());
	}
	catch (RepositoryException& e)
	{
		ui.updateLabel->setText(e.what());
	}
	catch (FileException& e)
	{
		ui.updateLabel->setText(e.what());
	}
}

void MovieDatabaseGUI::removeButtonHandler()
{
	string title = ui.titleEdit->text().toStdString();
	undoMovie = ctrl.getRepo().findMovieByTitle(title);

	try
	{
		ctrl.removeMovieFromRepo(title);
		populate();
		ui.updateLabel->setText("Movie removed!");
		undoVariable = 2;
	}
	catch (MovieException & e)
	{
		string x;
		for (auto m : e.getErrors())
			x += m;
		ui.updateLabel->setText(x.c_str());
	}
	catch (RepositoryException& e)
	{
		ui.updateLabel->setText(e.what());
	}
	catch (FileException& e)
	{
		ui.updateLabel->setText(e.what());
	}
}

void MovieDatabaseGUI::updateButtonHandler()
{
	string title1 = ui.oldTitleEdit->text().toStdString();
	string title = ui.titleEdit->text().toStdString();
	string genre = ui.genreEdit->text().toStdString();
	int yearOfRelease = ui.yearOfReleaseEdit->text().toInt();
	int likes = ui.likesEdit->text().toInt();
	string trailer = ui.trailerEdit->text().toStdString();

	Movie m{ title, genre, yearOfRelease, likes, trailer };
	newMovie = m;
	undoMovie = ctrl.getRepo().findMovieByTitle(title1);

	try
	{
		ctrl.updateMovie(title1, title, genre, yearOfRelease, likes, trailer);
		populate();
		ui.updateLabel->setText("Movie updated!");
		undoVariable = 3;
	}
	catch (MovieException & e)
	{
		string x;
		for (auto m : e.getErrors())
			x += m;
		ui.updateLabel->setText(x.c_str());
	}
	catch (RepositoryException& e)
	{
		ui.updateLabel->setText(e.what());
	}
	catch (FileException& e)
	{
		ui.updateLabel->setText(e.what());
	}


}

void MovieDatabaseGUI::filterButtonHandler()
{
	string genre = ui.filterEdit->text().toStdString();
	int count = 0;

	if (ctrl.getRepo().getMovies().size() == 0)
	{
		ui.updateLabel->setText("There are no movies yet!");
	}
	ui.repoList->clear();

	for (auto m : this->ctrl.getRepo().getMovies())
	{
		if (this->ctrl.checkGenre(m, genre) == true)
		{
			count++;
			string s = m.getTitle();
			s += "| ";
			s += m.getGenre();
			s += "| ";
			s += to_string(m.getYearOfRelease());
			s += "| ";
			s += to_string(m.getLikes());
			s += "| ";
			s += m.getTrailer();
			ui.repoList->addItem(s.c_str());
		}

	}

	if (count == 0)
	{
		string x = "There are no movies for this genre: ";
		x += genre;
		ui.updateLabel->setText(x.c_str());
		return;
	}
}

void MovieDatabaseGUI::moveToWatchList()
{
	ui.watchListView->addItem(ui.repoList->currentItem()->text().toStdString().c_str());
	string s = ui.repoList->currentItem()->text().toStdString().c_str();
	string title = s.substr(0, s.find("|"));
	Movie m = ctrl.getRepo().findMovieByTitle(title);
	ctrl.addMovieToWatchList(m);
}

void MovieDatabaseGUI::playButtonHandler()
{
	string s = ui.watchListView->currentItem()->text().toStdString().c_str();
	string title = s.substr(0, s.find("|"));
	vector<Movie> newv = ctrl.getWatchList()->getAll();

	for (auto m : newv)
	{
		if (m.getTitle() == title)
		{
			m.play();
			break;
		}
	}
}

void MovieDatabaseGUI::nextButtonHandler()
{
	for (int i = 0; i < ui.watchListView->count(); i++)

		if (ui.watchListView->item(i)->isSelected() != 0)
		{
			if (i == ui.watchListView->count() - 1)
				ui.watchListView->item(0)->setSelected(true);
			else
				ui.watchListView->item(i + 1)->setSelected(true);
			break;
		}
}

void MovieDatabaseGUI::deleteWatchListButtonHandler()
{
	string s = ui.watchListView->currentItem()->text().toStdString().c_str();
	string title = s.substr(0, s.find("|"));
	Movie m = ctrl.getWatchList()->findMovieByTitle(title);
	ctrl.removeMovieFromWatchList(m);

	QListWidgetItem *it = ui.watchListView->takeItem(ui.watchListView->currentRow());
	delete it;

	QWidget * popup = new QWidget{};
	QPushButton* yes = new QPushButton("Yes");
	QPushButton* no = new QPushButton("No");
	QLabel* message = new QLabel{ "Did you like the movie?" };
	
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(message);
	layout->addWidget(yes);
	layout->addWidget(no);

	QObject::connect(yes, &QPushButton::clicked, popup, [popup, this, m]() mutable
	{
		this->ctrl.likeMovieFromRepo(m);
		this->populate();
		ui.updateLabel->setText("Movie updated!");
		popup->close();

	});
	QObject::connect(no, SIGNAL(clicked()), popup, SLOT(close()));

	popup->setLayout(layout);
	popup->show();

}

void MovieDatabaseGUI::redoButtonHandler()
{
	if (redoVariable == true)
	{
		try
		{
			RedoAdd redoAdd{ ctrl.getRepo(), undoMovie };
			redoAdd.executeRedo();
			populate();
			ui.updateLabel->setText("Redo add successfull!");
		}
		catch (MovieException &e)
		{
			string x;
			for (auto m : e.getErrors())
				x += m;
			ui.updateLabel->setText(x.c_str());
		}
		catch (RepositoryException &e)
		{
			ui.updateLabel->setText(e.what());
		}
	}
	else
	{
		ui.updateLabel->setText("There aren't any operations to redo!");
	}
}

void MovieDatabaseGUI::undoButtonHandler()
{
	if (undoVariable == 1)
	{
		undoVariable = 0;
		try
		{
			UndoAdd undoAdd{ctrl.getRepo(), undoMovie};
			undoAdd.executeUndo();
			populate();
			ui.updateLabel->setText("Undo add successfull!");
		}
		catch(MovieException &e)
		{
			string x;
			for (auto m : e.getErrors())
				x += m;
			ui.updateLabel->setText(x.c_str());
		}
		catch (RepositoryException &e)
		{
			ui.updateLabel->setText(e.what());
		}
	}
	else if (undoVariable == 2)
	{
		undoVariable = 0;
		try
		{
			UndoRemove undoRemove{ ctrl.getRepo(), undoMovie };
			undoRemove.executeUndo();
			populate();
			ui.updateLabel->setText("Undo remove succesfull!");
		}
		catch (MovieException &e)
		{
			string x;
			for (auto m : e.getErrors())
				x += m;
			ui.updateLabel->setText(x.c_str());
		}
		catch (RepositoryException &e)
		{
			ui.updateLabel->setText(e.what());
		}
	}
	else if (undoVariable == 3)
	{
		undoVariable = 0;
		try
		{
			UndoUpdate undoUpdate{ ctrl.getRepo(), undoMovie, newMovie };
			undoUpdate.executeUndo();
			populate();
			ui.updateLabel->setText("Undo update succesfull!");
		}
		catch (MovieException &e)
		{
			string x;
			for (auto m : e.getErrors())
				x += m;
			ui.updateLabel->setText(x.c_str());
		}
		catch (RepositoryException &e)
		{
			ui.updateLabel->setText(e.what());
		}
	}
	else
	{
		ui.updateLabel->setText("There are no operations to undo!");
	}
}

void MovieDatabaseGUI::saveButtonHandler()
{
	string filename = ui.filenameLineEdit->text().toStdString();

	try
	{
		ctrl.save_WatchList(filename);
		if (ctrl.getWatchList() == nullptr)
		{
			ui.updateLabel->setText("Something went wrong when saving the file!");
			return;
		}
		ctrl.open_WatchList();
	}
	catch (FileException &e)
	{
		ui.updateLabel->setText(e.what());
	}
}



