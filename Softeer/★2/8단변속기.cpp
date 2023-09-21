
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
	int arr[9];
	int compArr[9];
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		compArr[i] = arr[i];
	}
	sort(arr, arr + 8, greater<>());
	for (int i = 0; i < 8; i++) {
		if (arr[i] != compArr[i]) break;
		if (i == 7 && arr[i] == compArr[i]) {
			cout << "descending";
			return 0;
		}
	}
	sort(arr, arr + 8);
	for (int i = 0; i < 8; i++) {
		if (arr[i] != compArr[i]) break;
		if (i == 7 && arr[i] == compArr[i]) {
			cout << "ascending";
			return 0;
		}
	}
	cout << "mixed";
	return 0;
}
