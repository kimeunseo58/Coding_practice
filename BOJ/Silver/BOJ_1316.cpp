#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, answer;
	answer = 0;
	cin >> n;
	while (n--) {
		string word;
		cin >> word;
		bool flag = true;
		for (int i = 0; i < word.length(); i++) {
			for (int j = i + 1; j < word.length(); j++) {
				if (word[j] == word[i] && word[i] != word[j-1]) flag = false;
			}
		}
		if (flag == true) answer += 1;
	}
	cout << answer;
}
