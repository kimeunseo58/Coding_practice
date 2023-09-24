#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,m;
int w[1000001];
int res = 0;
int main(int argc, char** argv)
{	
	cin >> n >> m;
	vector<vector<int>> v(n + 1);
	for(int i=1;i<=n;i++) cin >> w[i];
	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i<=n; i++){
		int flag = 1;
		for(int j = 0; j < v[i].size(); j++){
			if(w[v[i][j]] >= w[i]) 
				flag = 0; 
				
		}
		if(flag == 1) res++;
	}
	cout << res;
	return 0; 
}
