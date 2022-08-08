#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef string transactionName_t; // string���� ������ ���´�
typedef int won_t; // won_t�� int��� �̿��� �� �ִ�.
typedef string name_t; // ù���� ����Ӹ��ƴ϶� name_t�ε� string�� ��ü�� �� �ִ�.
// typedef �� �̿��� �������̼� �۾��� �� �� �������� ���� �� �ִ�

struct Transaction { //����ü ���� �� ����

	transactionName_t transactionName;
	won_t depositAndWithdrawal;
	//����ü�� ����� �����Ѵ�.
};

enum DayOfTheWeek {
	Monday = 0, //���ٺ��� 1�� �����ϸ鼭 �ʱ�ȭ
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

class BankAccount {

private : //�ܺο��� �����ϰų� �ҷ��� �� ���� ����(class �������� �ٷ� �� �ִ�,)
	name_t clientName;
	int password;
	int accountID;
	won_t accountBalance;
	DayOfTheWeek termDepositDay;
	Transaction transactionList[2]; // ����ü ���� ����

public: //class�� attributes

	BankAccount() : clientName("������"), password(1234), accountID(rand() % 10000), accountBalance(0), termDepositDay(Monday) { // �⺻������
		transactionList[0] = { .transactionName = "�ŷ� ����", .depositAndWithdrawal = 0 };
		transactionList[1] = { .transactionName = "�ŷ� ����", .depositAndWithdrawal = 0 };
		cout << clientName << "���� ���°� �����Ǿ����ϴ�. Account ID: " << accountID << endl;
	}
	//�⺻�����ڴ� main �Լ����� class�� ȣ��ɶ� ����Ǿ�� �ϴ� �ൿ��� ����Ǵ� ������ ��Ƴ�����!!

	BankAccount(name_t clientName, int password, DayOfTheWeek termDepositDay) :
		clientName(clientName), password(password), accountID(rand() % 10000), accountBalance(0), termDepositDay(termDepositDay) 
	{
		transactionList[0] = { .transactionName = "�ŷ� ����", .depositAndWithdrawal = 0 };
		transactionList[1] = { .transactionName = "�ŷ� ����", .depositAndWithdrawal = 0 };
		cout << clientName << "���� ���°� �����Ǿ����ϴ�. Account ID: ";
		printf("%04d\n", accountID);
	}
	//���ϴ� ����� class ���ο��� ���� Ʋ�� ���¸� ���鶧

	~BankAccount() {
		cout << clientName << "���� ���°� �����Ǿ����ϴ�. Account ID: ";
		printf("%04d\n", accountID);
		
		// main �Լ����� �������� �Ҵ�� �޸𸮰� ������ �� ������ �ൿ�� �ʿ��ϸ� �Ҹ��ڿ� ������´�!!
	}

	// Metods (Ŭ���� ���ο��� �����ϴ� �Լ����̸� ����ü������ ������ �� ����.)
	// ĸ��ȭ�� class���� ������ ������������ ����ϰų� �پ��� ����� �����ϱ� ���� �����Ѵ�.
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
		this->termDepositDay = termDepositDay; //this ������ ��� this =  "main�Լ������� class�� �̿��� ���� ��ü�� �ּ�"
	}                                          //class�� ��쿡�� "->"�� ���ؼ� ���� �����Ѵ�!

	void printTransactionList() {
		for (int i = 0; i < 2; i++) {
			cout << "�ŷ� �̸�: " << transactionList[i].transactionName << "  �ŷ� �ݾ�: " << transactionList[i].depositAndWithdrawal << endl;
		}
	}

