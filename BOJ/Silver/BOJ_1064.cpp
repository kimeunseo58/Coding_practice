#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
double getLen(int a, int b) {
	double p = sqrt(a * a + b * b);
	return p;
}
bool isLine1(int a1, int b1, int a2, int b2, int a3, int b3) {
	return abs(a1 - a2) * abs(b2 - b3) == abs(b1 - b2) * abs(a2 - a3);
}
bool isLine2(int a1, int b1, int a2, int b2, int a3, int b3) {
	return abs(a1 - a2) * abs(b1 - b3) == abs(b2 - b1) * abs(a3 - a1);
}
int main()
{
	int x1, y1, x2, y2, x3, y3;
	double a, b, c;
	double answer[3] = { 0, };
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	if (isLine1(x1, y1, x2, y2, x3, y3) && isLine2(x1, y1, x2, y2, x3, y3)) {
		cout << "-1.0";
		return 0;
	}
	a = getLen(x1 - x3, y1 - y3);
	b = getLen(x2 - x1, y2 - y1);
	c = getLen(x2 - x3, y2 - y3);
	answer[0] = 2 * (a + b);
	answer[1] = 2 * (a + c);
	answer[2] = 2 * (b + c);
	sort(answer, answer + 3);
	cout << fixed << setprecision(15) << answer[2]-answer[0];
	return 0;
}