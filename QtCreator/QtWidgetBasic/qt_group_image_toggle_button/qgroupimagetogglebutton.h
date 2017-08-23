#ifndef QGROUPIMAGETOGGLEBUTTON_H
#define QGROUPIMAGETOGGLEBUTTON_H

#include <QtWidgets>

class QGroupImageToggleButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QGroupImageToggleButton(QWidget *parent = 0);
    ~QGroupImageToggleButton();

    void addButton(QPushButton *button);
    void hideGroup(bool value);
    bool isGroupHidden();

    QWidget *m_parentWidget;
public slots:
    void buttonClicked();
private :
    bool m_isHide;
    QHash<QString, QPushButton *> *m_Buttons;
    QStyle *m_Style;
    QPixmap *m_Pixmap;
};

#endif // QGROUPIMAGETOGGLEBUTTON_H
