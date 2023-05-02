#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	string alphabet;
	cin >> alphabet;
	int answer = 0;
	for (int i = 0; i < alphabet.length(); i++) {
		if (alphabet[i] == 'c' && (alphabet[i + 1] == '=' || alphabet[i + 1] == '-') && (i + 1) < alphabet.length()) {
			answer++;
			i++;
			continue;
		}
		else if (alphabet[i] == 'd' && alphabet[i + 1] == 'z' && alphabet[i + 2] == '=' && (i + 2) < alphabet.length()) {
			answer++;
			i += 2;
			continue;
		}
		else if (alphabet[i] == 'd' && alphabet[i + 1] == '-' && (i + 1) < alphabet.length()) {
			answer++;
			i++;
			continue;
		}
		else if (alphabet[i] == 'l' && alphabet[i + 1] == 'j' && (i + 1) < alphabet.length()) {
			answer++;
			i++;
			continue;
		}
		else if (alphabet[i] == 'n' && alphabet[i + 1] == 'j' && (i + 1) < alphabet.length()) {
			answer++;
			i++;
			continue;
		}
		else if (alphabet[i] == 's' && alphabet[i + 1] == '=' && (i + 1) < alphabet.length()) {
			answer++;
			i++;
			continue;
		}
		else if (alphabet[i] == 'z' && alphabet[i + 1] == '=' && (i + 1) < alphabet.length()) {
			answer++;
			i++;
			continue;
		}
		else answer++;
	}
	cout << answer;
}
