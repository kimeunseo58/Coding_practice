#include<iostream>
#include<cmath>
using namespace std;
int n;
int map[49][49];
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " ";
        cin >> n;
        string s;
        for(int i =0; i<n;i++){
            cin >>s;
            for(int k =0; k<s.length(); k++)map[i][k] = s[k] - '0';
        }
        int x = n / 2;
        int res = 0;
        for(int i =0; i<n; i++){
        	for(int j =0;j<n;j++){
            	if(abs(x - i) + abs(x - j) <= x) res+= map[i][j];
            }
        }
        cout << res << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
