/********************************************************************************
** Form generated from reading ui file 'otupyachivateldialog.ui'
**
** Created: Mon 11. May 16:11:03 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OTUPYACHIVATELDIALOG_H
#define UI_OTUPYACHIVATELDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OtupyachivatelDialog
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *InputTextLabel;
    QPlainTextEdit *InputPlainTextEdit;
    QLabel *OutputTextLabel;
    QPlainTextEdit *OutputPlainTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *OutputTagsTextLabel;
    QCheckBox *HtmlViewCheckBox;
    QPlainTextEdit *OutputTagsPlainTextEdit;
    QTextBrowser *HtmlTextBrowser;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *OpenConfigButton;
    QCheckBox *TopmostCheckBox;
    QGroupBox *ZlogenGroupBox;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_2;
    QLabel *IndustryLabel;
    QSpinBox *IndustrySpinBox;
    QLabel *SymbolLimitLabel;
    QSpinBox *SymbolLimitSpinBox;
    QGroupBox *BufferGroupBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QRadioButton *BufferTextRadioButton;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *BufferTagsRadioButton;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *OkButton;
    QPushButton *CancelButton;
    QGroupBox *AutoModeGroupBox;
    QVBoxLayout *verticalLayout_8;
    QFormLayout *formLayout;
    QLabel *IntervalLabel;
    QSpinBox *IntervalSpinBox;
    QGridLayout *gridLayout_3;
    QComboBox *TagGroupComboBox;
    QLabel *TagsGroupLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *ToolbarPushButton;
    QLabel *ToolbarLabel;

    void setupUi(QDialog *OtupyachivatelDialog)
    {
        if (OtupyachivatelDialog->objectName().isEmpty())
            OtupyachivatelDialog->setObjectName(QString::fromUtf8("OtupyachivatelDialog"));
        OtupyachivatelDialog->resize(586, 586);
        OtupyachivatelDialog->setContextMenuPolicy(Qt::PreventContextMenu);
        OtupyachivatelDialog->setAcceptDrops(true);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/UP4K-men.ico")), QIcon::Normal, QIcon::Off);
        icon.addPixmap(QPixmap(QString::fromUtf8(":/UP4K-men Sitting.ico")), QIcon::Disabled, QIcon::Off);
        OtupyachivatelDialog->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(OtupyachivatelDialog);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(10);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        InputTextLabel = new QLabel(OtupyachivatelDialog);
        InputTextLabel->setObjectName(QString::fromUtf8("InputTextLabel"));

        verticalLayout->addWidget(InputTextLabel);

        InputPlainTextEdit = new QPlainTextEdit(OtupyachivatelDialog);
        InputPlainTextEdit->setObjectName(QString::fromUtf8("InputPlainTextEdit"));
        InputPlainTextEdit->setTabChangesFocus(true);
        InputPlainTextEdit->setBackgroundVisible(false);

        verticalLayout->addWidget(InputPlainTextEdit);

        OutputTextLabel = new QLabel(OtupyachivatelDialog);
        OutputTextLabel->setObjectName(QString::fromUtf8("OutputTextLabel"));

        verticalLayout->addWidget(OutputTextLabel);

        OutputPlainTextEdit = new QPlainTextEdit(OtupyachivatelDialog);
        OutputPlainTextEdit->setObjectName(QString::fromUtf8("OutputPlainTextEdit"));
        OutputPlainTextEdit->setAcceptDrops(false);
        OutputPlainTextEdit->setTabChangesFocus(true);
        OutputPlainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(OutputPlainTextEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        OutputTagsTextLabel = new QLabel(OtupyachivatelDialog);
        OutputTagsTextLabel->setObjectName(QString::fromUtf8("OutputTagsTextLabel"));

        horizontalLayout_3->addWidget(OutputTagsTextLabel);

        HtmlViewCheckBox = new QCheckBox(OtupyachivatelDialog);
        HtmlViewCheckBox->setObjectName(QString::fromUtf8("HtmlViewCheckBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HtmlViewCheckBox->sizePolicy().hasHeightForWidth());
        HtmlViewCheckBox->setSizePolicy(sizePolicy);
        HtmlViewCheckBox->setChecked(false);

        horizontalLayout_3->addWidget(HtmlViewCheckBox);


        verticalLayout->addLayout(horizontalLayout_3);

        OutputTagsPlainTextEdit = new QPlainTextEdit(OtupyachivatelDialog);
        OutputTagsPlainTextEdit->setObjectName(QString::fromUtf8("OutputTagsPlainTextEdit"));
        OutputTagsPlainTextEdit->setAcceptDrops(false);
        OutputTagsPlainTextEdit->setTabChangesFocus(true);
        OutputTagsPlainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(OutputTagsPlainTextEdit);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        HtmlTextBrowser = new QTextBrowser(OtupyachivatelDialog);
        HtmlTextBrowser->setObjectName(QString::fromUtf8("HtmlTextBrowser"));
        HtmlTextBrowser->setEnabled(true);
        HtmlTextBrowser->setAcceptDrops(false);
        HtmlTextBrowser->setOpenExternalLinks(true);

        gridLayout_2->addWidget(HtmlTextBrowser, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        OpenConfigButton = new QToolButton(OtupyachivatelDialog);
        OpenConfigButton->setObjectName(QString::fromUtf8("OpenConfigButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(OpenConfigButton->sizePolicy().hasHeightForWidth());
        OpenConfigButton->setSizePolicy(sizePolicy1);
        OpenConfigButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        OpenConfigButton->setAutoRaise(false);

        horizontalLayout_2->addWidget(OpenConfigButton);

        TopmostCheckBox = new QCheckBox(OtupyachivatelDialog);
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

        horizontalLayout_2->addWidget(TopmostCheckBox);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        ZlogenGroupBox = new QGroupBox(OtupyachivatelDialog);
        ZlogenGroupBox->setObjectName(QString::fromUtf8("ZlogenGroupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ZlogenGroupBox->sizePolicy().hasHeightForWidth());
        ZlogenGroupBox->setSizePolicy(sizePolicy3);
        ZlogenGroupBox->setCheckable(true);
        ZlogenGroupBox->setChecked(false);
        verticalLayout_3 = new QVBoxLayout(ZlogenGroupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setMargin(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        IndustryLabel = new QLabel(ZlogenGroupBox);
        IndustryLabel->setObjectName(QString::fromUtf8("IndustryLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(IndustryLabel->sizePolicy().hasHeightForWidth());
        IndustryLabel->setSizePolicy(sizePolicy4);
        IndustryLabel->setOpenExternalLinks(false);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, IndustryLabel);

        IndustrySpinBox = new QSpinBox(ZlogenGroupBox);
        IndustrySpinBox->setObjectName(QString::fromUtf8("IndustrySpinBox"));
        IndustrySpinBox->setAccelerated(true);
        IndustrySpinBox->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        IndustrySpinBox->setMinimum(1);
        IndustrySpinBox->setMaximum(512);
        IndustrySpinBox->setValue(10);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, IndustrySpinBox);

        SymbolLimitLabel = new QLabel(ZlogenGroupBox);
        SymbolLimitLabel->setObjectName(QString::fromUtf8("SymbolLimitLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, SymbolLimitLabel);

        SymbolLimitSpinBox = new QSpinBox(ZlogenGroupBox);
        SymbolLimitSpinBox->setObjectName(QString::fromUtf8("SymbolLimitSpinBox"));
        SymbolLimitSpinBox->setAccelerated(true);
        SymbolLimitSpinBox->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        SymbolLimitSpinBox->setMaximum(10000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, SymbolLimitSpinBox);


        verticalLayout_3->addLayout(formLayout_2);


        gridLayout->addWidget(ZlogenGroupBox, 1, 2, 1, 1);

        BufferGroupBox = new QGroupBox(OtupyachivatelDialog);
        BufferGroupBox->setObjectName(QString::fromUtf8("BufferGroupBox"));
        sizePolicy2.setHeightForWidth(BufferGroupBox->sizePolicy().hasHeightForWidth());
        BufferGroupBox->setSizePolicy(sizePolicy2);
        BufferGroupBox->setFlat(false);
        BufferGroupBox->setCheckable(true);
        BufferGroupBox->setChecked(false);
        verticalLayout_5 = new QVBoxLayout(BufferGroupBox);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setMargin(10);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        BufferTextRadioButton = new QRadioButton(BufferGroupBox);
        BufferTextRadioButton->setObjectName(QString::fromUtf8("BufferTextRadioButton"));
        sizePolicy.setHeightForWidth(BufferTextRadioButton->sizePolicy().hasHeightForWidth());
        BufferTextRadioButton->setSizePolicy(sizePolicy);
        BufferTextRadioButton->setMouseTracking(false);
        BufferTextRadioButton->setChecked(true);

        horizontalLayout->addWidget(BufferTextRadioButton);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        BufferTagsRadioButton = new QRadioButton(BufferGroupBox);
        BufferTagsRadioButton->setObjectName(QString::fromUtf8("BufferTagsRadioButton"));
        sizePolicy.setHeightForWidth(BufferTagsRadioButton->sizePolicy().hasHeightForWidth());
        BufferTagsRadioButton->setSizePolicy(sizePolicy);
        BufferTagsRadioButton->setMouseTracking(false);
        BufferTagsRadioButton->setChecked(false);

        horizontalLayout->addWidget(BufferTagsRadioButton);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_5->addLayout(horizontalLayout);


        gridLayout->addWidget(BufferGroupBox, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 3, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMaximumSize);
        OkButton = new QPushButton(OtupyachivatelDialog);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        sizePolicy1.setHeightForWidth(OkButton->sizePolicy().hasHeightForWidth());
        OkButton->setSizePolicy(sizePolicy1);
        OkButton->setAutoDefault(true);
        OkButton->setDefault(true);

        horizontalLayout_4->addWidget(OkButton);

        CancelButton = new QPushButton(OtupyachivatelDialog);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        sizePolicy1.setHeightForWidth(CancelButton->sizePolicy().hasHeightForWidth());
        CancelButton->setSizePolicy(sizePolicy1);
        CancelButton->setAutoDefault(true);
        CancelButton->setDefault(false);

        horizontalLayout_4->addWidget(CancelButton);


        gridLayout->addLayout(horizontalLayout_4, 0, 2, 1, 1);

        AutoModeGroupBox = new QGroupBox(OtupyachivatelDialog);
        AutoModeGroupBox->setObjectName(QString::fromUtf8("AutoModeGroupBox"));
        sizePolicy3.setHeightForWidth(AutoModeGroupBox->sizePolicy().hasHeightForWidth());
        AutoModeGroupBox->setSizePolicy(sizePolicy3);
        AutoModeGroupBox->setCheckable(true);
        AutoModeGroupBox->setChecked(false);
        verticalLayout_8 = new QVBoxLayout(AutoModeGroupBox);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setMargin(10);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setSizeConstraint(QLayout::SetMaximumSize);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetMaximumSize);
        IntervalLabel = new QLabel(AutoModeGroupBox);
        IntervalLabel->setObjectName(QString::fromUtf8("IntervalLabel"));
        IntervalLabel->setScaledContents(false);
        IntervalLabel->setWordWrap(false);
        IntervalLabel->setOpenExternalLinks(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, IntervalLabel);

        IntervalSpinBox = new QSpinBox(AutoModeGroupBox);
        IntervalSpinBox->setObjectName(QString::fromUtf8("IntervalSpinBox"));
        IntervalSpinBox->setAccelerated(true);
        IntervalSpinBox->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        IntervalSpinBox->setMinimum(100);
        IntervalSpinBox->setMaximum(10000);
        IntervalSpinBox->setSingleStep(100);
        IntervalSpinBox->setValue(1000);

        formLayout->setWidget(0, QFormLayout::FieldRole, IntervalSpinBox);


        verticalLayout_8->addLayout(formLayout);


        gridLayout->addWidget(AutoModeGroupBox, 2, 1, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        TagGroupComboBox = new QComboBox(OtupyachivatelDialog);
        TagGroupComboBox->setObjectName(QString::fromUtf8("TagGroupComboBox"));

        gridLayout_3->addWidget(TagGroupComboBox, 0, 2, 1, 1);

        TagsGroupLabel = new QLabel(OtupyachivatelDialog);
        TagsGroupLabel->setObjectName(QString::fromUtf8("TagsGroupLabel"));

        gridLayout_3->addWidget(TagsGroupLabel, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        ToolbarPushButton = new QPushButton(OtupyachivatelDialog);
        ToolbarPushButton->setObjectName(QString::fromUtf8("ToolbarPushButton"));

        gridLayout_3->addWidget(ToolbarPushButton, 1, 2, 1, 1);

        ToolbarLabel = new QLabel(OtupyachivatelDialog);
        ToolbarLabel->setObjectName(QString::fromUtf8("ToolbarLabel"));

        gridLayout_3->addWidget(ToolbarLabel, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_3, 2, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

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
        QWidget::setTabOrder(InputPlainTextEdit, OkButton);
        QWidget::setTabOrder(OkButton, OutputPlainTextEdit);
        QWidget::setTabOrder(OutputPlainTextEdit, OutputTagsPlainTextEdit);
        QWidget::setTabOrder(OutputTagsPlainTextEdit, OpenConfigButton);
        QWidget::setTabOrder(OpenConfigButton, TopmostCheckBox);
        QWidget::setTabOrder(TopmostCheckBox, BufferGroupBox);
        QWidget::setTabOrder(BufferGroupBox, BufferTextRadioButton);
        QWidget::setTabOrder(BufferTextRadioButton, BufferTagsRadioButton);
        QWidget::setTabOrder(BufferTagsRadioButton, ZlogenGroupBox);
        QWidget::setTabOrder(ZlogenGroupBox, IndustrySpinBox);
        QWidget::setTabOrder(IndustrySpinBox, SymbolLimitSpinBox);
        QWidget::setTabOrder(SymbolLimitSpinBox, AutoModeGroupBox);
        QWidget::setTabOrder(AutoModeGroupBox, IntervalSpinBox);
        QWidget::setTabOrder(IntervalSpinBox, HtmlViewCheckBox);
        QWidget::setTabOrder(HtmlViewCheckBox, HtmlTextBrowser);
        QWidget::setTabOrder(HtmlTextBrowser, CancelButton);

        retranslateUi(OtupyachivatelDialog);
        QObject::connect(CancelButton, SIGNAL(clicked()), OtupyachivatelDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(OtupyachivatelDialog);
    } // setupUi

    void retranslateUi(QDialog *OtupyachivatelDialog)
    {
        OtupyachivatelDialog->setWindowTitle(QApplication::translate("OtupyachivatelDialog", "\320\236\320\242\320\243\320\237\320\257\320\247\320\230\320\222\320\220\320\242\320\225\320\233\320\254-3000", 0, QApplication::UnicodeUTF8));
        InputTextLabel->setText(QApplication::translate("OtupyachivatelDialog", "&\320\243\320\275\321\213\320\273\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \321\201\321\216\320\264\320\260:", 0, QApplication::UnicodeUTF8));
        OutputTextLabel->setText(QApplication::translate("OtupyachivatelDialog", "\320\236\321\205\321\203\320\265\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202 \320\277\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\267\320\264\320\265\321\201\321\214:", 0, QApplication::UnicodeUTF8));
        OutputTagsTextLabel->setText(QApplication::translate("OtupyachivatelDialog", "\320\220 \321\202\321\203\321\202\321\201\321\217 \321\202\320\265\320\272\321\201\321\202 \321\201 \320\272\320\276\321\202\320\260\320\274\320\270:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        HtmlViewCheckBox->setToolTip(QApplication::translate("OtupyachivatelDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\321\217\320\265\321\202 \321\201\320\277\321\200\320\260\320\262\320\260 \320\276\320\272\320\276\321\210\320\272\320\276 \320\264\320\273\321\217 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217 \321\202\320\276\320\263\320\276, \320\272\320\260\320\272 \320\261\321\203\320\264\320\265\321\202\n"
"\320\262\321\213\320\263\320\273\321\217\320\264\320\265\321\202\321\214 \321\202\320\265\320\272\321\201\321\202 (\320\277\320\276\320\275\320\270\320\274\320\260\320\265\321\202 \321\202\320\276\320\273\321\214\320\272\320\276 html-\321\202\320\265\320\263\320\270)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        HtmlViewCheckBox->setText(QApplication::translate("OtupyachivatelDialog", "\320\237\321\200\320\265\320\262\321\214\321\216 html-\320\272\320\276\321\202\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        OpenConfigButton->setToolTip(QApplication::translate("OtupyachivatelDialog", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\264\321\200\321\203\320\263\320\276\320\271 \321\204\320\260\320\271\320\273 \320\272\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        OpenConfigButton->setText(QApplication::translate("OtupyachivatelDialog", "\320\236\321\202&\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273\n"
"\320\272\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        TopmostCheckBox->setToolTip(QApplication::translate("OtupyachivatelDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\236\320\277\321\200\320\265\320\264\320\265\320\273\321\217\320\265\321\202, \321\207\321\202\320\276 \321\215\321\202\320\276 \320\276\320\272\320\275\320\276 \320\261\321\203\320\264\320\265\321\202 \320\262\321\201\320\265\320\263\320\264\320\260 \320\277\320\276\320\262\320\265\321\200\321\205 \320\264\321\200\321\203\320\263\320\270\321\205 \320\276\320\272\320\276\320\275</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span "
                        "style=\" font-size:8pt;\">\320\237\320\276\320\272\320\260 \321\207\321\202\320\276 \320\275\320\265 \321\200\320\260\320\261\320\276\321\202\320\260\320\265</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        TopmostCheckBox->setText(QApplication::translate("OtupyachivatelDialog", "&\320\237\320\276\320\262\320\265\321\200\321\205 \321\203\320\275\321\213\320\273\321\213\321\205 \320\276\320\272\320\276\320\275", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ZlogenGroupBox->setToolTip(QApplication::translate("OtupyachivatelDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\240\320\265\320\266\320\270\320\274, \320\262 \320\272\320\276\321\202\320\276\321\200\320\276\320\274 \320\275\320\265 \320\270\320\267\320\274\320\265\320\275\321\217\320\265\321\202\321\201\321\217 \320\267\320\260\320\264\320\260\320\275\320\275\321\213\320\271 \321\202\320\265\320\272\321\201\321\202, \320\260 \320\263\320\265\320\275\320\265\321\200\320\270\321\200\321\203\320\265\321\202\321\201\321\217</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-in"
                        "dent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\275\320\276\320\262\321\213\320\271, \320\270\320\267 \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\213\321\205 \320\262\321\201\321\202\320\260\320\262\320\276\320\272, \320\272\320\276\321\202\320\276\321\200\321\213\320\265 \320\277\321\200\320\276\320\277\320\270\321\201\320\260\320\275\321\213 \320\262 \320\272\320\276\320\275\321\204\320\270\320\263\320\265</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ZlogenGroupBox->setTitle(QApplication::translate("OtupyachivatelDialog", "&\320\240\320\265\320\266\320\270\320\274 \320\263\320\265\320\275\320\265\321\200\320\260\321\202\320\276\321\200\320\260 \320\273\321\203\321\207\320\265\320\271 \320\277\320\276\320\275\320\276\321\201\320\260", 0, QApplication::UnicodeUTF8));
        IndustryLabel->setText(QApplication::translate("OtupyachivatelDialog", "\320\237\321\200\320\276\320\274&\321\213\321\210\320\273 (512 - max)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        IndustrySpinBox->setToolTip(QApplication::translate("OtupyachivatelDialog", "\320\237\321\200\320\276\320\274\321\213\321\210\320\273\320\265\320\275\320\275\320\276\321\201\321\202\321\214 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\321\217\320\265\321\202 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\263\320\265\320\275\320\265\321\200\320\270\321\200\321\203\320\265\320\274\321\213\321\205 \320\262\321\201\321\202\320\260\320\262\320\276\320\272", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        SymbolLimitLabel->setText(QApplication::translate("OtupyachivatelDialog", "\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265 \320\277\320\276 \321\201\320\270\320\274\320\262\320\276\320\273\320\260\320\274", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SymbolLimitSpinBox->setToolTip(QApplication::translate("OtupyachivatelDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265 \320\277\320\276 \321\201\320\270\320\274\320\262\320\276\320\273\320\260\320\274 \320\267\320\260\320\264\320\260\320\265\321\202, \320\261\320\276\320\273\321\214\321\210\320\265 \320\272\320\260\320\272\320\276\320\263\320\276 \321\200\320\260\320\267\320\274\320\265\321\200\320\260 \321\202\320\265\320\272\321\201\321\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-inde"
                        "nt:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\261\321\203\320\264\320\265\321\202 \320\276\320\261\321\200\320\265\320\267\320\260\321\202\321\214\321\201\321\217. \320\235\321\203\320\266\320\275\320\276 \320\265\321\201\320\273\320\270 \320\275\320\260 \321\203\320\275\321\213\320\273\320\276\320\274 \321\204\320\276\321\200\321\203\320\274\320\265 \321\201\321\202\320\276\320\270\321\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265 \320\277\320\276 \320\272\320\276\320\273-\320\262\321\203 \321\201\320\270\320\274\320\262\320\276\320\273\320\276\320\262. 0 \320\276\320\267\320\275\320\260\321\207\320\260\320\265\321\202, \321\207\321\202\320\276 \321\202\320\265\320\272\321\201\321\202 \320\276\320\261\321\200\320\265\320\267\320\260\321\202\321\214\321\201\321\217</span></p>\n"
"<p "
                        "style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\275\320\265 \320\261\321\203\320\264\320\265\321\202</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        BufferGroupBox->setToolTip(QApplication::translate("OtupyachivatelDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\240\320\265\320\266\320\270\320\274, \320\262 \320\272\320\276\321\202\320\276\321\200\320\276\320\274 \320\262\321\201\320\265 \320\276\321\202\321\203\320\277\321\217\321\207\320\265\320\275\320\275\321\213\320\265 \320\270 \321\201\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265 \321\202\320\265\320\272\321\201\321\202\321\213</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-inden"
                        "t:0px;\"><span style=\" font-size:8pt;\">\320\261\321\203\320\264\321\203\321\202  \321\201\320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\321\213 \320\262 \320\261\321\203\321\204\320\265\321\200 \320\276\320\261\320\274\320\265\320\275\320\260, \321\202\320\260\320\272 \321\207\321\202\320\276 \320\262\320\260\320\274 \320\275\320\265 \320\275\321\203\320\266\320\275\320\276 \320\261\321\203\320\264\320\265\321\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\270\321\205 \320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\262\321\200\321\203\321\207\320\275\321\203\321\216</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        BufferGroupBox->setTitle(QApplication::translate("OtupyachivatelDialog", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\260 \320\262 \320\261\321\203\321\204\320\265\321\200 \320\276\320\261&\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        BufferTextRadioButton->setToolTip(QApplication::translate("OtupyachivatelDialog", "\320\222 \320\261\321\203\321\204\320\265\321\200 \320\261\321\203\320\264\320\265\321\202 \320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217 \321\202\320\265\320\272\321\201\321\202 \320\270\320\267 \320\277\320\276\320\273\321\217 \321\202\320\265\320\272\321\201\321\202\320\260 \320\261\320\265\320\267 \321\202\320\265\320\263\320\276\320\262", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        BufferTextRadioButton->setText(QApplication::translate("OtupyachivatelDialog", "&\320\242\320\265\320\272\321\201\321\202", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        BufferTagsRadioButton->setToolTip(QApplication::translate("OtupyachivatelDialog", "\320\222 \320\261\321\203\321\204\320\265\321\200 \320\261\321\203\320\264\320\265\321\202 \320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217 \321\202\320\265\320\272\321\201\321\202 \320\270\320\267 \320\277\320\276\320\273\321\217 \321\202\320\265\320\272\321\201\321\202\320\260 \321\201 \321\202\320\265\320\263\320\260\320\274\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        BufferTagsRadioButton->setText(QApplication::translate("OtupyachivatelDialog", "\320\242\320\265\320\272\321\201\321\202 \321\201 \320\272\320\276\321\202\320\260\320\274&\320\270", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("OtupyachivatelDialog", "&\320\236\321\202\321\203\320\277\321\217\321\207\320\270\321\202\321\214 \321\202\320\265\320\272\321\201\321\202", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        CancelButton->setToolTip(QApplication::translate("OtupyachivatelDialog", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        CancelButton->setText(QApplication::translate("OtupyachivatelDialog", "&\320\224\320\260 \320\275\321\203 \320\262 \320\277\320\270\320\267\320\264\321\203 :(", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        AutoModeGroupBox->setToolTip(QApplication::translate("OtupyachivatelDialog", "\320\240\320\265\320\266\320\270\320\274, \320\272\320\276\320\263\320\264\320\260 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \321\200\320\260\320\261\320\276\321\202\320\260\320\265\321\202 \320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270. \320\230 \321\207\321\202\320\276 \320\276\320\275\320\260 \320\264\320\265\320\273\320\260\320\265\321\202 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\321\217\320\265\321\202\321\201\321\217 \321\202\320\265\320\274, \320\262\320\272\320\273\321\216\321\207\320\265\320\275 \321\200\320\265\320\266\320\270\320\274 \320\267\320\273\320\276\320\263\320\265\320\275\320\260, \320\270\320\273\320\270 \320\275\320\265\321\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        AutoModeGroupBox->setTitle(QApplication::translate("OtupyachivatelDialog", "\320\240\320\265\320\266\320\270\320\274 &\320\260\320\262\321\202\320\276\320\277\320\276\320\277\321\217\321\207\320\270\320\262\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        IntervalLabel->setText(QApplication::translate("OtupyachivatelDialog", "\320\230\320\275\321\202\320\265\321\200&\320\262\320\260\320\273 (10000 - max)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        IntervalSpinBox->setToolTip(QApplication::translate("OtupyachivatelDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273 \320\274\320\265\320\266\320\264\321\203 \320\263\320\265\320\275\320\265\321\200\320\260\321\206\320\270\320\265\320\271 \320\273\321\203\321\207\320\265\320\271 \320\277\320\276\320\275\320\276\321\201\320\260 \320\262 \321\200\320\265\320\266\320\270\320\274\320\265 \320\267\320\273\320\276\320\263\320\265\320\275\320\260.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\""
                        "><span style=\" font-size:8pt;\">\320\227\320\260\320\264\320\260\320\265\321\202\321\201\321\217 \320\262 \320\274\320\270\320\273\320\273\320\270\321\201\320\265\320\272\321\203\320\275\320\264\320\260\321\205. \320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274 - 10000 (\321\207\321\202\320\276 \321\215\320\272\320\262\320\270\320\262\320\260\320\273\320\265\320\275\321\202\320\275\320\276</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">10 \321\201\320\265\320\272\321\203\320\275\320\264\320\260\320\274), \320\274\320\270\320\275\320\270\320\274\321\203\320\274 - 100 (\321\207\321\202\320\276 \321\215\320\272\320\262\320\270\320\262\320\260\320\273\320\265\320\275\321\202\320\275\320\276 \320\264\320\265\321\201\321\217\321\202\320\276\320\271 \321\201\320\265\320\272\321\203\320\275\320\264\321\213)</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        TagGroupComboBox->setToolTip(QApplication::translate("OtupyachivatelDialog", "\320\222\321\213\320\261\320\276\321\200 \320\270\320\267 \320\263\321\200\321\203\320\277\320\277\321\213 \320\272\320\276\321\202\320\276\320\262, \321\201\321\207\320\270\321\202\320\260\320\275\320\275\321\213\321\205 \320\270\320\267 \320\272\320\276\320\275\321\204\320\270\320\263\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        TagsGroupLabel->setText(QApplication::translate("OtupyachivatelDialog", "\320\222\321\213\320\261\320\276\321\200 \320\263\321\200\321\203\320\277\320\277\321\213 \320\272\320\276\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        ToolbarPushButton->setText(QApplication::translate("OtupyachivatelDialog", "\320\222\320\272\320\273", 0, QApplication::UnicodeUTF8));
        ToolbarLabel->setText(QApplication::translate("OtupyachivatelDialog", "\320\240\320\265\320\266\320\270\320\274 \321\202\321\203\320\273\320\261\320\260\321\200\320\260", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(OtupyachivatelDialog);
    } // retranslateUi

};

namespace Ui {
    class OtupyachivatelDialog: public Ui_OtupyachivatelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTUPYACHIVATELDIALOG_H
