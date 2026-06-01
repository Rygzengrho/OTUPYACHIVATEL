#include "toolbarmodeform.h"
#include "ui_toolbarmodeform.h"

ToolbarModeForm::ToolbarModeForm(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::ToolbarModeForm)
{
    m_ui->setupUi(this);
}

ToolbarModeForm::~ToolbarModeForm()
{
    delete m_ui;
}

void ToolbarModeForm::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
