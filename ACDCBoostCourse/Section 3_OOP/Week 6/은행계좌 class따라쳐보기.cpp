#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef string transactionName_t; // string형의 별명을 짓는다
typedef int won_t; // won_t를 int대신 이용할 수 있다.
typedef string name_t; // 첫줄의 별명뿐만아니라 name_t로도 string을 대체할 수 있다.
// typedef 를 이용해 여러명이서 작업을 할 때 가독성을 높일 수 있다

struct Transaction { //구조체 선언 및 정의

	transactionName_t transactionName;
	won_t depositAndWithdrawal;
	//구조체의 멤버를 정의한다.
};

enum DayOfTheWeek {
	Monday = 0, //윗줄부터 1씩 증가하면서 초기화
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

class BankAccount {

private : //외부에서 수정하거나 불러낼 수 없는 값들(class 내에서만 다룰 수 있다,)
	name_t clientName;
	int password;
	int accountID;
	won_t accountBalance;
	DayOfTheWeek termDepositDay;
	Transaction transactionList[2]; // 구조체 변수 선언

public: //class의 attributes

	BankAccount() : clientName("이의진"), password(1234), accountID(rand() % 10000), accountBalance(0), termDepositDay(Monday) { // 기본생성자
		transactionList[0] = { .transactionName = "거래 없음", .depositAndWithdrawal = 0 };
		transactionList[1] = { .transactionName = "거래 없음", .depositAndWithdrawal = 0 };
		cout << clientName << "님의 계좌가 생성되었습니다. Account ID: " << accountID << endl;
	}
	//기본생성자는 main 함수에서 class가 호출될때 수행되어야 하는 행동들과 저장되는 값들을 모아놓은것!!

	BankAccount(name_t clientName, int password, DayOfTheWeek termDepositDay) :
		clientName(clientName), password(password), accountID(rand() % 10000), accountBalance(0), termDepositDay(termDepositDay) 
	{
		transactionList[0] = { .transactionName = "거래 없음", .depositAndWithdrawal = 0 };
		transactionList[1] = { .transactionName = "거래 없음", .depositAndWithdrawal = 0 };
		cout << clientName << "님의 계좌가 생성되었습니다. Account ID: ";
		printf("%04d\n", accountID);
	}
	//원하는 값들로 class 내부에서 만들 틀의 계좌를 만들때

	~BankAccount() {
		cout << clientName << "님의 계좌가 삭제되었습니다. Account ID: ";
		printf("%04d\n", accountID);
		
		// main 함수에서 마지막에 할당된 메모리가 삭제될 때 취해질 행동이 필요하면 소멸자에 적어놓는다!!
	}

	// Metods (클래스 내부에서 수행하는 함수들이며 구조체에서는 구현할 수 없다.)
	// 캡슐화된 class내의 정보를 꺼내오기위해 사용하거나 다양한 기능을 구현하기 위해 설정한다.
	name_t getName() { 
		return clientName;
	}
	won_t getAccountBalance() {
		return accountBalance;
	}
	int getPassword() {
		return password;
	}

	string getDayOfTheWeek() {
		switch (termDepositDay) {
		case Monday :
			return "Monday";

		case Tuesday :
			return "Tuesday";

		case Wednesday :
			return "Wednesday";

		case Thursday :
			return "Thursday";

		case Friday :
			return "Friday";

		case Saturday :
			return "Saturday";

		case Sunday :
			return "Sunday";

		default :
			break;

		}
	}

	void setDayOfTheWeek(DayOfTheWeek termDepositDay) {
		this->termDepositDay = termDepositDay; //this 포인터 사용 this =  "main함수내에서 class를 이용해 만든 객체의 주소"
	}                                          //class의 경우에는 "->"를 통해서 값에 접근한다!

	void printTransactionList() {
		for (int i = 0; i < 2; i++) {
			cout << "거래 이름: " << transactionList[i].transactionName << "  거래 금액: " << transactionList[i].depositAndWithdrawal << endl;
		}
	}

	void addTransaction(name_t transactionName, won_t depositAndWithdrawal) {
		for (int i = 0; i < 2; i++) {
			if (transactionList[i].transactionName == "거래 없음") {
				transactionList[i].transactionName = transactionName;
				transactionList[i].depositAndWithdrawal = depositAndWithdrawal;
				accountBalance += depositAndWithdrawal;
				break; 
			}
		}
	}

	void mergeAccountBalance(won_t mergedMoney) {
		accountBalance += mergedMoney;
	}

