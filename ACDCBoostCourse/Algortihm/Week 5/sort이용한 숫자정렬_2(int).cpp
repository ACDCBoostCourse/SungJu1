#include <iostream>
#include <algorithm>
#include <stdbool.h>

using namespace std;
int *sorted(int *arr[4], char a,int b) {
	if (a == true) {
		sort(arr, arr + 4, greater<>());
		int* arr_1[4] = { 0, };
		for (int i = 0; i < 4; i++) {
			arr_1[i] = arr[i];
		}

		return arr_1[b];
	}
	else { return 0; };
}
int main() {
	int one = 1;
	int two = 2;
	int three = 3;
	int five = 5;
	
	int* items[4] = { &one,&five,&three,&two };
	int* newItems[4];
	
	for (int* item : items) {
		cout << *item << ' ';  // 1 5 3 2
	}

	
	cout << endl;

	
	newItems[0] = sorted(items, true,0);
	newItems[1] = sorted(items, true,1);
	newItems[2] = sorted(items, true,2);
	newItems[3] = sorted(items, true,3);


	for (int* item  :  newItems) {
		cout << *item << ' ';  // 1 2 3 5
	}
	
}

