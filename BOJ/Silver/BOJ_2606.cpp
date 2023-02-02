#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	int answer = 0;
	vector<int> arr[101];
	bool check[101] = {false,};
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	check[1] = true;

	while (!q.empty()) {
		int temp = q.front();
		check[temp] = true;
		q.pop();
		for (int i = 0; i < arr[temp].size(); i++) {
			if (check[arr[temp][i]] == false)q.push(arr[temp][i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == true) answer++;
	}
	cout << answer - 1;
}
