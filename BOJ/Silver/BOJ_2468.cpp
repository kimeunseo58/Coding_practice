#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[101][101];
int numOfSafe[101] = {0,};
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};    
int check[101][101] ={0,};
int n, maxH;
void bfs(int a, int b){
    queue<pair<int, int>> q;
    q.push({a,b});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i =0;i<4;i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx >= 0 && xx < n && yy >= 0 && yy < n){
                if(check[xx][yy] == 0){
                     check[xx][yy] = 1;
                     q.push({xx,yy});
                   
                }
            }
        }
    }
}
int main() { 
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    cin >> n;
    maxH = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            if(arr[i][j] > maxH) maxH = arr[i][j];
        }
    }
    for(int k = 0; k<= maxH; k++){
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(arr[i][j] <= k) check[i][j] = -1;
                else check[i][j] = 0;
            }
        }
        for(int i= 0; i<n; i++){
            for(int j =0;j<n;j++){
                if(check[i][j] == 0){
                    bfs(i,j);
                    numOfSafe[k]++;
                }
            }
        }
    }
    sort(numOfSafe,numOfSafe+maxH);
    cout << numOfSafe[maxH - 1] <<'\n';
}
