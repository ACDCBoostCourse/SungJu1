#include <iostream>
using namespace std;

void get_sequence_number(double a);//0��° �׺��� 99��°�ױ��� ���ϴ� �Լ�

int main() {
   cout << fixed;//�Ҽ��� ����
   cout.precision(50);//���� ū �ڸ������� 50�ڸ��� ���
   get_sequence_number(10);

}

void get_sequence_number(double a) {
    

    for (int i = 0; i < 100; i++) {
        a /= 2;
    }
    cout << a;
   
}
