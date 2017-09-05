#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include <QHash>
#include <QObject>
#include <QString>

class ObjectFactory
{
public:
    ObjectFactory() = delete;

    template<typename T>
    static void registerClass()
    {
        constructors().insert(T::staticMetaObject.className(), &constructorHelper<T>);
    }

    static QObject *createObject(const QString className, QObject *parent=Q_NULLPTR)
    {
        Constructor constructor = constructors().value(className);
        if(constructor == Q_NULLPTR)
            return Q_NULLPTR;
        return (*constructor)(parent);
    }

private:
    typedef QObject *(*Constructor)(QObject *parent);

    template <typename T>
    static QObject *constructorHelper(QObject *parent)
    {
        return new T(parent);
    }

    static QHash<QString, Constructor> &constructors()
    {
        static QHash<QString, Constructor> instance;
        return instance;
    }
};

#endif // OBJECTFACTORY_H
