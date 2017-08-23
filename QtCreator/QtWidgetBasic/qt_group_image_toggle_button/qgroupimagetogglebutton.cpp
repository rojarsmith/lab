#include "qgroupimagetogglebutton.h"

QGroupImageToggleButton::QGroupImageToggleButton(QWidget *parent)
    : QPushButton(parent),
      m_parentWidget(parent),
      m_isHide(false)
{
    m_Buttons = new QHash<QString, QPushButton *>();

    this->setCheckable(true);
    this->setLocale(QLocale(QLocale::Chinese, QLocale::Taiwan));
    this->setStyleSheet(
                "QPushButton:hover:!pressed {"
                "background-color: rgb(167, 205, 255);"
                "border-style: solid;"
                "border-width: 1px; border-color: green;"
                "}"

                "QPushButton:hover:pressed {"
                "background-color: rgb(167, 205, 255);"
                "border-style: solid;"
                "border-width: 1px; border-color: red;"
                "}"

                "QPushButton[PushDown=true]{"
                "qproperty-icon: url(://images/group_triangle_collapse.png);"
                "background-color: transparent;"
                "border-style: solid;"
                "border-width: 1px; border-color: transparent;"
                "}"

                "QPushButton[PushDown=false]{"
                "qproperty-icon: url(://images/group_triangle_extend.png);"
                "background-color: transparent;"
                "border-style: solid;"
                "border-width: 1px; border-color: transparent;"
                "}"

                "QPushButton {"
                "qproperty-icon: url(://images/group_triangle_extend.png);"
                ////"background-image: url(://images/add_element_36x36.png);"
                "background-color: transparent;"
                "border-style: solid;"
                "border-width: 1px;"
                "border-color: transparent;"
                "padding-left: 2px;"
                "text-align: left;"
                "padding-right: 20px;"
                "background-position: center left;"
                "background-repeat: no-repeat;"
                "background-origin: content;"
                "}"
                );

    connect(this, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}

QGroupImageToggleButton::~QGroupImageToggleButton()
{
    if(m_Buttons) delete m_Buttons;
}

void QGroupImageToggleButton::buttonClicked()
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
}

void QGroupImageToggleButton::addButton(QPushButton *button)
{
    m_Buttons->insert(button->objectName(), button);
}

void QGroupImageToggleButton::hideGroup(bool value)
{
    QHashIterator<QString, QPushButton *> i(*m_Buttons);
    if(value){
        while (i.hasNext()) {
            i.next();
            i.value()->hide();
        }
        m_isHide = true;
    }else{
        while (i.hasNext()) {
            i.next();
            i.value()->setVisible(true);
        }
        m_isHide = false;
    }
}

bool QGroupImageToggleButton::isGroupHidden()
{
    return m_isHide;
}
