#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {    
    int n, k, x, m;
    int check[300001] = {0,};    
    cin >> n >> m >> k >> x;
    vector<vector<int>> arr(n +1);
    vector<int> answer;
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
    }
    queue<pair<int,int>> q;
    q.push({x, 0});
    check[x] = 1;
    while(!q.empty()){
        int a = q.front().first;
        int dis = q.front().second;
        q.pop();
        if(dis == k) answer.push_back(a);
        for(int i =0; i < (signed)arr[a].size(); i++){
            int b = arr[a][i];
            if(check[b] == 0){
                check[b] = 1;
                q.push({b, (dis+1)});
            }
        }    
    }
    if(answer.size() == 0) {
        cout << -1;
        return 0;
    }
    sort(answer.begin(),answer.end());
        for(int i=0;i<answer.size(); i++) cout << answer[i] <<'\n';
    return 0;
}