	void addTransaction(name_t transactionName, won_t depositAndWithdrawal) {
		for (int i = 0; i < 2; i++) {
			if (transactionList[i].transactionName == "�ŷ� ����") {
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
	won_t mergedMoney = absorbed.getAccountBalance(); // �ڿ� �Է��� ������ �ܰ�
	absorbing.mergeAccountBalance(mergedMoney); // class ���� ������ �Լ��� �̿��� �ܰ� ��ħ. 
}


int main() {
	srand(time(NULL));
	name_t name;
	int password;
	int temp;
	DayOfTheWeek dayOfTheWeek;
	transactionName_t transactionName;
	won_t money;
	//class �������� ������ ������������ class���� ���������̹Ƿ� main�Լ������� ����Ϸ��� �ٽ� �����ؾ���!!

	// ���� ���
	cout << "�̸��� �Է����ּ���." << endl;
	cin >> name;
	cout << "��й�ȣ�� �Է����ּ���." << endl;
	cin >> password;
	cout << "���� ���� ������ ���ڷ� �Է����ּ���. \n������ - 1\nȭ���� - 2\n������ - 3\n����� - 4\n�ݿ��� - 5\n����� - 6\n�Ͽ��� - 7" << endl;
	cin >> temp;
	dayOfTheWeek = (DayOfTheWeek)(temp - 1);//�������� 0���� �����Ǿ������Ƿ� "-1"�� �ʿ���

	BankAccount A(name, password, dayOfTheWeek); 
	
	//������ ���� ������ ���� A�� ���¸� ����� �ٽ� ������ �޾� �������� �ʱ�ȭ ��Ų��.

	cout << "�̸��� �Է����ּ���." << endl;
	cin >> name;
	cout << "��й�ȣ�� �Է����ּ���." << endl;
	cin >> password;
	cout << "���� ���� ������ ���ڷ� �Է����ּ���. \n������ - 1\nȭ���� - 2\n������ - 3\n����� - 4\n�ݿ��� - 5\n����� - 6\n�Ͽ��� - 7" << endl;
	cin >> temp;
	dayOfTheWeek = (DayOfTheWeek)(temp - 1);

	BankAccount B(name, password, dayOfTheWeek);

	// ���ݾ� ����
	cout << "�ŷ� �̸��� ������ �ݾ��� �Է����ּ���." << endl;
	cout << "�ŷ� �̸�: ";
	cin >> transactionName;
	cout << "������ �ݾ�: ";
	cin >> money;

	A.addTransaction(transactionName, money);
	cout << "���� �ܾ�: " << A.getAccountBalance() << endl;
	A.printTransactionList();

	//���µ�϶��� �����ϰ� A�� �������� ������ ������ �ٽ� ������ �޾Ƽ� B�� ���� ������ �����Ѵ�. (C���� ���������� ���������� �۵��ϱ⶧����)

	cout << "�ŷ� �̸��� ������ �ݾ��� �Է����ּ���." << endl;
	cout << "�ŷ� �̸�: ";
	cin >> transactionName;
	cout << "������ �ݾ�: ";
	cin >> money;

	B.addTransaction(transactionName, money);
	cout << "���� �ܾ�: " << B.getAccountBalance() << endl;
	B.printTransactionList();

	// A���¿��� ���� ����
	cout << "�ٲ� ������ �Է����ּ���. \n������ - 1\nȭ���� - 2\n������ - 3\n����� - 4\n�ݿ��� - 5\n����� - 6\n�Ͽ��� - 7" << endl;
	cin >> temp;
	cout << "�ٲٱ� �� ���� : " << A.getDayOfTheWeek() << endl;
	dayOfTheWeek = (DayOfTheWeek)(temp - 1);
	A.setDayOfTheWeek(dayOfTheWeek);
	cout << "�ٲ� �� ���� : " << A.getDayOfTheWeek() << endl;

	// B���¿��� ���

	cout << "�ŷ� �̸��� ����� �ݾ� (������ �Է�) �� �Է����ּ���." << endl;
	cout << "�ŷ� �̸�: ";
	cin >> transactionName;
	cout << "����� �ݾ�: ";
	cin >> money;

	B.addTransaction(transactionName, money);
	cout << "���� �ݾ� : " << B.getAccountBalance() << endl;
	B.printTransactionList();

	// ���� ��ġ��
	mergeAccount(A, B);
	

	cout << "��ģ ���� �̸�: " << A.getName() << endl;
	cout << "��ģ ���� �ܰ�: " << A.getAccountBalance() << endl;
	cout << "��ģ ���� ID: " << A.getAccountID() << endl;
	cout << "��ģ ���� ��й�ȣ: " << A.getPassword() << endl;
	A.printTransactionList();
	cout << A.getDayOfTheWeek() << endl;

	return 0;

}


