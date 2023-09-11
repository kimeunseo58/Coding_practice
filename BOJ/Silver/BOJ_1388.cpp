#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
char wood[50][50];
bool visited[50][50]={0,};
int answer = 0;
int xy[2] = {-1,1};
void dfs(int x, int y){
    for(int i =0; i<2;i++){
        int xx = x;
        int yy = y;
        if(wood[x][y] == '|') xx += xy[i];
        else yy += xy[i];
         
        if(xx >= 0 && xx < n && yy >= 0 && yy < m){
            if(wood[x][y] == wood[xx][yy] && visited[xx][yy] == 0){
                visited[xx][yy] = 1;
                dfs(xx, yy); 
            }    
        }
    }
};

int main(){
    cin >> n >> m;
    string s;
    for(int i=0;i < n;i++){
        cin >> s;
        for(int j =0; j < m;j++){
            wood[i][j] = s[j];
        }
    }

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 1)
				continue;
			else {
				dfs(i, j);
				answer++;
			}
		}
	}
    cout << answer <<'\n';
  return(0);
}
