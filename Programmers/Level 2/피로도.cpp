class Solution {
    int[] check = {0,0,0,0,0,0,0,0};
    int answer = 0;
    public int solution(int k, int[][] dungeons) {
        find(0,k,dungeons);
        return answer;
    }
    public int find(int n, int k, int[][] dungeons){
        for(int i = 0; i < dungeons.length; i++){
            if(check[i] == 0 && dungeons[i][0] <= k){
                check[i] = 1;
                find(n + 1, k- dungeons[i][1], dungeons);
                check[i] = 0;
            }
        }
        answer = Math.max(answer, n);
        return 0;
    }
}
