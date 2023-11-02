import java.util.*;
class Solution {
    int[] check;
    Set<Set<Integer>> res = new HashSet<>();
    Set<Integer> s; 
    public int solution(String[] user_id, String[] banned_id) {
        int answer = 0;
        Vector<Vector<Integer>> v = new Vector<>();
        for(int i =0; i < banned_id.length; i++){
            Vector<Integer> tempV = new Vector<>();
            for(int j = 0; j< user_id.length; j++){
                if(is_ban(banned_id[i], user_id[j])) tempV.add(j);
            }
            v.add(tempV);
        }
        Collections.sort(v, (o1,o2)->Integer.compare(o1.size(), o2.size()));
        Vector<Integer> tempV = v.get(0);
        if(v.size() == 1) return tempV.size();
        for(int j =0; j< tempV.size(); j++){
            check = new int[user_id.length];
            check[tempV.get(j)] = 1;
            s = new HashSet<>();
            s.add(tempV.get(j));
            dfs(s, v, 0);
        }
        return res.size();
    }
    public void dfs(Set<Integer> s, Vector<Vector<Integer>> v, int startIdx){
        for(int i = startIdx + 1; i < v.size(); i++){
            Vector<Integer> tempV = v.get(i);
            for(int j =0; j< tempV.size(); j++){
                if(check[tempV.get(j)] == 0){
                    check[tempV.get(j)] = 1;
                    Set<Integer> copySet = new HashSet<>(s);
                    copySet.add((Integer) tempV.get(j));
                    dfs(copySet, v, i);
                    if(i == v.size() - 1 && copySet.size() ==  v.size()) res.add(copySet);
                    check[tempV.get(j)] = 0;
                }
            }
        }
    }
    public boolean is_ban(String s1, String s2){
        if(s1.length() != s2.length()) return false;
        for(int i =0; i< s1.length(); i++){
            if(s1.charAt(i) == '*') continue;
            if(s1.charAt(i) != s2.charAt(i)) return false;
        }
        return true;
    }
}
