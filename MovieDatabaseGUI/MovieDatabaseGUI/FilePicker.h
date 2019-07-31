#pragma once

#include <QWidget>
#include "ui_FilePicker.h"

class FilePicker : public QWidget
{
	Q_OBJECT

public:
	FilePicker(QWidget *parent = Q_NULLPTR);
	~FilePicker();

private:
	Ui::FilePicker ui;
};
