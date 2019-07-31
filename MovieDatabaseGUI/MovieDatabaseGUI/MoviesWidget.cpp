#include "MoviesWidget.h"

MoviesWidget::MoviesWidget(Repository &r, QAbstractItemModel* model, QWidget *parent)
	: QWidget(parent), repo{ r }, tableModel{ model }
{
	ui.setupUi(this);

	// force the columns to resize, according to the size of the tabe view
	this->ui.moviesTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	this->ui.moviesTableView->setModel(this->tableModel);

	this->ui.moviesTableView->setSortingEnabled(true);


}


MoviesWidget::~MoviesWidget()
{
}
