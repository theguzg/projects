#include "FilePicker.h"
#include "Repository.h"
#include "Controller.h"
#include "CSVWatchList.h"
#include "HTMLWatchList.h"
#include "MovieDatabaseGUI.h"

FilePicker::FilePicker(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	QObject::connect(ui.CSVButton, &QPushButton::clicked, this, [this]()
	{
		Repository repo("Movies.txt");
		FileWatchList* watchList = new CSVWatchlist{};

		Controller ctrl{ repo, watchList};
		MovieDatabaseGUI* n = new MovieDatabaseGUI(ctrl, NULL);
		n->show();
		close();

	});

	QObject::connect(ui.HTMLButton, &QPushButton::clicked, this, [this]()
	{
		Repository repo("Movies.txt");
		FileWatchList* watchList = new HTMLWatchList{};

		Controller ctrl{ repo, watchList};
		MovieDatabaseGUI* n = new MovieDatabaseGUI(ctrl, NULL);
		n->show();
		close();
	});
}

FilePicker::~FilePicker()
{
}
