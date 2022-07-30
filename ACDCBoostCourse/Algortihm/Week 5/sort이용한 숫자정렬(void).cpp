#include <iostream>
#include <algorithm>
#include <stdbool.h>

using namespace std;
void organize(int* arr[4], char a);

int main() {
	int one = 1;
	int two = 2;
	int three = 3;
	int five = 5;
	int* items[4] = {&one,&five,&three,&two };
	
	organize(items, true);

	for (int* item : items) {
		cout << *item << ' ';  // 1 2 3 5
	}

	cout << endl;
	
	organize(items, false);

	for (int* item : items) {
		cout << *item << ' ';  // 5 3 2 1
	}
}

void organize(int* arr[4], char a) {

	if (a == true) {
		sort(arr,  arr+4, greater<>());
	}
	else {
		sort(arr, arr + 4);
	}
}