#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int arr[26][26];
int check[26][26] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<int> ans;
int n;
int bfs(int a, int b) {
	queue<pair<int, int>> q;
	check[a][b] = 1; //방문 처리 해주기!!
	int num = 1; //시작 지점까지 포함하여 1개로 시작
	q.push({ a,b });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < n && yy >= 0 && yy < n) {
				if (check[xx][yy] == 0 && arr[xx][yy] == 1) {
					q.push({ xx,yy });
					check[xx][yy] = 1;
					num++;
				}
			}
		}
	}
	return num;
}
int main(int argc, char** argv) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 0 && arr[i][j] == 1) {
				ans.push_back(bfs(i, j));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
	return 0;
}
