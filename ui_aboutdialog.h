/********************************************************************************
** Form generated from reading ui file 'aboutdialog.ui'
**
** Created: Tue 9. Jun 17:38:20 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QPushButton *OKPushButton;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->setWindowModality(Qt::ApplicationModal);
        AboutDialog->resize(235, 86);
        AboutDialog->setModal(true);
        horizontalLayout = new QHBoxLayout(AboutDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(AboutDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/UP4K-men Sitting.ico")));
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        label = new QLabel(AboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        OKPushButton = new QPushButton(AboutDialog);
        OKPushButton->setObjectName(QString::fromUtf8("OKPushButton"));

        horizontalLayout->addWidget(OKPushButton);


        retranslateUi(AboutDialog);
        QObject::connect(OKPushButton, SIGNAL(pressed()), AboutDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "About", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Blade (C).</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">GLORY TO THE UPYACHKA!</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        OKPushButton->setText(QApplication::translate("AboutDialog", "Ok, i got it", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AboutDialog);
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
