import java.util.*;
class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        
        Arrays.sort(people);
        int i = 0;
        for (int j = people.length - 1; j >= i; j--){
            if (people[i] + people[j] <= limit) i++;
            answer++;
        }
        return answer;
    }
}
