#include <iostream>
#include <string>

using namespace std;

int main() {

	char a[3][10] = { "Hello","World","Doodle" };
	char* p_str[3]; // ������ �迭

	for (int i = 0; i < 3; i++) {
		p_str[i] = a[i]; // �� �� 1���� �ּҰ��� �����
	}

	for (int i = 0; i < 3; i++) {
		cout << p_str[i] << endl; // ���� �ּҰ����� ���̰��� ���ö����� ���ڿ��� ��� ���
	}
}