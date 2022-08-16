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
		arr[endCursor++] = x; //�ڿ� ++�� �ٿ��� �迭�� �Էµǰ� �Ŀ� 1�̿ö�
		++q_size;
	}
	void pop() {
		if (q_size != 0) {
			cout << arr[startCursor++] << endl; //���� ����
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
			cout << arr[endCursor-1] << endl; //push �Լ��� endCursor �ڿ� ++ �����Ƿ� 1������� �������� ���� ��ġ�� ���ڰ� ���!
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
			int num;//push �ڿ� �����������Ƿ� �������Ŀ� ���ڿ��� ����Ƿ� ���ο� �����͸� �߰��� �޾Ƽ� ���尡��!
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