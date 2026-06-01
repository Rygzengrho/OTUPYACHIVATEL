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

#include "mainwindow.h"
#include "ui_mainwindow.h"

QTranslator AppTranslator;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // Initialization of variables
    m_bOKWasClicked = false;

    AutoModeTimer = new QTimer ( this );
    Clipboard = QApplication::clipboard();

    connect( AutoModeTimer, SIGNAL(timeout()), this, SLOT(AutoZlogenMode()) );
    connect( Clipboard, SIGNAL(dataChanged()), this, SLOT(ClipboardChanged()) );

    // Now the rest
    ui->setupUi(this);

    ui->HtmlTextBrowser->setVisible ( false );

    // Setting russian translation if present
    // Fucking hardcode
    if ( AppTranslator.load("otupyachivatel_ru") )
	ui->actionRussian->setChecked( true );
    else
	ui->actionEnglish->setChecked( true );

    ui->retranslateUi(this);

    // Parsing "default.ini"
    QFile fFileName ("default.ini");
    OpenAndReadConfigFile( &fFileName );

    // Resizing in case if we need to remove empty space from hidden htmlBrowser
    //this->resize( this->width() - ui->HtmlTextBrowser->width() - ui->gridLayout_2->horizontalSpacing(), this->height() );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_OkButton_clicked()
{
    QString sInputText = ui->InputPlainTextEdit->toPlainText();

    ProcessAndOutputText ( &sInputText );

    // For debug's sake
    //m_Config.TestRegExp( &sInputText );
}

void MainWindow::UpdateButtonsText()
{
    if ( ui->ZlogenGroupBox->isChecked() )
    {
	ui->OkButton->setText( tr("GSO&MMMM!!11") );
    }
    else if ( m_bOKWasClicked )
    {
	ui->OkButton->setText( tr("&More!") );
    }
    else
    {
	ui->OkButton->setText( tr("&Make text better") );
	ui->CancelButton->setText( tr("Aww, scre&w that :(") );
    }

    if ( m_bOKWasClicked )
    {
	ui->CancelButton->setText( tr("&That's enuff") );
    }
}

void MainWindow::OpenAndReadConfigFile( QFile *fFileName )
{
    qDebug() << "Name of opening file: " + fFileName->fileName() ;

    // Nothing was opened
    if ( fFileName->fileName().isEmpty() )
	return;

    QString sCheck;

    // Get extension
    if ( fFileName->fileName().size() >= 3 )
	sCheck = fFileName->fileName().right( 3 );
    else
    {
	QMessageBox::warning( this, tr("Error"), tr("Incorrect file extension: ") + fFileName->fileName());
	return;
    }

    // Check extension
    if ( sCheck != "ini" )
    {
	QMessageBox::warning( this, tr("Error"), tr("Incorrect file extension: ") + fFileName->fileName());
	return;
    }

    if ( !fFileName->open(QIODevice::ReadOnly | QIODevice::Text) )
    {
	QMessageBox::warning( this, tr("Error"), tr("Program was unable to open file: ") + fFileName->fileName());
	return;
    }

    QTextStream tsFile(fFileName);

    QString sConfig = tsFile.readAll();

    qDebug() << "Text from file: \n" + sConfig ;

    m_Config.Clear();

    ui->TagGroupComboBox->clear();

    if ( m_Config.ParseConfig ( &sConfig ) )
    {
	QMessageBox::warning( this, tr("Error"), tr("Config file contains mistakes. Program will work, but you could get not what you are expecting."));
    }
    else
    {
	for ( int i = 0 ; i < m_Config.GetTagsVectorSize() ; i++ )
	{
	    ui->TagGroupComboBox->addItem( QString( "%1" ).arg(i) );
	}
    }
}

void MainWindow::on_InputPlainTextEdit_textChanged()
{
    m_bOKWasClicked = false;
    UpdateButtonsText();
}

void MainWindow::on_OpenConfigButton_clicked()
{
    QFile fFileName;

    fFileName.setFileName( QFileDialog::getOpenFileName(this, tr("Choose configuration file"), "/", tr("Config Files (*.ini);;All Files (*.*)")) );

    OpenAndReadConfigFile( &fFileName );
}

void MainWindow::on_TopmostCheckBox_toggled(bool checked)
{
    if ( checked )
    {
	Qt::WindowFlags flags = this->windowFlags();
	flags |= Qt::WindowStaysOnTopHint;

	this->setWindowFlags( flags );
	this->show();
    }
    else
    {
	Qt::WindowFlags flags = this->windowFlags();
	flags = Qt::WindowFlags( flags - Qt::WindowStaysOnTopHint );

	this->setWindowFlags( flags );
	this->show();
    }
}

void MainWindow::on_ZlogenGroupBox_toggled(bool )
{
    CheckInputFieldReadOnly();
    CheckAutoZlogenMode();
    UpdateButtonsText();
}

void MainWindow::on_AutoModeGroupBox_toggled(bool )
{
    CheckInputFieldReadOnly();
    CheckAutoZlogenMode();
}

