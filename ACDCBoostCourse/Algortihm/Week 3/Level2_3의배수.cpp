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
            
            sum += n[i] - '0'; // 문자열을 상수로 취급하기 위해 " -'0' " 을 붙여준다.
            

        }

        cnt++;

        stringSum = to_string(sum); // 상수 sum 을 문자열로 변환

        solve(stringSum);
    }
}

int main() {
    string x;
  
    cin >> x;  

    solve(x);
    
    return 0; 
 
}