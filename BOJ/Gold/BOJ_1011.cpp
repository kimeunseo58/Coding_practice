#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main() {
	int t, x, y;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		int answer = 1;
		int distance = y - x;
		int maxD = sqrt(distance);
		int counter = (distance - (maxD * maxD)) / maxD;
		answer = maxD * 2 + counter;
		if (distance % maxD == 0) answer -= 1;

		cout << answer << '\n';
	}
}
