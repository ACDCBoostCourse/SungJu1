#include <iostream>
#include <string>

using namespace std;

int main() {

	char a[3][10] = { "Hello","World","Doodle" };
	char* p_str[3]; // 포인터 배열

	for (int i = 0; i < 3; i++) {
		p_str[i] = a[i]; // 각 행 1열의 주소값이 저장됌
	}

	for (int i = 0; i < 3; i++) {
		cout << p_str[i] << endl; // 시작 주소값부터 더미값이 나올때까지 문자열을 모두 출력
	}
}