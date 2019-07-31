#ifndef MOVIESWIDGET_H
#define MOVIESWIDGET_H

#include <QWidget>
#include "ui_MoviesWidget.h"
#include "Repository.h"

class MoviesWidget : public QWidget
{
	Q_OBJECT

public:
	MoviesWidget(Repository &r, QAbstractItemModel* model, QWidget *parent = Q_NULLPTR);
	~MoviesWidget();

private:
	Ui::MoviesWidget ui;
	Repository& repo;

	QAbstractItemModel* tableModel;
};


#endif // MOVIESSWIDGET_H