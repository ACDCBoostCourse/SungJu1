#include <iostream>
#include <string>

using namespace std;

int testCase = 0; // 'O', 'X' ����

char ox[999];

int sum, i;

int c = 1;

int main() {

    cin >> testCase;

    for (i = 0; i < testCase; i++) { // 'O' �� 'X'�� ���ڿ��� ����

        cin >> ox[i];

    }

    for (i = 0; i < testCase; i++) {


        if (ox[i] == 'O')
        {

            sum += c++; // c �� �ڿ� ++ �������Ƿ� 1�� ����Ŀ��

        }

        else
        {

            c = 1; // X �� ������ c �� 1�� �ʱ�ȭ

        }

    }

    cout << sum;

}