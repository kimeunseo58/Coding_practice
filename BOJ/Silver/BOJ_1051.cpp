#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int n, m;
	int answer = 1;
	string arr[51];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n == 1 || m == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int result = 0;
			int counter = 1;
			int iCounter = i + 1;
			int jCounter = j + 1;
			while (iCounter < n  && jCounter < m) {
				if (arr[i][j] == arr[i][jCounter] &&
					arr[i][j] == arr[iCounter][j] &&
					arr[i][j] == arr[iCounter][jCounter]) {
					result = counter;
				}
				iCounter++;
				jCounter++;
				counter++;
			}
			if (result != 0) result++;
			answer = max(answer, result);
		}
	}
	cout << answer * answer;

}
