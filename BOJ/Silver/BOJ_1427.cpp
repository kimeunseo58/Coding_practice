#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
	string a;
	int arr[11];
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		arr[i] = a[i] - '0';
	}
	sort(arr, arr + a.length());
	for (int i = a.length() - 1; i >= 0; i--) {
		cout << arr[i];
	}
}