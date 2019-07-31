#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <qcombobox.h>
#include <QListWidget>
#include <QHBoxLayout>
#include <QFormLayout>
#include <qstring.h>
#include <qtextedit.h> 
#include "MovieDatabaseGUI.h"
#include <QtWidgets/QApplication>
#include "CSVWatchlist.h"
#include "FilePicker.h"
#include "Movie.h"
#include <crtdbg.h>
#include "ui_FilePicker.h"
#include "ui_MovieDatabaseGUI.h"
#include "ui_MoviesWidget.h"
#include "MoviesTableModel.h"
#include <QSortFilterProxyModel>
#include "MoviesWidget.h"

int main(int argc, char *argv[])
{
	

	QApplication a(argc, argv);
	FilePicker choice{ NULL };
	choice.show();

	Repository repo{ "movies.txt" };
	MoviesTableModel* tableModel = new MoviesTableModel{ repo };

	QSortFilterProxyModel* sortModel = new QSortFilterProxyModel{};
	sortModel->setSourceModel(tableModel);
	MoviesWidget MoviesTableWidget{ repo, sortModel };
	MoviesTableWidget.setWindowTitle("Movie list");
	MoviesTableWidget.show();

	return a.exec();
}
