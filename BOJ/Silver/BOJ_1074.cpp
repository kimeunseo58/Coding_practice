#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n, r, c;
int answer = 0;
void Z(int x, int y, int z) {
	if (c == x && r == y) cout<< answer;
	else if (c < x + z && c >= x && r < y + z && r >= y) {
		Z(x, y, z / 2);
        Z(x + z / 2, y, z / 2);
		Z(x, y + z / 2, z / 2);
		Z(x + z / 2, y + z / 2, z / 2);
	}
	else answer += z * z;
}
int main() {
	//answer = 0;
	cin >> n >> r >> c;
	Z(0, 0, pow(2,n));
	return 0;
}


   
