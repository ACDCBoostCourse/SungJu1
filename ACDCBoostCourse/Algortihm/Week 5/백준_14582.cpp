#include <iostream>

using namespace std;
int firstScore[9] = { 0, };
int finalScore[9] = { 0, };
int totalScore_1 = 0;
int totalScore_2 = 0;
int cnt = 0;

int main() {
	for (int i = 0; i < 9; i++) { // ù��° �� ���ھ�(������)

		cin >> firstScore[i];
	}
	for (int i = 0; i < 9; i++) { // �ι�° �� ���ھ�

		cin >> finalScore[i];
	}

	for (int i = 0; i < 9; i++) {

		totalScore_1 += firstScore[i];
		

		if (totalScore_1 > totalScore_2) {
			cnt++;
		}
		totalScore_2 += finalScore[i];
	}

	if (cnt > 0) {
		if (totalScore_1 < totalScore_2) {
			cout << "Yes" << endl;
		}
		else { cout << "No" << endl; }
	}
	else {
		cout << "No" << endl;
	}
}