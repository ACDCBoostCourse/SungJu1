#include <iostream>
using namespace std;

void get_sequence_number(double a);//0번째 항부터 99번째항까지 구하는 함수

int main() {
   cout << fixed;//소수점 고정
   cout.precision(50);//가장 큰 자릿수부터 50자리를 출력
   get_sequence_number(10);

}

void get_sequence_number(double a) {
    

    for (int i = 0; i < 100; i++) {
        a /= 2;
    }
    cout << a;
   
}
