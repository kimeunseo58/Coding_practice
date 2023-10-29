import java.util.*;
class Solution {
    int[][] tree;
    public int solution(int n, int[][] wires) {
        int answer = n;
        tree = new int[n+1][n+1];
        for(int i=0; i<wires.length; i++){
            int a = wires[i][0], b = wires[i][1];
            tree[a][b] = 1;
            tree[b][a] = 1;
        }
        for(int i=0; i<wires.length; i++){
            int a = wires[i][0], b = wires[i][1];
            tree[a][b] = 0;
            tree[b][a] = 0;
            answer = Math.min(answer, bfs(n, a));
            tree[a][b] = 1;
            tree[b][a] = 1;
        }
        return answer;
    }
    public int bfs(int n, int x){
        int[] check = new int[n+1];
        int count = 1;
        Queue<Integer> q = new LinkedList<>();
        check[x] = 1;
        q.offer(x);
        while(!q.isEmpty()){
            int temp = q.poll();
            for(int i=1; i<=n; i++){
                if(tree[temp][i] == 1 && check[i] == 0){
                    check[i] = 1;
                    q.offer(i);
                    count++;
                }
            }
        }
        return (int)Math.abs(count-(n-count));
    }
}
