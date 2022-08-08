#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {

	while (1) {
		string str;
		
		getline(cin,str); // ������� �Է¹ޱ� ����
		if (str == ".") { // '.'�� ������ ������ ���� (while �������� �ǵ��ư�)
			break;
		}

		stack<char>ch;
		bool error = 0;

		for (int i = 0; i < str.length(); i++) {

			if (str[i] == '(') {

				ch.push('(');
			}
			else if (str[i] == ')') {

				if (!ch.empty() && ch.top() == '(') {
					ch.pop();
				}
				else { error = 1;	break; }
			}

			else if (str[i] == '[') {

				ch.push('[');
			}

			else if (str[i] == ']') {

				if (!ch.empty() && ch.top() == '[') {
					ch.pop();
				}
				else { error = 1; break; }

			}

		}

		if (error == 0 && ch.empty()) {
			cout << "yes" << endl;;
		}
		else { cout << "no" << endl; }
	}
}