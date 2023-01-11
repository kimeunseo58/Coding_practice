#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct Spot {
	int x = 0;
	int y = 0;
	int r = 0;
};
int isInCircle(Spot x, Spot y,  Spot z) {
	int x1 = pow((x.x - z.x), 2) + pow((x.y - z.y), 2);
	int x2 = pow((y.x - z.x), 2) + pow((y.y - z.y), 2);
	if ((x1 < pow(z.r, 2))&& (x2 < pow(z.r, 2))) {
		return 0;//출발과 도착이 한 원 안에 존재할 때.
	}
	else if ((x1 > pow(z.r, 2)) && (x2 < pow(z.r, 2))) {
		return 1;
	}
	else if ((x1 < pow(z.r, 2)) && (x2 > pow(z.r, 2))) {
		return 1;
	}
	else {
		return 0;
	}
}
int main()
{	
	int t;
	cin >> t;
	while (t--) {
		int n;
		int answer = 0;
		Spot x1, x2;
		Spot arr[51];
		cin >> x1.x >> x1.y >> x2.x >> x2.y >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i].x >> arr[i].y >> arr[i].r;
		for (int i = 1; i <= n; i++) answer += isInCircle(x1, x2, arr[i]);		
		cout << answer << '\n';
	}
}