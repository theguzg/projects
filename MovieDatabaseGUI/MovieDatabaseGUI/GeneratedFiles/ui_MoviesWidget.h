/********************************************************************************
** Form generated from reading UI file 'MoviesWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIESWIDGET_H
#define UI_MOVIESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MoviesWidget
{
public:
    QTableView *moviesTableView;

    void setupUi(QWidget *MoviesWidget)
    {
        if (MoviesWidget->objectName().isEmpty())
            MoviesWidget->setObjectName(QStringLiteral("MoviesWidget"));
        MoviesWidget->resize(753, 448);
        moviesTableView = new QTableView(MoviesWidget);
        moviesTableView->setObjectName(QStringLiteral("moviesTableView"));
        moviesTableView->setGeometry(QRect(10, 10, 731, 431));

        retranslateUi(MoviesWidget);

        QMetaObject::connectSlotsByName(MoviesWidget);
    } // setupUi

    void retranslateUi(QWidget *MoviesWidget)
    {
        MoviesWidget->setWindowTitle(QApplication::translate("MoviesWidget", "MoviesWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MoviesWidget: public Ui_MoviesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIESWIDGET_H
