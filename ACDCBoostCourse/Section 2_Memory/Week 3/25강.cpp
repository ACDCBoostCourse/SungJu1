#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	for (int i = 0; i < 10; i++){
		cout << arr[i];
	}
	cout << "\n";
	for (int i = 0; i < 10; i++) {
		cout << *(arr + i) ;
	}
	cout << "\n";
	for (int *ptr=arr; ptr < arr+10; ptr++) {
		cout << *ptr ;
	}
}