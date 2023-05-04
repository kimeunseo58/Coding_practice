#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, m; 
string s[102];
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int check[101][101] = { 0, };
void checking() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
				if (s[xx][yy] - '0' == 1 && check[xx][yy] == 0) {
					check[xx][yy] = check[x][y] + 1;
					q.push({ xx, yy });
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	q.push({ 0,0 });
	checking();
	cout << check[n - 1][m - 1] + 1;
}
