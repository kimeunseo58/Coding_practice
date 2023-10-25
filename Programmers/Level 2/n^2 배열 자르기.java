class Solution {
    public int[] solution(int n, long left, long right) {
        int t = (int)(right - left + 1);
        int[] answer = new int[t];
        // int[][] temp = new int[n][n];
        // for(int i =0; i<n;i++){
        //     for(int j = 0; j<n; j++){
        //         if(i > j) temp[i][j] = i + 1;
        //         else temp[i][j] = j + 1;
        //     }
        // }
        int x = (int)(left / n);
        int y = (int)(left % n);
        int cnt = 0;
        while(cnt < t){
            if(x > y) answer[cnt] = x + 1;
            else answer[cnt] = y + 1;
            //answer[cnt] = temp[x][y];
            if(y == n - 1){
                x += 1;
                y = 0;
            }
            else{
                y++;
            }
            cnt++;
        }
        return answer;
    }
}
