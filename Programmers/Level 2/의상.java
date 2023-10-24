import java.util.*;
class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> hm = new HashMap<>();
        for(int i =0; i<clothes.length; i++){
            if(hm.containsKey(clothes[i][1])){
                int n = hm.get(clothes[i][1]) + 1;
                hm.replace(clothes[i][1], n);
            }
            else hm.put(clothes[i][1], 1);
        }
        List<Integer> arr = new ArrayList<>(hm.values());
        for(int i = 0; i < arr.size(); i++){ 
            answer *= arr.get(i) + 1;
        }
        return answer - 1;
    }
}
