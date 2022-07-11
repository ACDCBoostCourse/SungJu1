#include <iostream>
#include <string>

using namespace std;

int main() {

	string input;
	int size; // 문자열의 길이
	int alphabetCount[26] = {};
	int max = 0;
	int maxIndex = 0;

	int count = 0;
	cin >> input;
	size = input.length(); // 문장 길이를 변수에 저장

	for (int i = 0; i < size; i++) {
		if (input[i] < 'a') // 대문자 일때
			alphabetCount[input[i] - 'A']++; // 대문자
		else
			alphabetCount[input[i] - 'a']++; // 소문자
	}// 알파벳 갯수 확인

	for (int i = 0; i < 26; i++) {
		if (max < alphabetCount[i]) {
			max = alphabetCount[i];
			maxIndex = i;
		}
	}// 가장 많은 알파벳의 대문자 (아스키코드 번호-65)찾기
	
	for (int i = 0; i < 26; i++) {
		if (max == alphabetCount[i]) count++;
	}// 같은 갯수의 알파벳이 있는지 확인

	if (count > 1) cout << "?";
	else cout << (char)(maxIndex + 65); // 대문자로 출력 (+97로 바꾸면 소문자 출력)

}