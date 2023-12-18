import java.util.*;
class Solution {
   
    public long solution(int[] sequence) {
        long answer = 0;
        long[][] dp = new long[sequence.length][2];
        
        dp[0][0] = sequence[0] * -1;  //- 1 1 -1 1  -> 짝수번 -1
        dp[0][1] = sequence[0];   //1 -1 1 ->홀수번 -1
        
        for(int i = 1; i< sequence.length; i++){
            if(i % 2== 0){ //짝수
                dp[i][0] = Math.max(dp[i-1][0] + sequence[i] * -1,sequence[i] * -1);
                dp[i][1] = Math.max(dp[i-1][1] +sequence[i] ,sequence[i] );
            }else{ //홀수
                dp[i][0] = Math.max(dp[i-1][0] + sequence[i] ,sequence[i] );
                dp[i][1] = Math.max(dp[i-1][1] + sequence[i] * -1, sequence[i] * -1);
                
            }
        }
        
        long max1 = dp[0][0], max2 = dp[0][1];
        for(int i =0; i< sequence.length; i++){
             max1 = Math.max(max1, dp[i][0]);
             max2 = Math.max(max2, dp[i][1]);
        }

        return Math.max(max1, max2);
    }
}
