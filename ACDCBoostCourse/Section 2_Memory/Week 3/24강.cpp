#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int a = 10;
	int* ptr;
	ptr = &a;

	int** ptr_ptr;
	ptr_ptr = &ptr;

	cout <<"a�� �� : " << a << endl;
	cout <<"a�� �ּҰ� : " << &a << endl;

	cout <<"ptr�� �� : " << ptr << endl;
	cout <<"ptr�� �ּҰ� : " << &ptr << endl;
	cout << "ptr_ptr�� ���������� : " << **ptr_ptr << endl;

}