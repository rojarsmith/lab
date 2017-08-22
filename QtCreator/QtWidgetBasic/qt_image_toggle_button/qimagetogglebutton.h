#ifndef QIMAGETOGGLEBUTTON_H
#define QIMAGETOGGLEBUTTON_H

#include <QtWidgets>

class QImageToggleButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QImageToggleButton(QWidget *parent = 0);
    QWidget *m_parentWidget;
public slots:
    void buttonClicked();
private :
    QStyle *m_Style;
    QPixmap *m_Pixmap;
};

#endif // QIMAGETOGGLEBUTTON_H
