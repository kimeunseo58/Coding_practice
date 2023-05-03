#include<iostream>
#include<algorithm>
#include<queue>
#include <tuple>
using namespace std;
int tomato[101][101][101];
queue<tuple<int, int, int>> QueueForBFS;
int n, m, h;
int answer = 0;
int dx[6] = { 0,0,0,1,0,-1 };
int dy[6] = { 0,0, 1,0,-1,0 };
int dz[6] = { 1,-1,0,0,0,0 };
void tomatoDate() {
	while (!QueueForBFS.empty()) {
		int x = get<0>(QueueForBFS.front());
		int y = get<1>(QueueForBFS.front());
		int z = get<2>(QueueForBFS.front());
		QueueForBFS.pop();
		for (int i = 0; i < 6; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			int zz = z + dz[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < m && zz >=0 && zz < h) {
				if (tomato[xx][yy][zz] == 0) {
					tomato[xx][yy][zz] = tomato[x][y][z] + 1;
					QueueForBFS.push({ xx,yy,zz });
				}
			}
		}
	}

}
int main() {
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1)QueueForBFS.push({ i, j, k });
			}
		}
	}
	
	if (QueueForBFS.empty()) {
		cout << -1;
		return 0;
	}
	else {
		tomatoDate();
	}
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tomato[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
				if (tomato[i][j][k] > answer) answer = tomato[i][j][k];
			}
		}
	}
	cout << answer - 1;

	return 0;
}
   
