#include <iostream>

using namespace std;
int firstScore[9] = { 0, };
int finalScore[9] = { 0, };
int totalScore_1 = 0;
int totalScore_2 = 0;
int cnt = 0;

int main() {
	for (int i = 0; i < 9; i++) { // Ã¹¹øÂ° ÆÀ ½ºÄÚ¾î(ÆÒÀÎÆÀ)

		cin >> firstScore[i];
	}
	for (int i = 0; i < 9; i++) { // µÎ¹øÂ° ÆÀ ½ºÄÚ¾î

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