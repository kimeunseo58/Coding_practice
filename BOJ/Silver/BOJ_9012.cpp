#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		stack<int> stack;
		string a;
		bool flag = true;
		cin >> a;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] == '(') stack.push(1);
			else if (a[i] == ')') {
				if (stack.empty()) {
					flag = false;
					break;
				}
				else stack.pop();
			}
		}
		if (stack.empty() && flag == true) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
	return 0;
}