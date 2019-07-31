/********************************************************************************
** Form generated from reading UI file 'FilePicker.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEPICKER_H
#define UI_FILEPICKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilePicker
{
public:
    QLabel *label;
    QPushButton *CSVButton;
    QPushButton *HTMLButton;

    void setupUi(QWidget *FilePicker)
    {
        if (FilePicker->objectName().isEmpty())
            FilePicker->setObjectName(QStringLiteral("FilePicker"));
        FilePicker->resize(698, 396);
        label = new QLabel(FilePicker);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 10, 321, 121));
        label->setLineWidth(1);
        label->setScaledContents(false);
        label->setIndent(-1);
        CSVButton = new QPushButton(FilePicker);
        CSVButton->setObjectName(QStringLiteral("CSVButton"));
        CSVButton->setGeometry(QRect(80, 160, 221, 131));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        CSVButton->setFont(font);
        HTMLButton = new QPushButton(FilePicker);
        HTMLButton->setObjectName(QStringLiteral("HTMLButton"));
        HTMLButton->setGeometry(QRect(390, 160, 221, 131));
        HTMLButton->setFont(font);

        retranslateUi(FilePicker);

        QMetaObject::connectSlotsByName(FilePicker);
    } // setupUi

    void retranslateUi(QWidget *FilePicker)
    {
        FilePicker->setWindowTitle(QApplication::translate("FilePicker", "FilePicker", nullptr));
        label->setText(QApplication::translate("FilePicker", "<html><head/><body><p><span style=\" font-size:26pt;\">Pick the type of file</span></p></body></html>", nullptr));
#ifndef QT_NO_WHATSTHIS
        CSVButton->setWhatsThis(QApplication::translate("FilePicker", "<html><head/><body><p><span style=\" font-size:14pt;\">DECE</span></p></body></html>", nullptr));
#endif // QT_NO_WHATSTHIS
        CSVButton->setText(QApplication::translate("FilePicker", "CSV", nullptr));
        HTMLButton->setText(QApplication::translate("FilePicker", "HTML", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilePicker: public Ui_FilePicker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEPICKER_H
