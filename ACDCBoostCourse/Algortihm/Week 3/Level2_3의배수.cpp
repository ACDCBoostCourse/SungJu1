#include <iostream>
#include <string>

using namespace std;
int cnt = 0;



void solve(string n) {
    int sum = 0;    
    string stringSum;

    if (n.length() == 1) {

        cout << cnt<<"\n";

        if ((n[0] - '0') % 3 == 0) {
            cout << "YES\n";
        }
    
        else {
            cout << "NO\n" << endl;
        }

        return;
    
   
    }
    else {
        for (int i = 0; i < n.length(); i++) {
            
            sum += n[i] - '0'; // ���ڿ��� ����� ����ϱ� ���� " -'0' " �� �ٿ��ش�.
            

        }

        cnt++;

        stringSum = to_string(sum); // ��� sum �� ���ڿ��� ��ȯ

        solve(stringSum);
    }
}

int main() {
    string x;
  
    cin >> x;  

    solve(x);
    
    return 0; 
 
}