void MainWindow::CheckInputFieldReadOnly()
{
    if ( ui->AutoModeGroupBox->isChecked() || ui->ZlogenGroupBox->isChecked() )
    {
	ui->InputPlainTextEdit->setReadOnly( true );
    }
    else
	ui->InputPlainTextEdit->setReadOnly( false );
}

void MainWindow::CheckAutoZlogenMode()
{
    if ( ui->AutoModeGroupBox->isChecked() && ui->ZlogenGroupBox->isChecked() )
    {
	AutoModeTimer->start( ui->IntervalSpinBox->value());
    }
    else
    {
	AutoModeTimer->stop();
    }
}

void MainWindow::AutoZlogenMode()
{
    ProcessAndOutputText ( );

    AutoModeTimer->stop();
    AutoModeTimer->start( ui->IntervalSpinBox->value());
}

void MainWindow::ClipboardChanged()
{
    const QMimeData* MimeData = Clipboard->mimeData();

    if ( ui->AutoModeGroupBox->isChecked() && !ui->ZlogenGroupBox->isChecked() && MimeData->hasText() )
    {
	QString sInputText = Clipboard->text();

	ProcessAndOutputText ( &sInputText );
    }
}

void MainWindow::CopyToClipboard()
{
    if ( ui->BufferTextRadioButton->isChecked() )
    {
	Clipboard->setText( ui->OutputPlainTextEdit->toPlainText() );
    }
    else if ( ui->BufferTagsRadioButton->isChecked() )
    {
	Clipboard->setText( ui->OutputTagsPlainTextEdit->toPlainText() );
    }
}

void MainWindow::ProcessAndOutputText( QString* sInputText )
{
    QVector <QString> strVector;

    QString sOutputText;
    QString sOutputTextTags;

    if ( ui->ZlogenGroupBox->isChecked() )
    {
	int nZlogenAmount = ui->IndustrySpinBox->value();
	strVector = m_Config.GenerateAdditionsVector ( nZlogenAmount );
    }
    else
    {
	strVector = m_Config.OtupyachitText ( *sInputText );
    }

    sOutputText = m_Config.VectorToString ( &strVector );

    bool ok;
    uint unTagsGroup = ui->TagGroupComboBox->currentText().toUInt( &ok, 10 );
    if ( ok )
    {
	strVector = m_Config.AddTags ( &strVector, unTagsGroup );
    }

    sOutputTextTags = m_Config.VectorToString ( m_Config.AddStyle( &strVector ));

    if ( int SymbLim = ui->SymbolLimitSpinBox->value() )
    {
	if ( sOutputText.length() > SymbLim )
	    sOutputText = sOutputText.left ( SymbLim );
	if ( sOutputTextTags.length() > SymbLim )
	    sOutputTextTags = sOutputTextTags.left ( SymbLim );
    }

    ui->OutputPlainTextEdit->setPlainText( sOutputText );
    ui->OutputTagsPlainTextEdit->setPlainText( sOutputTextTags );

    ui->HtmlTextBrowser->setText( sOutputTextTags );

    m_bOKWasClicked = true;

    if ( ui->BufferGroupBox->isChecked() )
    {
	CopyToClipboard();
    }

    UpdateButtonsText();
}

void MainWindow::on_HtmlViewCheckBox_toggled(bool checked)
{
    ui->HtmlTextBrowser->setVisible( checked );

    if ( checked )
    {
	this->resize( (this->width() - ui->gridLayout_2->horizontalSpacing()) * 2 - 2, this->height() );
    }
    else
    {
	this->resize( this->width() - ui->HtmlTextBrowser->width() - ui->gridLayout_2->horizontalSpacing(), this->height() );
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
	event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    if ( event->mimeData()->urls().size() > 1 )
    {
	QMessageBox::warning( this, tr("Error"), tr("It's possible to have only one active configuration file at once."));
	event->ignore();
    }
    else
    {
	QFile File ( event->mimeData()->urls()[0].toLocalFile() );
	OpenAndReadConfigFile ( &File );
	event->acceptProposedAction();
    }
}

void MainWindow::on_actionRussian_triggered()
{
    ChangeLanguage ( "Russian" );
}

void MainWindow::on_actionEnglish_triggered()
{
    ChangeLanguage ( "English" );
}

void MainWindow::ChangeLanguage ( QString Language )
{
    if ( Language == "Russian" )
    {
	if ( AppTranslator.load("otupyachivatel_ru") )
	{
	    ui->actionRussian->setChecked( true );
	    ui->actionEnglish->setChecked( false );
	}
	else
	    ui->actionRussian->setChecked( false );
    }
    else
    {
	AppTranslator.load("otupyachivatel");
	ui->actionEnglish->setChecked( true );
	ui->actionRussian->setChecked( false );
    }
    ui->retranslateUi( this );
}

void MainWindow::on_actionAbout_triggered()
{
    About.show();
}

void MainWindow::on_ToolbarPushButton_clicked()
{
    //ToolbarForm.show();
    //this->hide();
}
