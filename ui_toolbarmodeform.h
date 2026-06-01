/********************************************************************************
** Form generated from reading ui file 'toolbarmodeform.ui'
**
** Created: Sat 6. Jun 18:21:06 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TOOLBARMODEFORM_H
#define UI_TOOLBARMODEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolbarModeForm
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *OpenConfigButton;
    QPushButton *AutoModeButton;
    QPushButton *BufferButton;
    QPushButton *ZlogenButton;
    QSpinBox *IndustrySpinBox;
    QComboBox *TagGroupComboBox;
    QPushButton *TopmostPushButton;

    void setupUi(QWidget *ToolbarModeForm)
    {
        if (ToolbarModeForm->objectName().isEmpty())
            ToolbarModeForm->setObjectName(QString::fromUtf8("ToolbarModeForm"));
        ToolbarModeForm->resize(490, 41);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ToolbarModeForm->sizePolicy().hasHeightForWidth());
        ToolbarModeForm->setSizePolicy(sizePolicy);
        ToolbarModeForm->setAcceptDrops(true);
        QIcon icon;
        icon.addPixmap(QPixmap(QString::fromUtf8(":/UP4K-men.ico")), QIcon::Normal, QIcon::Off);
        ToolbarModeForm->setWindowIcon(icon);
        ToolbarModeForm->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout = new QHBoxLayout(ToolbarModeForm);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        OpenConfigButton = new QToolButton(ToolbarModeForm);
        OpenConfigButton->setObjectName(QString::fromUtf8("OpenConfigButton"));

        horizontalLayout->addWidget(OpenConfigButton);

        AutoModeButton = new QPushButton(ToolbarModeForm);
        AutoModeButton->setObjectName(QString::fromUtf8("AutoModeButton"));
        AutoModeButton->setCheckable(true);

        horizontalLayout->addWidget(AutoModeButton);

        BufferButton = new QPushButton(ToolbarModeForm);
        BufferButton->setObjectName(QString::fromUtf8("BufferButton"));
        BufferButton->setCheckable(true);

        horizontalLayout->addWidget(BufferButton);

        ZlogenButton = new QPushButton(ToolbarModeForm);
        ZlogenButton->setObjectName(QString::fromUtf8("ZlogenButton"));
        ZlogenButton->setCheckable(true);

        horizontalLayout->addWidget(ZlogenButton);

        IndustrySpinBox = new QSpinBox(ToolbarModeForm);
        IndustrySpinBox->setObjectName(QString::fromUtf8("IndustrySpinBox"));
        IndustrySpinBox->setAccelerated(true);
        IndustrySpinBox->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        IndustrySpinBox->setMinimum(1);
        IndustrySpinBox->setMaximum(512);
        IndustrySpinBox->setValue(10);

        horizontalLayout->addWidget(IndustrySpinBox);

        TagGroupComboBox = new QComboBox(ToolbarModeForm);
        TagGroupComboBox->setObjectName(QString::fromUtf8("TagGroupComboBox"));

        horizontalLayout->addWidget(TagGroupComboBox);

        TopmostPushButton = new QPushButton(ToolbarModeForm);
        TopmostPushButton->setObjectName(QString::fromUtf8("TopmostPushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TopmostPushButton->sizePolicy().hasHeightForWidth());
        TopmostPushButton->setSizePolicy(sizePolicy1);
        TopmostPushButton->setCheckable(true);

        horizontalLayout->addWidget(TopmostPushButton);


        retranslateUi(ToolbarModeForm);

        QMetaObject::connectSlotsByName(ToolbarModeForm);
    } // setupUi

    void retranslateUi(QWidget *ToolbarModeForm)
    {
        ToolbarModeForm->setWindowTitle(QApplication::translate("ToolbarModeForm", "OTUPYACHIVATEL-3000", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        OpenConfigButton->setToolTip(QApplication::translate("ToolbarModeForm", "Open another configuration file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        OpenConfigButton->setText(QApplication::translate("ToolbarModeForm", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        AutoModeButton->setToolTip(QApplication::translate("ToolbarModeForm", "Mode, in which program will work automatically. And what will it do\n"
"depends on: turned on zlogen mode, or not", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        AutoModeButton->setText(QApplication::translate("ToolbarModeForm", "A&uto", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        BufferButton->setToolTip(QApplication::translate("ToolbarModeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Determines, which text will be copied to the buffer</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        BufferButton->setText(QApplication::translate("ToolbarModeForm", "Te&xt", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ZlogenButton->setToolTip(QApplication::translate("ToolbarModeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Mode, in which text is generated depending on the random additions in </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">the config file</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ZlogenButton->setText(QApplication::translate("ToolbarModeForm", "&Zlogen", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        IndustrySpinBox->setToolTip(QApplication::translate("ToolbarModeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Industry sets amount of generated additions</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        TagGroupComboBox->setToolTip(QApplication::translate("ToolbarModeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Chooses set of tags from the config</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        TopmostPushButton->setToolTip(QApplication::translate("ToolbarModeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">If checked - determines that this windows will be topmost</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        TopmostPushButton->setText(QApplication::translate("ToolbarModeForm", "&Topmost", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ToolbarModeForm);
    } // retranslateUi

};

namespace Ui {
    class ToolbarModeForm: public Ui_ToolbarModeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBARMODEFORM_H
