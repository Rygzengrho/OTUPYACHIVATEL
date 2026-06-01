#ifndef TOOLBARMODEFORM_H
#define TOOLBARMODEFORM_H

#include <QtGui/QWidget>
#include "Config.h"

namespace Ui {
    class ToolbarModeForm;
}

class ToolbarModeForm : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(ToolbarModeForm)
public:
    explicit ToolbarModeForm(QWidget *parent = 0);
    virtual ~ToolbarModeForm();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::ToolbarModeForm *m_ui;
};

#endif // TOOLBARMODEFORM_H
