#include <iostream>
using namespace std;

int main() {

	int arr[2][3] = { {1,2,3},{4,5,6} };

	for (int(*row)[3] = arr; row < arr + 2; row++) { // "(*row)[3]" 은 한개의 행씩 가르키는 포인터
		for (int* col = *row; col < *row + 3; col++) { // "*col" 은 한개의 열씩 가르키는 포인터
			cout << *col;
		}
		cout << "\n";
	}
}