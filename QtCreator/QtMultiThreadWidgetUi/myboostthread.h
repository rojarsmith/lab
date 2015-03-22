#ifndef MYBOOSTTHREAD
#define MYBOOSTTHREAD

//#include "boost/system/error_code.hpp"
#include "boost/thread.hpp"

//using namespace boost;

class MyBoostThread {
public:
  MyBoostThread();
  //~BoostThread();
  //bool stop;
  void run();
  void(*changeNumber)(int var1);
  //void changeNumber(int);

private:
  void runLogic();
  //boost::thread *_thread;
};

#endif // MYBOOSTTHREAD
