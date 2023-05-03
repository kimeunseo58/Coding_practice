#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int tomato[1001][1001];
queue<pair<int, int>> QueueForBFS;
int n, m;
int answer = 0;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0 };
void tomatoDate() {
	while (!QueueForBFS.empty()) {
		int x = QueueForBFS.front().first;
		int y = QueueForBFS.front().second;
		QueueForBFS.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m) {
				if (tomato[xx][yy] == 0) {
					tomato[xx][yy] = tomato[x][y] + 1;
					QueueForBFS.push({ xx,yy });
				}
			}
		}
	}
	
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1)QueueForBFS.push({ i, j });
		}
	}
	if (QueueForBFS.empty()) {
		cout << -1; 
		return 0;
	}
	else {
		tomatoDate();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) { 
				cout << -1; 
				return 0; 
			}
			if (tomato[i][j] > answer) answer = tomato[i][j];
		}
	}
	cout << answer - 1;
	return 0;
}
