#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int x;
	cin >> x;
	int index = 1;
	while (x > index) {
		x -= index;
		index++;
	}
	int a = index - x + 1;
	if (index % 2 == 0) cout << x << "/" << a;
	else cout << a << "/" << x;
	return 0;
}
