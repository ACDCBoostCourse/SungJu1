#include <iostream>
using namespace std;

int main() {

	int arr[2][3] = { {1,2,3},{4,5,6} };

	for (int(*row)[3] = arr; row < arr + 2; row++) { // "(*row)[3]" �� �Ѱ��� �྿ ����Ű�� ������
		for (int* col = *row; col < *row + 3; col++) { // "*col" �� �Ѱ��� ���� ����Ű�� ������
			cout << *col;
		}
		cout << "\n";
	}
}