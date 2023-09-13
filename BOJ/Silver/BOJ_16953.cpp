#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
long long n,m;
queue<pair<long long,long long>>q;
void bfs(){
    q.push(make_pair(n,0));
    while(!q.empty()){
        long long a = q.front().first;
        long long cnt = q.front().second;
        q.pop();
        if(a == m){
            cout << cnt + 1;
            return; 
        }
        else{
            if(a * 10 + 1 <= m)q.push(make_pair(a * 10 + 1,cnt+1));
            if(a * 2 <= m)q.push(make_pair(a * 2,cnt+1));
        }
    }
    cout << -1;
}
int main() { 
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    bfs();
    return 0;
}
