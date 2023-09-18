#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	deque<int> dq;
	int arr[51];
	for (int i = 0; i < m; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) dq.push_back(i);
	int res = 0;
	for (int i = 0; i < m; i++) {
		auto idx = find(dq.begin(), dq.end(), arr[i]);
		if (dq.front() == arr[i]) dq.pop_front();
		else {
			if (idx - dq.begin() > dq.size() / 2) {
				while (dq.front() != arr[i]) {
					dq.push_front(dq.back());
					dq.pop_back();
					res++;
				}
				dq.pop_front();
			}
			else {
				while (dq.front() != arr[i]) {
					dq.push_back(dq.front());
					dq.pop_front();
					res++;
				}
				dq.pop_front();
			}
		}
	}
	cout << res;
}
