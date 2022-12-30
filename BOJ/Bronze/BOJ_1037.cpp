#include<iostream>
using namespace std;
int main()
{
	int n ,min,max, k;
	int arr[51] = { 0, };
	cin >> n;
	max = 0;
	min = 1000000;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (k < min) {
			min = k;
		}
		if (k > max) {
			max = k;
		}
	}
	cout << min * max;
	/*
	if (n == 1) {
		answer = arr[0] * arr[0];
	}
	else if (n == 2) {
		answer = arr[0] * arr[1];
	}
	else {

	}*/
	return 0;
}