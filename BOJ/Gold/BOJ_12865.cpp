#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct things{
    int w;
    int v;
};
int main() {
    int n, k;
    things myT[101];
    int dp[101][100001];
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> myT[i].w >> myT[i].v;

    for(int i =1;i<=n;i++){
        for(int j =1; j<=k; j++){
            if(myT[i].w <= j) 
								dp[i][j] = max(dp[i-1][j], myT[i].v +dp[i-1][j-myT[i].w]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k];
    return 0;
}
