#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    int dp[501][501];
    for(int i = 0; i< n; i++){
        for(int j =0; j <= i; j++) dp[i][j] = triangle[i][j];
    }
    for(int i = n - 2; i > 0; i--){
        for(int j = 0; j <= i; j++){
            dp[i][j] += max(dp[i+1][j], dp[i+1][j + 1]);
        }
    }
    answer = dp[0][0] + max(dp[1][0],dp[1][1]);
    return answer;
}
