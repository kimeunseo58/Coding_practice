import java.util.*;
class Solution {
    int[] check;
    Map<Integer, List<Integer>> hm;
    public int solution(int n, int[][] edge) {
        int answer = 0;
        check = new int[n + 1];
        for(int i =0; i< n + 1; i++)check[i]  = -1;
        check[1] = 0;
        hm = new HashMap<>();
        for(int i =1; i< n+1; i++){
             hm.put(i, new ArrayList<>());
        }
        for(int i = 0; i < edge.length; i++){
            int node1 = edge[i][0];
            int node2 = edge[i][1];
            hm.get(node1).add(node2);
            hm.get(node2).add(node1);
        }
        List<Integer> arr = hm.get(1);
        for (int i = 0; i < arr.size(); i++) {
            dfs(arr.get(i), 1);
        }
        int m = -1;
        for(int i = 0; i < check.length; i++) m = Math.max(m, check[i]);
        for(int i = 0; i <check.length; i++){
            if(m == check[i]) answer++;
        }
        return answer;
    }
    
    public void dfs(int start, int cnt){
        if(check[start] != -1 && check[start] <= cnt) return;
        if(check[start] == -1) check[start] = cnt;
        else check[start] = Math.min(check[start], cnt);
        List<Integer> arr = hm.get(start);
        for(int i = 0; i< arr.size(); i++){
            dfs(arr.get(i), cnt + 1);
        }
    }
}
