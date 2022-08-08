#include <iostream>

using namespace std;

template <typename T>
T multiply(T a, T b) {
	return a * b;
}


int main() {
	int a = 3;
	int b = 4;
	double c = 3.2;
	double d = 4.3;

	cout << multiply<int>(a, b) << endl;
	cout << multiply<double>(c, d) << endl;

	return 0;
}