#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
 
using namespace std;
 
string str;
stack<char> s;

int main() {
    cin >> str;
 
    int answer = 0;
    int temp = 1;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            temp *= 2;
            s.push('(');
        }
        else if(str[i] == '[') {
            temp *= 3;
            s.push('[');
        }
        else if(str[i] == ')') {
            if(s.empty() || s.top() != '(') {  
                cout << 0;
                return 0;
            }
            if(str[i-1] == '(') answer += temp;
            temp /= 2;
            s.pop();
        }
        else if(str[i] == ']') {
            if(s.empty() || s.top() != '[') {  
                cout << 0;
                return 0;
            }
            if(str[i-1] == '[') answer += temp;
            temp /= 3;
            s.pop();
        }
    }
    if(!s.empty()) answer = 0;
    cout << answer << '\n';
 
    return 0;
}
