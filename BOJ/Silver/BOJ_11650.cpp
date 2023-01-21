#include<iostream>
#include<algorithm>
using namespace std;

struct point {
	int x = 0;
	int y = 0;
};
bool compare(const point &a, const point &b) {
	if (a.x < b.x) {
		return true;
	}
	else if (a.x == b.x) {
		return a.y < b.y;
	}
	else {
		return false;
	}
}
int main() {
	point arr[100001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr, arr + n,compare);
	for (int i = 0; i < n; i++) {
		cout << arr[i].x << " " << arr[i].y << '\n';
	}
}