#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int a = 10;
	int* ptr;
	ptr = &a;

	int** ptr_ptr;
	ptr_ptr = &ptr;

	cout <<"a의 값 : " << a << endl;
	cout <<"a의 주소값 : " << &a << endl;

	cout <<"ptr의 값 : " << ptr << endl;
	cout <<"ptr의 주소값 : " << &ptr << endl;
	cout << "ptr_ptr의 더블포인터 : " << **ptr_ptr << endl;

}