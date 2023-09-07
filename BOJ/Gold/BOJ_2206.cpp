#include<iostream>
#include<queue>
#include<tuple>
#include<algorithm>
using namespace std;
int n, m;
queue<tuple<int,int,int>> q;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int arr[1001][1001];
int check[1001][1001][2] = { 0, };
int isInside(int xx, int yy){
    if(xx >= 0 && xx < n && yy >= 0 && yy < m) return 1;
    else return 0;
}
int bfs(){
    q.push(make_tuple(0, 0, 0));
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int isB = get<2>(q.front());
        q.pop();
        int answer = check[x][y][isB];
        //cout << answer << endl;
        for(int i =0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(isInside(xx, yy)){
                if(xx == n - 1 && yy == m - 1) return answer + 1;
                if(arr[xx][yy] == 1 && isB == 0 && check[xx][yy][isB] == 0){
                    check[xx][yy][1] = answer + 1;
                    q.push(make_tuple(xx,yy,1));
                }
                else if(arr[xx][yy] == 0 && check[xx][yy][isB] == 0){
                    check[xx][yy][isB] = answer + 1;
                    q.push(make_tuple(xx,yy,isB));
                }
            }
        }
    }
    return -1;
}
int main(){
    cin >> n >> m;
    string a;
    int x,y;
    for(int i=0;i<n;i++) {
        cin >> a;
        x = i;
        for(int j=0;j<m;j++){
            y = j;
            arr[i][j] = a[j] - 48;
        }
    }
    check[0][0][0] = 1;
    if(n == 1 && m == 1){
        if(arr[0][0] == 1) cout << -1;
        else cout << 1;
    }
    else cout <<  bfs();
    return 0;
}
