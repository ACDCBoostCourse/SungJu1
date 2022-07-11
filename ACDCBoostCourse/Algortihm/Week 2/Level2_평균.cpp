#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int numberOfTest;

int highestScore;

float sum;

float testScore[1001];

int main()
{
	
	cin >> numberOfTest;
	

	
	for (int i = 0; i < numberOfTest; i++) {
		
		cin >> testScore[i];
	}
	
	sort(testScore, testScore + numberOfTest, greater<>()); //내림차순 배열 함수

	
	highestScore = testScore[0]; //가장 높은점수

	for (int i = 0; i < numberOfTest; i++) {

		sum += (testScore[i]/highestScore)*100;
	}

	cout << sum / numberOfTest;

	
}
