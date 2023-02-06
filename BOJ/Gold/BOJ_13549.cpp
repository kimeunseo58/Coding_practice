#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

int n, k;
int answer[100001];

int bfs() {
	deque<int> q;
	q.push_back(n);
	answer[n] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop_front();
		if (temp == k) return answer[temp];
		if (temp * 2 < 100001 && !answer[temp * 2]) {
			q.push_front(temp * 2);
			answer[temp * 2] = answer[temp];
		}
		if (temp + 1 < 100001 && !answer[temp + 1] ) {
			q.push_back(temp + 1);
			answer[temp + 1] = answer[temp] + 1;
		}
		if (temp - 1 >= 0 && !answer[temp - 1]) {
			q.push_back(temp - 1);
			answer[temp - 1] = answer[temp] + 1;
		}
	}
}
int main() {
	cin >> n >> k;
	cout << bfs() - 1;
	return 0;
}
