#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int k,n;
queue<pair<int, int> > q;
int check[100001] = {0,};
int answer = 0;
void bfs(){
    q.push(make_pair(n, 0));
    while(!q.empty()){
        int a = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(a == k){
            cout << cnt;
            return;
        }
        else{
            if(check[a + 1] == 0 && a + 1 >= 0 && a + 1 <= 100000){
                q.push(make_pair(a+1, cnt+1));
                check[a+1] = 1;
            }
            if(check[a - 1] == 0 && a - 1 >= 0 && a - 1 <= 100000){
                q.push(make_pair(a-1, cnt+1));
                check[a-1] = 1;
            }
            if(check[2*a] == 0 && 2*a >= 0 && 2*a <= 100000){
                q.push(make_pair(a*2, cnt+1));
                check[2*a] = 1;
            }
        }
    }
}
int main() { 
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    bfs();
    return 0;
}
