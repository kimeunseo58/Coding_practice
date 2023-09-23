#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int t;
	cin >> t;
	int num[10][8]={
		{1,1,1,0,1,1,1},//0
		{0,0,1,0,0,0,1},//1
		{0,1,1,1,1,1,0},//2
		{0,1,1,1,0,1,1},//3
		{1,0,1,1,0,0,1},//4
		{1,1,0,1,0,1,1},//5
		{1,1,0,1,1,1,1},//6
		{1,1,1,0,0,0,1},//7
		{1,1,1,1,1,1,1},//8
		{1,1,1,1,0,1,1},//9
	};
	while(t--){
		string a,b;
		cin >> a >> b;
		if(a.length() < b.length()){
			string s = a;
			a = b;
			b = s;
		} //길이가 더 긴 문자열 = a
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int res =0;
		for(int i =0; i < b.length(); i++){
			for(int j = 0; j<8; j++) res += abs(num[a[i] - '0'][j] - num[b[i] - '0'][j]);
		}
		for(int i = b.length(); i < a.length(); i++){
			for(int j = 0; j<8; j++) res += num[a[i] - '0'][j];
		}
		cout << res << '\n';
	}
	return 0;
}
