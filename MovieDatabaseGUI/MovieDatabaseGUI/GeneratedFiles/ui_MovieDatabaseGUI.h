/********************************************************************************
** Form generated from reading UI file 'MovieDatabaseGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIEDATABASEGUI_H
#define UI_MOVIEDATABASEGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MovieDatabaseGUIClass
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QListWidget *watchListView;
    QPushButton *addToWatchListButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *playWatchList;
    QPushButton *nextWatchList;
    QPushButton *saveWatchList;
    QLabel *updateLabel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QListWidget *repoList;
    QLineEdit *titleEdit;
    QLineEdit *genreEdit;
    QLineEdit *yearOfReleaseEdit;
    QLineEdit *likesEdit;
    QLineEdit *trailerEdit;
    QPushButton *addMovieButton;
    QPushButton *deleteMovieButton;
    QPushButton *filterMoviesButton;
    QLineEdit *filterEdit;
    QPushButton *updateButton;
    QLineEdit *oldTitleEdit;
    QPushButton *removeWatchListButton;
    QLineEdit *filenameLineEdit;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MovieDatabaseGUIClass)
    {
        if (MovieDatabaseGUIClass->objectName().isEmpty())
            MovieDatabaseGUIClass->setObjectName(QStringLiteral("MovieDatabaseGUIClass"));
        MovieDatabaseGUIClass->resize(845, 693);
        actionExit = new QAction(MovieDatabaseGUIClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MovieDatabaseGUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        watchListView = new QListWidget(centralWidget);
        watchListView->setObjectName(QStringLiteral("watchListView"));
        watchListView->setGeometry(QRect(460, 30, 261, 481));
        addToWatchListButton = new QPushButton(centralWidget);
        addToWatchListButton->setObjectName(QStringLiteral("addToWatchListButton"));
        addToWatchListButton->setGeometry(QRect(380, 140, 71, 23));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 250, 81, 131));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        playWatchList = new QPushButton(centralWidget);
        playWatchList->setObjectName(QStringLiteral("playWatchList"));
        playWatchList->setGeometry(QRect(550, 530, 75, 23));
        nextWatchList = new QPushButton(centralWidget);
        nextWatchList->setObjectName(QStringLiteral("nextWatchList"));
        nextWatchList->setGeometry(QRect(640, 530, 75, 23));
        saveWatchList = new QPushButton(centralWidget);
        saveWatchList->setObjectName(QStringLiteral("saveWatchList"));
        saveWatchList->setGeometry(QRect(550, 560, 75, 23));
        updateLabel = new QLabel(centralWidget);
        updateLabel->setObjectName(QStringLiteral("updateLabel"));
        updateLabel->setGeometry(QRect(30, 560, 371, 71));
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 20, 271, 531));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(layoutWidget1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        repoList = new QListWidget(layoutWidget1);
        repoList->setObjectName(QStringLiteral("repoList"));

        verticalLayout->addWidget(repoList);

        titleEdit = new QLineEdit(layoutWidget1);
        titleEdit->setObjectName(QStringLiteral("titleEdit"));

        verticalLayout->addWidget(titleEdit);

        genreEdit = new QLineEdit(layoutWidget1);
        genreEdit->setObjectName(QStringLiteral("genreEdit"));

        verticalLayout->addWidget(genreEdit);

        yearOfReleaseEdit = new QLineEdit(layoutWidget1);
        yearOfReleaseEdit->setObjectName(QStringLiteral("yearOfReleaseEdit"));

        verticalLayout->addWidget(yearOfReleaseEdit);

        likesEdit = new QLineEdit(layoutWidget1);
        likesEdit->setObjectName(QStringLiteral("likesEdit"));

        verticalLayout->addWidget(likesEdit);

        trailerEdit = new QLineEdit(layoutWidget1);
        trailerEdit->setObjectName(QStringLiteral("trailerEdit"));

        verticalLayout->addWidget(trailerEdit);

        addMovieButton = new QPushButton(layoutWidget1);
        addMovieButton->setObjectName(QStringLiteral("addMovieButton"));

        verticalLayout->addWidget(addMovieButton);

        deleteMovieButton = new QPushButton(layoutWidget1);
        deleteMovieButton->setObjectName(QStringLiteral("deleteMovieButton"));

        verticalLayout->addWidget(deleteMovieButton);

        filterMoviesButton = new QPushButton(layoutWidget1);
        filterMoviesButton->setObjectName(QStringLiteral("filterMoviesButton"));

        verticalLayout->addWidget(filterMoviesButton);

        filterEdit = new QLineEdit(layoutWidget1);
        filterEdit->setObjectName(QStringLiteral("filterEdit"));

        verticalLayout->addWidget(filterEdit);

        updateButton = new QPushButton(layoutWidget1);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        verticalLayout->addWidget(updateButton);

        oldTitleEdit = new QLineEdit(layoutWidget1);
        oldTitleEdit->setObjectName(QStringLiteral("oldTitleEdit"));

        verticalLayout->addWidget(oldTitleEdit);

        removeWatchListButton = new QPushButton(centralWidget);
        removeWatchListButton->setObjectName(QStringLiteral("removeWatchListButton"));
        removeWatchListButton->setGeometry(QRect(460, 530, 75, 23));
        filenameLineEdit = new QLineEdit(centralWidget);
        filenameLineEdit->setObjectName(QStringLiteral("filenameLineEdit"));
        filenameLineEdit->setGeometry(QRect(640, 561, 111, 20));
        undoButton = new QPushButton(centralWidget);
        undoButton->setObjectName(QStringLiteral("undoButton"));
        undoButton->setGeometry(QRect(20, 50, 75, 23));
        redoButton = new QPushButton(centralWidget);
        redoButton->setObjectName(QStringLiteral("redoButton"));
        redoButton->setGeometry(QRect(20, 80, 75, 23));
        MovieDatabaseGUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MovieDatabaseGUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 845, 21));
        MovieDatabaseGUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MovieDatabaseGUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MovieDatabaseGUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MovieDatabaseGUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MovieDatabaseGUIClass->setStatusBar(statusBar);

        retranslateUi(MovieDatabaseGUIClass);

        QMetaObject::connectSlotsByName(MovieDatabaseGUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *MovieDatabaseGUIClass)
    {
        MovieDatabaseGUIClass->setWindowTitle(QApplication::translate("MovieDatabaseGUIClass", "MovieDatabaseGUI", nullptr));
        actionExit->setText(QApplication::translate("MovieDatabaseGUIClass", "Exit", nullptr));
        addToWatchListButton->setText(QApplication::translate("MovieDatabaseGUIClass", ">", nullptr));
        label->setText(QApplication::translate("MovieDatabaseGUIClass", "Title:", nullptr));
        label_2->setText(QApplication::translate("MovieDatabaseGUIClass", "Genre:", nullptr));
        label_3->setText(QApplication::translate("MovieDatabaseGUIClass", "Year of release:", nullptr));
        label_4->setText(QApplication::translate("MovieDatabaseGUIClass", "Likes:", nullptr));
        label_5->setText(QApplication::translate("MovieDatabaseGUIClass", "Trailer:", nullptr));
        playWatchList->setText(QApplication::translate("MovieDatabaseGUIClass", "Play", nullptr));
        nextWatchList->setText(QApplication::translate("MovieDatabaseGUIClass", "Next", nullptr));
        saveWatchList->setText(QApplication::translate("MovieDatabaseGUIClass", "Save", nullptr));
        updateLabel->setText(QString());
        comboBox->setItemText(0, QApplication::translate("MovieDatabaseGUIClass", "Detailed", nullptr));
        comboBox->setItemText(1, QApplication::translate("MovieDatabaseGUIClass", "Short", nullptr));

        addMovieButton->setText(QApplication::translate("MovieDatabaseGUIClass", "Add", nullptr));
        deleteMovieButton->setText(QApplication::translate("MovieDatabaseGUIClass", "Delete", nullptr));
        filterMoviesButton->setText(QApplication::translate("MovieDatabaseGUIClass", "Filter", nullptr));
        filterEdit->setText(QApplication::translate("MovieDatabaseGUIClass", "Genre to filter", nullptr));
        updateButton->setText(QApplication::translate("MovieDatabaseGUIClass", "Update", nullptr));
        oldTitleEdit->setText(QApplication::translate("MovieDatabaseGUIClass", "Old title", nullptr));
        removeWatchListButton->setText(QApplication::translate("MovieDatabaseGUIClass", "Delete", nullptr));
        filenameLineEdit->setInputMask(QString());
        filenameLineEdit->setText(QApplication::translate("MovieDatabaseGUIClass", "name.html/csv", nullptr));
        undoButton->setText(QApplication::translate("MovieDatabaseGUIClass", "Undo", nullptr));
        redoButton->setText(QApplication::translate("MovieDatabaseGUIClass", "Redo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MovieDatabaseGUIClass: public Ui_MovieDatabaseGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIEDATABASEGUI_H
