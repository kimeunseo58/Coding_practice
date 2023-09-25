#include<iostream>
using namespace std;

char table[5][5];
int alphabet[26] = { 0, };
string message, key;
char s[25];

string changeAlpha(char a, char b) {
	int xA, yA, xB, yB;
	string temp = "";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (a == table[i][j]) {
				yA = i;
				xA = j;
			}
			if (b == table[i][j]) {
				yB = i;
				xB = j;
			}
		}
	}
	if (yA == yB) {
		if (xA == 4) temp += table[yA][0];
		else temp += table[yA][xA + 1];
		if (xB == 4) temp += table[yB][0];
		else temp += table[yB][xB + 1];
	}
	else if (xA == xB) {
		if (yA == 4) temp += table[0][xA];
		else temp += table[yA + 1][xA];
		if (yB == 4) temp += table[0][xB];
		else temp += table[yB + 1][xB];
	}
	else {
		temp += table[yA][xB];
		temp += table[yB][xA];
	}
	//cout << a << b << " " << xA << xB << yA << yB;
	return temp;
}

int main(int argc, char** argv)
{
	cin >> message >> key;
	int counter = 0;
	for (int i = 0; i < key.length(); i++) {
		int a = key[i] - 65;
		if (alphabet[a] == 0) {
			alphabet[a] = 1;
			s[counter] = key[i];
			counter++;
		}
	}
	alphabet[9] = 1; // J 예외 처리
	for (int i = 0; i < 26; i++) {
		int alpha = i + 65; //해당 알파벳의 아스키값.
		if (alphabet[i] == 0) {
			s[counter] = char(alpha);
			counter++;
		}
	}
	counter = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			table[i][j] = s[counter];
			counter++;
		}
	}
	for (int i = 0; i < message.length(); i += 2) {
		string temp = "";
		char t[2];
		if ((i + 1 == message.length()) || (message[i] == message[i + 1])) {
			t[0] = message[i];
			if (message[i] == 'X' && i + 1 != message.length()) t[1] = 'Q';
			else t[1] = 'X';
			temp = changeAlpha(t[0], t[1]);
			i--;
		}
		else temp = changeAlpha(message[i], message[i + 1]);
		cout << temp;
	}
	return 0;
}
