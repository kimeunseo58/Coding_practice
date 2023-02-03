#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int arr[51][51];
bool check[51][51];
int dx[4] = { 0, 0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int checking(int x,int y) {
	queue<int> qx;
	queue<int> qy;
	int count = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (check[i][j] == true || arr[i][j] == 0) continue;
			else {
				count++;
				check[i][j] = true;
				qx.push(i);
				qy.push(j);
				while (!qx.empty() && !qy.empty()) {
					int xx = qx.front();
					int yy = qy.front();
					qx.pop();
					qy.pop();
					for (int k = 0; k < 4; k++) {
						if (xx + dx[k] >= 0 && yy + dy[k] >= 0 && xx + dx[k] < x && yy + dy[k] < y) {
							if (check[xx + dx[k]][yy + dy[k]] == false && arr[xx + dx[k]][yy + dy[k]] == 1) {
								qx.push(xx + dx[k]);
								qy.push(yy + dy[k]);
								check[xx + dx[k]][yy + dy[k]] = true;
							}

						}
					}
				}
			}
		}
	}
	return count;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n, k;
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				arr[i][j] = 0;
				check[i][j] = false;
			}
		}
		//arr[51][51] = { 0, };
	//	check[51][51] = { false, };
		cin >> m >> n >> k;
		for (int i = 1; i <= k; i++) {
			int a, b;
			cin >> a >> b;
			arr[b][a] = 1;
		}
		cout << checking(n, m) << '\n';
	}
}
