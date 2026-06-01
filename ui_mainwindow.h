/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 5. Dec 16:54:55 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRussian;
    QAction *actionEnglish;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *InputTextLabel;
    QPlainTextEdit *InputPlainTextEdit;
    QLabel *OutputTextLabel;
    QPlainTextEdit *OutputPlainTextEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *OutputTagsTextLabel;
    QCheckBox *HtmlViewCheckBox;
    QPlainTextEdit *OutputTagsPlainTextEdit;
    QTextBrowser *HtmlTextBrowser;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *OpenConfigButton;
    QCheckBox *TopmostCheckBox;
    QGroupBox *ZlogenGroupBox;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout_3;
    QLabel *IndustryLabel;
    QSpinBox *IndustrySpinBox;
    QLabel *SymbolLimitLabel;
    QSpinBox *SymbolLimitSpinBox;
    QGroupBox *BufferGroupBox;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QRadioButton *BufferTextRadioButton;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *BufferTagsRadioButton;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *OkButton;
    QPushButton *CancelButton;
    QGroupBox *AutoModeGroupBox;
    QVBoxLayout *verticalLayout_9;
    QFormLayout *formLayout_4;
    QLabel *IntervalLabel;
    QSpinBox *IntervalSpinBox;
    QGridLayout *gridLayout_4;
    QComboBox *TagGroupComboBox;
    QLabel *TagsGroupLabel;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *ToolbarPushButton;
    QLabel *ToolbarLabel;
    QMenuBar *menuBar;
    QMenu *menuLanguage;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(586, 545);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/UP4K-men.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionRussian = new QAction(MainWindow);
        actionRussian->setObjectName(QString::fromUtf8("actionRussian"));
        actionRussian->setCheckable(true);
        actionRussian->setText(QString::fromUtf8("\320\240\321\203\321\201\321\201\320\272\320\270\320\271"));
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        actionEnglish->setCheckable(true);
        actionEnglish->setText(QString::fromUtf8("English"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        InputTextLabel = new QLabel(centralWidget);
        InputTextLabel->setObjectName(QString::fromUtf8("InputTextLabel"));

        verticalLayout_2->addWidget(InputTextLabel);

        InputPlainTextEdit = new QPlainTextEdit(centralWidget);
        InputPlainTextEdit->setObjectName(QString::fromUtf8("InputPlainTextEdit"));
        InputPlainTextEdit->setTabChangesFocus(true);
        InputPlainTextEdit->setBackgroundVisible(false);

        verticalLayout_2->addWidget(InputPlainTextEdit);

        OutputTextLabel = new QLabel(centralWidget);
        OutputTextLabel->setObjectName(QString::fromUtf8("OutputTextLabel"));

        verticalLayout_2->addWidget(OutputTextLabel);

        OutputPlainTextEdit = new QPlainTextEdit(centralWidget);
        OutputPlainTextEdit->setObjectName(QString::fromUtf8("OutputPlainTextEdit"));
        OutputPlainTextEdit->setAcceptDrops(false);
        OutputPlainTextEdit->setTabChangesFocus(true);
        OutputPlainTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(OutputPlainTextEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        OutputTagsTextLabel = new QLabel(centralWidget);
        OutputTagsTextLabel->setObjectName(QString::fromUtf8("OutputTagsTextLabel"));

        horizontalLayout->addWidget(OutputTagsTextLabel);

        HtmlViewCheckBox = new QCheckBox(centralWidget);
        HtmlViewCheckBox->setObjectName(QString::fromUtf8("HtmlViewCheckBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HtmlViewCheckBox->sizePolicy().hasHeightForWidth());
        HtmlViewCheckBox->setSizePolicy(sizePolicy);
        HtmlViewCheckBox->setChecked(false);

        horizontalLayout->addWidget(HtmlViewCheckBox);


        verticalLayout_2->addLayout(horizontalLayout);

        OutputTagsPlainTextEdit = new QPlainTextEdit(centralWidget);
        OutputTagsPlainTextEdit->setObjectName(QString::fromUtf8("OutputTagsPlainTextEdit"));
        OutputTagsPlainTextEdit->setAcceptDrops(false);
        OutputTagsPlainTextEdit->setTabChangesFocus(true);
        OutputTagsPlainTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(OutputTagsPlainTextEdit);


        gridLayout_5->addLayout(verticalLayout_2, 0, 0, 1, 1);

        HtmlTextBrowser = new QTextBrowser(centralWidget);
        HtmlTextBrowser->setObjectName(QString::fromUtf8("HtmlTextBrowser"));
        HtmlTextBrowser->setEnabled(true);
        HtmlTextBrowser->setAcceptDrops(false);
        HtmlTextBrowser->setOpenExternalLinks(true);

        gridLayout_5->addWidget(HtmlTextBrowser, 0, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetMaximumSize);
        OpenConfigButton = new QToolButton(centralWidget);
        OpenConfigButton->setObjectName(QString::fromUtf8("OpenConfigButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(OpenConfigButton->sizePolicy().hasHeightForWidth());
        OpenConfigButton->setSizePolicy(sizePolicy1);
        OpenConfigButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        OpenConfigButton->setAutoRaise(false);

        horizontalLayout_6->addWidget(OpenConfigButton);

        TopmostCheckBox = new QCheckBox(centralWidget);
        TopmostCheckBox->setObjectName(QString::fromUtf8("TopmostCheckBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(TopmostCheckBox->sizePolicy().hasHeightForWidth());
        TopmostCheckBox->setSizePolicy(sizePolicy2);
        TopmostCheckBox->setMouseTracking(false);
        TopmostCheckBox->setAutoRepeat(false);
        TopmostCheckBox->setAutoRepeatDelay(300);
        TopmostCheckBox->setAutoRepeatInterval(100);

        horizontalLayout_6->addWidget(TopmostCheckBox);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 1, 1, 1);

        ZlogenGroupBox = new QGroupBox(centralWidget);
        ZlogenGroupBox->setObjectName(QString::fromUtf8("ZlogenGroupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ZlogenGroupBox->sizePolicy().hasHeightForWidth());
        ZlogenGroupBox->setSizePolicy(sizePolicy3);
        ZlogenGroupBox->setCheckable(true);
        ZlogenGroupBox->setChecked(false);
        verticalLayout_4 = new QVBoxLayout(ZlogenGroupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMaximumSize);
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        IndustryLabel = new QLabel(ZlogenGroupBox);
        IndustryLabel->setObjectName(QString::fromUtf8("IndustryLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(IndustryLabel->sizePolicy().hasHeightForWidth());
        IndustryLabel->setSizePolicy(sizePolicy4);
        IndustryLabel->setOpenExternalLinks(false);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, IndustryLabel);

        IndustrySpinBox = new QSpinBox(ZlogenGroupBox);
        IndustrySpinBox->setObjectName(QString::fromUtf8("IndustrySpinBox"));
        IndustrySpinBox->setAccelerated(true);
        IndustrySpinBox->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        IndustrySpinBox->setMinimum(1);
        IndustrySpinBox->setMaximum(512);
        IndustrySpinBox->setValue(10);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, IndustrySpinBox);

        SymbolLimitLabel = new QLabel(ZlogenGroupBox);
        SymbolLimitLabel->setObjectName(QString::fromUtf8("SymbolLimitLabel"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, SymbolLimitLabel);

        SymbolLimitSpinBox = new QSpinBox(ZlogenGroupBox);
        SymbolLimitSpinBox->setObjectName(QString::fromUtf8("SymbolLimitSpinBox"));
        SymbolLimitSpinBox->setAccelerated(true);
        SymbolLimitSpinBox->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        SymbolLimitSpinBox->setMaximum(10000);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, SymbolLimitSpinBox);


        verticalLayout_4->addLayout(formLayout_3);


        gridLayout_2->addWidget(ZlogenGroupBox, 1, 2, 1, 1);

        BufferGroupBox = new QGroupBox(centralWidget);
        BufferGroupBox->setObjectName(QString::fromUtf8("BufferGroupBox"));
        sizePolicy2.setHeightForWidth(BufferGroupBox->sizePolicy().hasHeightForWidth());
        BufferGroupBox->setSizePolicy(sizePolicy2);
        BufferGroupBox->setFlat(false);
        BufferGroupBox->setCheckable(true);
        BufferGroupBox->setChecked(false);
        verticalLayout_6 = new QVBoxLayout(BufferGroupBox);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setSizeConstraint(QLayout::SetMaximumSize);
        BufferTextRadioButton = new QRadioButton(BufferGroupBox);
        BufferTextRadioButton->setObjectName(QString::fromUtf8("BufferTextRadioButton"));
        sizePolicy.setHeightForWidth(BufferTextRadioButton->sizePolicy().hasHeightForWidth());
        BufferTextRadioButton->setSizePolicy(sizePolicy);
        BufferTextRadioButton->setMouseTracking(false);
        BufferTextRadioButton->setChecked(true);

        horizontalLayout_7->addWidget(BufferTextRadioButton);

        horizontalSpacer_5 = new QSpacerItem(60, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);

        BufferTagsRadioButton = new QRadioButton(BufferGroupBox);
        BufferTagsRadioButton->setObjectName(QString::fromUtf8("BufferTagsRadioButton"));
        sizePolicy.setHeightForWidth(BufferTagsRadioButton->sizePolicy().hasHeightForWidth());
        BufferTagsRadioButton->setSizePolicy(sizePolicy);
        BufferTagsRadioButton->setMouseTracking(false);
        BufferTagsRadioButton->setChecked(false);

        horizontalLayout_7->addWidget(BufferTagsRadioButton);

        horizontalLayout_7->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_7);


        gridLayout_2->addWidget(BufferGroupBox, 1, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 1, 3, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetMaximumSize);
        OkButton = new QPushButton(centralWidget);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        sizePolicy1.setHeightForWidth(OkButton->sizePolicy().hasHeightForWidth());
        OkButton->setSizePolicy(sizePolicy1);
        OkButton->setAutoDefault(true);
        OkButton->setDefault(true);

        horizontalLayout_8->addWidget(OkButton);

        CancelButton = new QPushButton(centralWidget);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        sizePolicy1.setHeightForWidth(CancelButton->sizePolicy().hasHeightForWidth());
        CancelButton->setSizePolicy(sizePolicy1);
        CancelButton->setAutoDefault(true);
        CancelButton->setDefault(false);

        horizontalLayout_8->addWidget(CancelButton);


        gridLayout_2->addLayout(horizontalLayout_8, 0, 2, 1, 1);

        AutoModeGroupBox = new QGroupBox(centralWidget);
        AutoModeGroupBox->setObjectName(QString::fromUtf8("AutoModeGroupBox"));
        sizePolicy3.setHeightForWidth(AutoModeGroupBox->sizePolicy().hasHeightForWidth());
        AutoModeGroupBox->setSizePolicy(sizePolicy3);
        AutoModeGroupBox->setCheckable(true);
        AutoModeGroupBox->setChecked(false);
        verticalLayout_9 = new QVBoxLayout(AutoModeGroupBox);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setSizeConstraint(QLayout::SetMaximumSize);
        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setSizeConstraint(QLayout::SetMaximumSize);
        IntervalLabel = new QLabel(AutoModeGroupBox);
        IntervalLabel->setObjectName(QString::fromUtf8("IntervalLabel"));
        IntervalLabel->setScaledContents(false);
        IntervalLabel->setWordWrap(false);
        IntervalLabel->setOpenExternalLinks(false);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, IntervalLabel);

        IntervalSpinBox = new QSpinBox(AutoModeGroupBox);
        IntervalSpinBox->setObjectName(QString::fromUtf8("IntervalSpinBox"));
        IntervalSpinBox->setAccelerated(true);
        IntervalSpinBox->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        IntervalSpinBox->setMinimum(100);
        IntervalSpinBox->setMaximum(10000);
        IntervalSpinBox->setSingleStep(100);
        IntervalSpinBox->setValue(1000);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, IntervalSpinBox);


        verticalLayout_9->addLayout(formLayout_4);


        gridLayout_2->addWidget(AutoModeGroupBox, 2, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        TagGroupComboBox = new QComboBox(centralWidget);
        TagGroupComboBox->setObjectName(QString::fromUtf8("TagGroupComboBox"));

        gridLayout_4->addWidget(TagGroupComboBox, 0, 2, 1, 1);

        TagsGroupLabel = new QLabel(centralWidget);
        TagsGroupLabel->setObjectName(QString::fromUtf8("TagsGroupLabel"));

        gridLayout_4->addWidget(TagsGroupLabel, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_8, 0, 0, 1, 1);

        ToolbarPushButton = new QPushButton(centralWidget);
        ToolbarPushButton->setObjectName(QString::fromUtf8("ToolbarPushButton"));
        ToolbarPushButton->setEnabled(false);

        gridLayout_4->addWidget(ToolbarPushButton, 1, 2, 1, 1);

        ToolbarLabel = new QLabel(centralWidget);
        ToolbarLabel->setObjectName(QString::fromUtf8("ToolbarLabel"));

        gridLayout_4->addWidget(ToolbarLabel, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 2, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 586, 21));
        menuLanguage = new QMenu(menuBar);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menuBar);
#ifndef QT_NO_SHORTCUT
        InputTextLabel->setBuddy(InputPlainTextEdit);
        OutputTextLabel->setBuddy(OutputPlainTextEdit);
        OutputTagsTextLabel->setBuddy(OutputTagsPlainTextEdit);
        IndustryLabel->setBuddy(IndustrySpinBox);
        SymbolLimitLabel->setBuddy(SymbolLimitSpinBox);
        IntervalLabel->setBuddy(IntervalSpinBox);
        TagsGroupLabel->setBuddy(TagGroupComboBox);
        ToolbarLabel->setBuddy(ToolbarPushButton);
#endif // QT_NO_SHORTCUT

        menuBar->addAction(menuLanguage->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuLanguage->addAction(actionRussian);
        menuLanguage->addAction(actionEnglish);
        menuAbout->addAction(actionAbout);

        retranslateUi(MainWindow);
        QObject::connect(CancelButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OTUPYACHIVATEL-3000", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        InputTextLabel->setText(QApplication::translate("MainWindow", "Sad text here:", 0, QApplication::UnicodeUTF8));
        OutputTextLabel->setText(QApplication::translate("MainWindow", "Awesome text get here:", 0, QApplication::UnicodeUTF8));
        OutputTagsTextLabel->setText(QApplication::translate("MainWindow", "And herse is text with cats:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        HtmlViewCheckBox->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Adds a field to the right that shows how text will look with all used tags</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">(understands only html-tags)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        HtmlViewCheckBox->setText(QApplication::translate("MainWindow", "&Html-cat preview", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        OpenConfigButton->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Open another configuration file</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        OpenConfigButton->setText(QApplication::translate("MainWindow", "Rel&oad\n"
"ray-launcher", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        TopmostCheckBox->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">If checked - determines that this windows will be topmost</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        TopmostCheckBox->setText(QApplication::translate("MainWindow", "Abo&ve the sadness", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ZlogenGroupBox->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Mode, in which text is generated depending on the random additions in </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">the config file</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ZlogenGroupBox->setTitle(QApplication::translate("MainWindow", "R&ays of shit generation mode", 0, QApplication::UnicodeUTF8));
        IndustryLabel->setText(QApplication::translate("MainWindow", "In&dustry (512 - max)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        IndustrySpinBox->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Industry sets amount of generated additions</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        SymbolLimitLabel->setText(QApplication::translate("MainWindow", "&Symbols limit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SymbolLimitSpinBox->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Symbols limit sets, above which quantity of symbols in result text that</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">text will be cut. Is required if the sad forum has the symbols limit in</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">their messages. 0 means that text won't be cut</"
                        "span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        BufferGroupBox->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Mode, in which all result texts will be copied to the clipboard, ready for</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">paste</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        BufferGroupBox->setTitle(QApplication::translate("MainWindow", "&Copy results to the clipboard", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        BufferTextRadioButton->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">To the clipboard will be copied text from the field \"awesome text\"</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        BufferTextRadioButton->setText(QApplication::translate("MainWindow", "Just te&xt", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        BufferTagsRadioButton->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">To the clipboard will be copied text from the field \"text with cats\"</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        BufferTagsRadioButton->setText(QApplication::translate("MainWindow", "Te&xt with cats", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("MainWindow", "&Make text better", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        CancelButton->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Exit the program</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        CancelButton->setText(QApplication::translate("MainWindow", "Aww, scre&w that :(", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        AutoModeGroupBox->setToolTip(QApplication::translate("MainWindow", "Mode, in which program will work automatically. And what will it do\n"
"depends on: turned on zlogen mode, or not", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        AutoModeGroupBox->setTitle(QApplication::translate("MainWindow", "A&utopepyaka mode", 0, QApplication::UnicodeUTF8));
        IntervalLabel->setText(QApplication::translate("MainWindow", "&Interval (10000 - max)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        IntervalSpinBox->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Interval between two rays of shit generations in auto-zlogen mode.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Is set in milliseconds.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Max - 10000 (which equals to 10 seconds)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Min - 100 (which equals to one-tenth on second)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        TagGroupComboBox->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Chooses set of tags from the config</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        TagsGroupLabel->setText(QApplication::translate("MainWindow", "Cats &group", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ToolbarPushButton->setToolTip(QApplication::translate("MainWindow", "Not implemented yet", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ToolbarPushButton->setText(QApplication::translate("MainWindow", "Off", 0, QApplication::UnicodeUTF8));
        ToolbarLabel->setText(QApplication::translate("MainWindow", "Tool&bar mode", 0, QApplication::UnicodeUTF8));
        menuLanguage->setTitle(QApplication::translate("MainWindow", "Language", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
