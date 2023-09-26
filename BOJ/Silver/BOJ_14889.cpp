#include<iostream>
#include<algorithm>
using namespace std;
int n;
int s[21][21];
int check[21] = { 0, };
int start[11];
int link[11];
int minCapcity = -1;
void tracking(int a, int idx) {
	if (idx == n / 2 + 1) {
		int x = 1;
		int y = 1;
		for (int i = 1; i <= n; i++) {
			if (check[i] == 1) {
				start[x] = i;
				x++;
			}
			else {
				link[y] = i;
				y++;
			}
		}
		int startC = 0;
		int linkC = 0;
		for (int i = 1; i < n / 2; i++) {
			for (int j = i + 1; j <= n / 2; j++) {
				startC += s[start[i]][start[j]] + s[start[j]][start[i]];
				linkC += s[link[i]][link[j]] + s[link[j]][link[i]];
			}
		}
		if (minCapcity == -1) minCapcity = abs(startC - linkC);
		else minCapcity = min(abs(startC - linkC), minCapcity);
	}
	else {
		for (int i = a ; i <= n; i++) {
			if (check[i] == 0) {
				check[i] = 1;
				tracking(i + 1, idx + 1);
				check[i] = 0;
			}
		}
	}
	
}
int main(int argc, char** argv)
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> s[i][j];
	}
	tracking(1, 1);
	cout << minCapcity;
	return 0;
}
