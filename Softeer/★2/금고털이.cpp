#include <iostream>
#include <algorithm>
using namespace std;
struct jewel {
	int weight;
	int value;
};
bool compare(jewel& a, jewel& b) {
	if (a.value == b.value) return a.weight < b.weight;
	else return a.value > b.value;
}
int main(int argc, char** argv) {
	int w, n;
	jewel arr[1000001];
	cin >> w >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i].weight >> arr[i].value;
	sort(arr, arr + n, compare);
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].weight > w) {
			res += w * arr[i].value;
			break;
		}
		else {
			res += arr[i].value * arr[i].weight;
			w -= arr[i].weight;
		}
	}
	cout << res;
	return 0;
}
