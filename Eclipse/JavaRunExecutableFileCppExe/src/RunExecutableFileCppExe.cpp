#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc >= 3) {
		try {
			double i = 3 / 0;  // do crach deliberately
		} catch (const char* message) {
			std::cout << message << std::endl;
		}
	} else if (argc == 2) {
		try {
			throw "something wrong...";
		} catch (const char* message) {
			std::cout << message << std::endl;
			return 1;
		}
	} else {
		cout << "Hello World" << endl; // prints !!!Hello World!!!
	}

	return 0;
}
