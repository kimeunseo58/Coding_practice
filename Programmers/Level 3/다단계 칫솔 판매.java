
import java.util.*;
class Solution {
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];
        HashMap<String, Vector<String>> map = new HashMap<>();
        for(int i =0; i< enroll.length; i++){
            String key = enroll[i];
            Vector<String> v = new Vector<>();
            v.add(String.valueOf(i));
            if(!referral[i].equals("-"))
                v.addAll(map.get(referral[i]));
            map.put(key, v);
        }
        for(int i =0; i< seller.length; i++){
            Vector<String> v = map.get(seller[i]);
            answer[Integer.parseInt(v.get(0))] += amount[i] * 90;
            int money = amount[i] * 10;
            for(int j = 1; j<v.size(); j++){
                int temp = money - (money/10);
                answer[Integer.parseInt(v.get(j))] += temp;
                money /= 10; 
                if(money < 1) break;
            }
        }        
        return answer;
    }
}
