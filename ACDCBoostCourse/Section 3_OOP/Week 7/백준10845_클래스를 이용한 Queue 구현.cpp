#include <iostream>
#include <string>

using namespace std;

template <typename T>

class Queue {
private:
	T* arr;
	int q_size;
	int startCursor;
	int endCursor;

public:
	Queue() {
		q_size = 0;
		arr = new T[10000];
		startCursor = 0;
		endCursor = 0;
	}
	~Queue() {
		delete[] arr;
	}
	void push(int x) {
		arr[endCursor++] = x; //뒤에 ++를 붙여야 배열에 입력되고난 후에 1이올라감
		++q_size;
	}
	void pop() {
		if (q_size != 0) {
			cout << arr[startCursor++] << endl; //위와 동일
			--q_size;
		}
		else { cout << "-1" << endl; }
	}
	void size() {
		cout << q_size << endl;
	}
	void empty() {
		if (q_size == 0) {
			cout << "1" << endl;
		}
		else { cout << "0" << endl; }
	}
	void front() {
		if (q_size != 0) {
			cout << arr[startCursor] << endl;
		}
		else { cout << "-1" << endl; }
	}
	void back() {
		if (q_size == 0) {
			cout << "-1" << endl;
		}
		else if(q_size !=0){
			cout << arr[endCursor-1] << endl; //push 함수에 endCursor 뒤에 ++ 있으므로 1을빼줘야 마지막에 넣은 위치의 숫자가 출력됌!
		}
	}


};

int main() {
	int commandCount;
	cin >> commandCount;
	string commandString;
	Queue<double> print;
	for (int i = 0; i < commandCount; i++) {
		cin >> commandString;
		if (commandString == "push") {
			int num;//push 뒤에 공백이있으므로 공백이후엔 문자열이 끊기므로 새로운 데이터를 추가로 받아서 저장가능!
			cin >> num;
			print.push(num);
		}
		else if (commandString == "pop") {
			print.pop();
		}
		else if (commandString == "size") {
			print.size();
		}
		else if (commandString == "empty") {
			print.empty();
		}
		else if (commandString == "front") {
			print.front();
		}
		else if (commandString == "back") {
			print.back();
		}

	}

}