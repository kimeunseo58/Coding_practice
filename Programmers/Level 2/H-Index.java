import java.util.*;
class Solution {
    public int solution(int[] citations) {
        int answer = citations.length;
        Arrays.sort(citations);
        while(answer != 0){  
            int smaller = 0;
            int bigger = 0;
            for(int i =0 ;i< citations.length; i++){
                if(citations[i] >= answer){
                    smaller = i;
                    bigger = citations.length - i;
                    if(citations[i] == answer) smaller += 1;
                    if(smaller <= answer && bigger >= answer)  return answer;
                    break;
                }
            }
            answer--;
        }
        return answer;
    }
}
