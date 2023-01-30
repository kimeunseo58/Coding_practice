#include<iostream>
#include<algorithm>
using namespace std;
struct word {
	string w;
	int len;
};
bool compare(const word& a, const word& b) {
	if (a.len == b.len) {
		return a.w < b.w;
	}
	else return a.len < b.len;
}
int main() {
	int n;
	string s;
	cin >> n;
	word a[20001];

	for (int i = 0; i < n; i++) {
		cin >> s;
		a[i].w = s;
		a[i].len = s.length();
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		if(a[i].w == a[i+1].w){
			continue;
		}
		else cout << a[i].w << '\n';
	}
}
