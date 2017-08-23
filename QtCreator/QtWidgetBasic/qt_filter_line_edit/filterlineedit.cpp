#include "filterlineedit.h"

FilterLineEdit::FilterLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    this->setPlaceholderText(tr("Filter"));
    this->setClearButtonEnabled(true);
}
