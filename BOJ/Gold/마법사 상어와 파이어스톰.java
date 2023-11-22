
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	static int n,m;
	static int[][] arr, after_move, visited;
	static int[] L;
	static int[] dx = {0,0,-1,1};
	static int[] dy = {-1,1,0,0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);
        n = (int)Math.pow(2, n);
        arr = new int[n][n];
        L = new int[m];
        after_move = new int[n][n];
        
        for(int i = 0; i< n; i++) {
        	String[] r = br.readLine().split(" ");
        	for(int j =0; j< n; j++) 
        		arr[i][j] = Integer.parseInt(r[j]);
        }
        String[] t = br.readLine().split(" ");
        for(int i = 0;i < m; i++) L[i] = Integer.parseInt(t[i]);

        for(int k = 0; k< m; k++) {
        	rotate_divide((int)Math.pow(2, L[k]));
        	isIce();
        }
        
        int resNum = 0, maxNum = 0;
        visited = new int[n][n];
    	for(int i = 0; i< n; i++) {
    		for(int j =0; j< n; j++) {
    			//System.out.print(arr[i][j] + " ");
    			if(visited[i][j] == 0 && arr[i][j] != 0) {
    				maxNum = Math.max(maxNum, bfs(i,j));
    				//System.out.println(bfs(i,j));
    			}
    			resNum += arr[i][j];
    		}
    		//System.out.println();
    	}
    	System.out.println(resNum +  "\n" + maxNum);
    }
    static class xy{
    	int x;
    	int y;
    	public xy(int x, int y) {
    		this.x = x;
    		this.y = y;
    	}
    }
    public static int bfs(int x, int y) {
    	int cnt = 1;
    	Queue<xy> q = new LinkedList<>();
    	q.offer(new xy(x,y));
    	visited[x][y] = 1;
    	while(!q.isEmpty()) {
    		xy t = q.poll();
    		for(int i =0; i< 4; i++) {
        		int xx = t.x + dx[i];
        		int yy = t.y + dy[i];
        		if(isIn(xx,yy) && arr[xx][yy] > 0 && visited[xx][yy] == 0) {
        			visited[xx][yy] = 1;
        			cnt += 1;
        			q.offer(new xy(xx,yy));
        		}
    		}
    	}
    	return cnt;
    	
    }
    public static void rotate_divide(int num) {
    	while(num > 0) {
    		for(int i =0; i< n; i += num) {
        		for(int j =0; j< n; j += num) {
        			rotate(i,j,num);
        		}
        	}
    		for (int i = 0; i < after_move.length; i++) {
        	    arr[i] = Arrays.copyOf(after_move[i], after_move[i].length);
        	}
    		num /= 2;
    	}
    }
    public static void rotate(int x, int y, int nn) {
    	int check_x = x + nn / 2;
    	int check_y = y + nn / 2;
    	int check = nn /2;
    	for(int i = x; i< x + nn; i++) {
    		for(int j = y; j < y + nn; j++) {
    			if(i < check_x && j >= check_y) 
    				after_move[i + check][j] = arr[i][j];
    			else if(i >= check_x && j >= check_y)
    				after_move[i][j - check] = arr[i][j];
       			else if(i >= check_x && j < check_y)
    				after_move[i-check][j] = arr[i][j];
       			else if(i < check_x && j < check_y)
    				after_move[i][j + check] = arr[i][j];
    		}
    	}
    }
    public static void isIce() {
    	for(int i =0; i< n; i++) {
    		for(int j =0; j< n; j++) {
    			int numOfIce = 0;
    			for(int k =0; k< 4; k++) {
    				int x = i + dx[k];
    				int y = j + dy[k];
    				if(isIn(x,y) && after_move[x][y] > 0) numOfIce++;
    			}
    			if(numOfIce <3 && arr[i][j] != 0) arr[i][j]--;
    		}
    	}
    }
    public static boolean isIn(int x, int y) {
    	if(x >= 0 && x < n && y >=0 && y < n)return true;
    	return false;
    }
}
