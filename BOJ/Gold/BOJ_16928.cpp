#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, m;
int map[101] = {0,};
bool check[101] = { false, };
queue<pair<int, int>> point;
void game() {
	point.push({ 1,0 });
	while (!point.empty()) {
		int location = point.front().first;
		int move = point.front().second;
		point.pop();
		for (int i = 1; i <= 6; i++) {
			int x = location + i;
			if (x == 100) { cout << move + 1; return; }
			else if (x < 100) {
				while (map[x] != 0) x = map[x];
				if (check[x] == false) {
					point.push({ x,move + 1 });
					check[x] = true;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= n + m; i++) {
		cin >> a >> b;
		map[a] = b;
	}
	game();
	return 0;
}
