#include<iostream>
#include<string>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	string s, y, m, d;
	int T, mm, dd;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> s;
		y = s.substr(0, 4);
		m = s.substr(4, 2);
		d = s.substr(6, 2);
		mm = (m[0] - 48) * 10 + (m[1] - 48);
		dd = (d[0] - 48) * 10 + (d[1] - 48);
		cout << "#" << test_case << " ";
		if (mm == (1, 3, 5, 7, 8, 10, 12) && dd < 1 && dd > 31) cout << -1 << '\n';
		else if (mm == (4, 6, 9, 11) && dd > 30 && dd < 1) cout << -1 << '\n';
		else if (mm == 2 && dd > 28) cout << -1 << '\n';
		else if (mm == 0)cout << -1 << '\n';
		else cout << y << '/' << m << '/' << d << '\n';
	}
	return 0;
}