#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int n, m, r;
int visited[100001] = { 0, };
vector<int> v[100001];
int res[100001] = { 0, };
int counter = 0;
void dfs(int x) {
	visited[x] = 1;
	counter++;
	res[x] = counter;
	for (int i = 0; i < v[x].size(); i++) {
		if (visited[v[x][i]] == 0) dfs(v[x][i]);
	}
}

int main(int argc, char** argv) {
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
	dfs(r);
	for (int i = 1; i <= n; i++) cout << res[i] << '\n';

	return 0;
}
