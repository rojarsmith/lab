#ifndef ELEMENTABSTRACTION_H
#define ELEMENTABSTRACTION_H

#include <QObject>

class ElementAbstraction : public QObject
{
    Q_OBJECT

public:
    explicit ElementAbstraction(QObject *parent = Q_NULLPTR);

signals:

public slots:
};

#endif // ELEMENTABSTRACTION_H
