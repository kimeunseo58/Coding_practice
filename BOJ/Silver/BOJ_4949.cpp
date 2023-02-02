#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

int main() {
	string s;
	string answer = "yes";
	stack<char> brace;
	while (true) {
		getline(cin, s);
		if (s.length() == 1 && s == ".")break;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.') {
				if (answer == "yes") {
					if (!brace.empty())answer = "no";
				}
				cout << answer << '\n';
				while (!brace.empty()) brace.pop();
				answer = "yes";
			}

			if (s[i] == '(' || s[i] == '[') {
				brace.push(s[i]);
			}
			else if (s[i] == ')') {
				if (!brace.empty() && brace.top() == '(') brace.pop();
				else if (brace.empty() || brace.top() == '[') answer = "no";
			}
			else if (s[i] == ']') {
				if (!brace.empty() && brace.top() == '[') brace.pop();
				else if (brace.empty() || brace.top() == '(') answer = "no";
			}
		}
	}
}
