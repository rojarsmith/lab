#ifndef MYBOOSTTHREAD
#define MYBOOSTTHREAD

#include <QObject>
//#include "boost/thread.hpp"

//using namespace boost;

class MyBoostThread: public QObject {
    // Q_OBJECT
public:
  MyBoostThread();
  //~BoostThread();
  //bool stop;
  void run();

  //void changeNumber(int);
  //boost::thread _thread;
protected:

public slots:
  void(__stdcall *changeNumber)(int num);
private:
  void runLogic();

};

#endif // MYBOOSTTHREAD
