#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int arr[11][11];
		int num = 1;
		int x = 0, y = -1;
		int flag = 1;
		cin >> n;
		int temp = n;
		while (n > 0) {
			for (int i = 0; i < n; i++) {
				y += flag;
				arr[x][y] = num;
				num++;
			}
			n--;
			for (int j = 0; j < n; j++) {
				x += flag;
				arr[x][y] = num;
				num++;
			}
			flag *= -1;
		}

		cout << "#" << test << '\n';
		for (int i = 0; i < temp; i++) {
			for (int j = 0; j < temp; j++) {
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}
	}
	return 0;
}