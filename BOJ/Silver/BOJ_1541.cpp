#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string s;
int res = 0;
string num;
bool flag = false;
int main() {
    cin >> s;

    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == '-' || s[i] == '+' || i==s.length()) {
            if (flag) res -= stoi(num);
            else res += stoi(num);
            num = "";
        }
        else num += s[i];
        if (s[i] == '-') flag = true;
    }
    cout << res;
}
