#include <iostream>
#include <algorithm>
using namespace std;
struct lecture {
	int s;
	int f;
};
bool compare(lecture& a, lecture& b) {
	if (a.f == b.f)return a.s < b.s;
	else return a.f < b.f;
}
int main(int argc, char** argv) {
	int n;
	lecture arr[1000001];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i].s >> arr[i].f;
	sort(arr, arr + n, compare);
	int res = 1;
	int end = arr[0].f;
	for (int i = 1; i < n; i++) {
		if (arr[i].s >= end) {
			end = arr[i].f;
			res++;
		}
	}
	cout << res;
	return 0;
}
