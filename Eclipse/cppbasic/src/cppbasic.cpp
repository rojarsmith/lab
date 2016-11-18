//============================================================================
// Name        : cppbasic.cpp
// Author      : Rojar Smith
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bitset>

using namespace std;

void func2(){
	int a[] = {0,1,2,3,4};
	int* p;
	p = &a[0];
	cout<<*(p++)<<endl;
	p = &a[0];
	p++;
	cout<<*p<<endl;
	p = &a[0];
	cout<<*p++<<endl;
	p = &a[0];
	cout<<(*p)++<<endl;
	p = &a[0];
	cout<<*(++p)<<endl;
}

void func1() {
	bitset<32> a(100);
	cout << a << endl;
	double t = 15.9375;
	char* low = (char*) &t;
	char* high = (char*) (&t + 1) - 1;
	char * cp = high;

	while (cp >= low) {
		bitset<8> bs(*cp);
		cout << bs << " ";
		cp--;
	}
}

int main() {
	func2();
	//func1();
	return 0;
}

