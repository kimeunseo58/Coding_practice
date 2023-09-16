#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int a, b;
	cin >> n >> a >> b;
	int res = 0;
	while (a != b) {
		a = (a + 1) / 2;
		b = (b + 1) / 2;
		res++;
	}
	cout << res;
}
