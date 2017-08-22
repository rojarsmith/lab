#include "qimagetogglebutton.h"

QImageToggleButton::QImageToggleButton(QWidget *parent)
    : QPushButton(parent),
      m_parentWidget(parent)
{
    this->setCheckable(true);
    this->setStyleSheet(
                "QPushButton:hover:!pressed {"
                "background-color: rgb(167, 205, 255);"
                "border-style: outset;"
                "border-width: 1px; border-color: green;"
                "}"

                "QPushButton:hover:pressed {"
                "background-color: rgb(167, 205, 255);"
                "border-style: outset;"
                "border-width: 1px; border-color: red;"
                "}"

                "QPushButton[PushDown=true]{"
                "background-color: rgb(167, 205, 255);"
                "border-style: outset;"
                "border-width: 1px; border-color: green;"
                "}"

                "QPushButton[PushDown=false]{"
                "background-color: transparent;"
                "border-style: outset;"
                "border-width: 1px; border-color: transparent;"
                "}"

                "QPushButton {"
                "qproperty-icon: url(://images/add_element_36x36.png);"
                ////"background-image: url(://images/add_element_36x36.png);"
                "background-color: transparent;"
                "border-style: outset;"
                "border-width: 1px; "
                "border-color: beige;"
                "padding-left: 10px;"
                "text-align: left;"
                "padding-right: 20px;"
                "background-position: center left;"
                "background-repeat: no-repeat;"
                "background-origin: content;"
                "}"
                );

    connect(this, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}

void QImageToggleButton::buttonClicked()
{    
    if(this->isChecked()){
        this->setProperty("PushDown", true);
        this->style()->unpolish(this);
        this->style()->polish(this);
    }else{
        this->setProperty("PushDown", false);
        this->style()->unpolish(this);
        this->style()->polish(this);
    }

    QMessageBox::information(m_parentWidget, "Toggled!", QString("The button is %1!").arg(this->isChecked()?"pressed":"released") );
}
