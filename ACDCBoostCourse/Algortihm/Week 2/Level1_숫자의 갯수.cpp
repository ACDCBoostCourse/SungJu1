#include <iostream>

using namespace std;

int firstNum, secondNum, thirdNum, result;

int numberCount[10] = {0};

int main() {

	cin >> firstNum;
	cin >> secondNum;
	cin >> thirdNum;

	result = firstNum*secondNum*thirdNum;
	cout << result<<endl;
	while (result != 0) {
		numberCount[result % 10] +=1; // 곱한수를 10으로 나눴을때 나머지 찾기
		result = result / 10;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << numberCount[i] << endl;
	}

	
}