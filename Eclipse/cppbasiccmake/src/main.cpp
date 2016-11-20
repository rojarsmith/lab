#define DBG(msg, arg...) printf("%s:%s(%d): " msg, __FILE__, __FUNCTION__, __LINE__, ##arg)

#include <iostream>

using namespace std;

int main() {
	int sum = 0;
	for (int i = 0; i < 100; ++i) {
		sum += i;
	}
	cout << "Hello CMake!" << endl << "Sum is " << sum << endl;

	DBG("index:%d str = %s\n", 123, "aaa");
	printf("%s:%s(%d): "    "index:%d str = %s\n", __FILE__, __FUNCTION__,
			__LINE__, 123, "aaa");
}