	int getAccountID() {
		return accountID;
	}

	
};

void mergeAccount(BankAccount& absorbing, BankAccount& absorbed) {
	won_t mergedMoney = absorbed.getAccountBalance(); // 뒤에 입력한 계좌의 잔고
	absorbing.mergeAccountBalance(mergedMoney); // class 내에 선언한 함수를 이용해 잔고를 합침. 
}


int main() {
	srand(time(NULL));
	name_t name;
	int password;
	int temp;
	DayOfTheWeek dayOfTheWeek;
	transactionName_t transactionName;
	won_t money;
	//class 내에서도 선언한 변수들이지만 class내의 지역변수이므로 main함수에서도 사용하려면 다시 선언해야함!!

	// 계좌 등록
	cout << "이름을 입력해주세요." << endl;
	cin >> name;
	cout << "비밀번호를 입력해주세요." << endl;
	cin >> password;
	cout << "정기 예금 요일을 숫자로 입력해주세요. \n월요일 - 1\n화요일 - 2\n수요일 - 3\n목요일 - 4\n금요일 - 5\n토요일 - 6\n일요일 - 7" << endl;
	cin >> temp;
	dayOfTheWeek = (DayOfTheWeek)(temp - 1);//월요일이 0으로 설정되어있으므로 "-1"이 필요함

	BankAccount A(name, password, dayOfTheWeek); 
	
	//위에서 받은 정보를 통해 A의 계좌를 만들고 다시 정보를 받아 변수들을 초기화 시킨다.

	cout << "이름을 입력해주세요." << endl;
	cin >> name;
	cout << "비밀번호를 입력해주세요." << endl;
	cin >> password;
	cout << "정기 예금 요일을 숫자로 입력해주세요. \n월요일 - 1\n화요일 - 2\n수요일 - 3\n목요일 - 4\n금요일 - 5\n토요일 - 6\n일요일 - 7" << endl;
	cin >> temp;
	dayOfTheWeek = (DayOfTheWeek)(temp - 1);

	BankAccount B(name, password, dayOfTheWeek);

	// 예금액 설정
	cout << "거래 이름과 예금할 금액을 입력해주세요." << endl;
	cout << "거래 이름: ";
	cin >> transactionName;
	cout << "예금할 금액: ";
	cin >> money;

	A.addTransaction(transactionName, money);
	cout << "계좌 잔액: " << A.getAccountBalance() << endl;
	A.printTransactionList();

	//계좌등록때와 동일하게 A의 계좌정보 수정이 끝난후 다시 정보를 받아서 B의 계좌 정보를 수정한다. (C언어는 위에서부터 순차적으로 작동하기때문에)

	cout << "거래 이름과 예금할 금액을 입력해주세요." << endl;
	cout << "거래 이름: ";
	cin >> transactionName;
	cout << "예금할 금액: ";
	cin >> money;

	B.addTransaction(transactionName, money);
	cout << "계좌 잔액: " << B.getAccountBalance() << endl;
	B.printTransactionList();

	// A계좌에서 요일 변경
	cout << "바꿀 요일을 입력해주세요. \n월요일 - 1\n화요일 - 2\n수요일 - 3\n목요일 - 4\n금요일 - 5\n토요일 - 6\n일요일 - 7" << endl;
	cin >> temp;
	cout << "바꾸기 전 요일 : " << A.getDayOfTheWeek() << endl;
	dayOfTheWeek = (DayOfTheWeek)(temp - 1);
	A.setDayOfTheWeek(dayOfTheWeek);
	cout << "바꾼 후 요일 : " << A.getDayOfTheWeek() << endl;

	// B계좌에서 출금

	cout << "거래 이름과 출금할 금액 (음수로 입력) 을 입력해주세요." << endl;
	cout << "거래 이름: ";
	cin >> transactionName;
	cout << "출금할 금액: ";
	cin >> money;

	B.addTransaction(transactionName, money);
	cout << "남은 금액 : " << B.getAccountBalance() << endl;
	B.printTransactionList();

	// 계좌 합치기
	mergeAccount(A, B);
	

	cout << "합친 계좌 이름: " << A.getName() << endl;
	cout << "합친 계좌 잔고: " << A.getAccountBalance() << endl;
	cout << "합친 계좌 ID: " << A.getAccountID() << endl;
	cout << "합친 계좌 비밀번호: " << A.getPassword() << endl;
	A.printTransactionList();
	cout << A.getDayOfTheWeek() << endl;

	return 0;

}


