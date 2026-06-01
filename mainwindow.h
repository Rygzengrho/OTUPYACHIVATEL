// Copyright (C) 2009 Blade <rygzengrho@yandex.ru>
//
// This file is part of OTUPYACHIVATEL.
//
// OTUPYACHIVATEL is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// OTUPYACHIVATEL is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with OTUPYACHIVATEL.  If not, see <http://www.gnu.org/licenses/>.

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QFileDialog>
#include <QtGui/QMessageBox>
#include <QTextStream>
#include <QTranslator>
#include <QTimer>
#include <QVector>
#include <QClipboard>
#include <QDebug>
#include "RandomGenerator.h"
#include "Config.h"
#include "aboutdialog.h"
#include "toolbarmodeform.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    bool m_bOKWasClicked;
    QTimer* AutoModeTimer;
    QClipboard* Clipboard;

    CConfig m_Config;

    AboutDialog About;
    ToolbarModeForm ToolbarForm;

    void CheckInputFieldReadOnly();
    void UpdateButtonsText();
    void OpenAndReadConfigFile( QFile *fFileName );
    void CheckAutoZlogenMode();
    void CopyToClipboard();
    void ProcessAndOutputText( QString* sInputText = 0 );
    void ChangeLanguage ( QString Language );

private slots:
    void on_ToolbarPushButton_clicked();
    void on_actionEnglish_triggered();
    void on_actionAbout_triggered();
    void on_actionRussian_triggered();
    void on_HtmlViewCheckBox_toggled(bool checked);
    void on_AutoModeGroupBox_toggled(bool );
    void on_ZlogenGroupBox_toggled(bool );
    void on_TopmostCheckBox_toggled(bool checked);
    void on_OpenConfigButton_clicked();
    void on_InputPlainTextEdit_textChanged();
    void on_OkButton_clicked();

    void AutoZlogenMode();
    void ClipboardChanged();

    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
};

#endif // MAINWINDOW_H
