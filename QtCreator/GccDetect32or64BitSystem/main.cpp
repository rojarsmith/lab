#include <iostream>

using namespace std;

#if __x86_64__
#define ENV64BIT
#else
#define ENV32BIT
#endif

int main() {
#ifdef ENV64BIT
  cout << "64 bit" << endl;
#endif

#ifdef ENV32BIT
  cout << "32 bit" << endl;
#endif
  return 0;
}
