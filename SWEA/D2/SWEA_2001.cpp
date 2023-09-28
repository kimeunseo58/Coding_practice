#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
int map[16][16];
int res = -1;
void check(int x,int y){
    int side = (n - 1) - (m - 1);
	if(x == side && y == side) return;
    else{
        int tmp = 0;
    	for(int i =0; i<m; i++){
       		for(int j =0; j<m; j++)  tmp += map[x + i][y + j];
        }
    	res = max(res, tmp);
        if(x + 1 <= side) check(x + 1, y);
        else if( x + 1 > side && y + 1 <= side)check(0, y + 1);
    }
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " ";
        cin >> n >> m;
        for(int i =0;i<n;i++){
			for(int j =0; j<n; j++) cin >> map[i][j];
        }
        res = -1;
        check(0,0);
        cout << res <<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
