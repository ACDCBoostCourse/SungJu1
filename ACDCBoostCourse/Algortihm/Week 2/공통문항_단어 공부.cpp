#include <iostream>
#include <string>

using namespace std;

int main() {

	string input;
	int size; // ���ڿ��� ����
	int alphabetCount[26] = {};
	int max = 0;
	int maxIndex = 0;

	int count = 0;
	cin >> input;
	size = input.length(); // ���� ���̸� ������ ����

	for (int i = 0; i < size; i++) {
		if (input[i] < 'a') // �빮�� �϶�
			alphabetCount[input[i] - 'A']++; // �빮��
		else
			alphabetCount[input[i] - 'a']++; // �ҹ���
	}// ���ĺ� ���� Ȯ��

	for (int i = 0; i < 26; i++) {
		if (max < alphabetCount[i]) {
			max = alphabetCount[i];
			maxIndex = i;
		}
	}// ���� ���� ���ĺ��� �빮�� (�ƽ�Ű�ڵ� ��ȣ-65)ã��
	
	for (int i = 0; i < 26; i++) {
		if (max == alphabetCount[i]) count++;
	}// ���� ������ ���ĺ��� �ִ��� Ȯ��

	if (count > 1) cout << "?";
	else cout << (char)(maxIndex + 65); // �빮�ڷ� ��� (+97�� �ٲٸ� �ҹ��� ���)

}