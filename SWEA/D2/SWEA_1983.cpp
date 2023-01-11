#include<iostream>
#include<algorithm>
using namespace std;
string getScore(int a, int b) {
	if (a / b == 0) return "A+";
	else if(a / b == 1) return "A0";
	else if (a / b == 2) return "A-";
	else if (a / b == 3) return "B+";
	else if (a / b == 4) return "B0";
	else if (a / b == 5) return "B-";
	else if (a / b == 6) return "C+";
	else if (a / b == 7) return "C0";
	else if (a / b == 8) return "C-";
	else if (a / b == 9) return "D0";
}
int main()
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		int k, n, temp; 
		int score[101] = {0};
		string answer;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			score[i] = a * 0.35 + b * 0.45 + c * 0.2;
			if (i == k) temp = score[i];
		}
		sort(score, score + n);
		for (int i = 1; i <= n; i++) {
			if (score[i] == temp) { 
				temp = i; 
				break;
			}
		}
		answer = getScore(temp, n / 10);
		cout << "#" << t << " " << answer;
	}

}