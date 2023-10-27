import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i = 0; i< works.length; i++) pq.add(works[i]);
        for(int i =0; i<n; i++){
            int k = pq.poll();
            
            k--;
            if(k <= 0) pq.add(0);
            else pq.add(k);
        }
       while(!pq.isEmpty()){
            answer += pq.peek() * pq.poll();
        }
        return answer;
    }
}
//가장 큰 값부터 줄이면서, 남은 배열들이 균등하도록 줄임
