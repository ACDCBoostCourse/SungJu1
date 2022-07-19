#include <iostream>
#include <string>

using namespace std;

int testCase = 0; // 'O', 'X' 갯수

char ox[999];

int sum, i;

int c = 1;

int main() {

    cin >> testCase;

    for (i = 0; i < testCase; i++) { // 'O' 와 'X'를 문자열에 저장

        cin >> ox[i];

    }

    for (i = 0; i < testCase; i++) {


        if (ox[i] == 'O')
        {

            sum += c++; // c 는 뒤에 ++ 가있으므로 1씩 점점커짐

        }

        else
        {

            c = 1; // X 가 나오면 c 를 1로 초기화

        }

    }

    cout << sum;

}