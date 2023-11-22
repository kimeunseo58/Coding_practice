import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static int n,m;
	static int[] dx = {0,-1,-1,-1,0,1,1,1};
	static int[] dy = {-1,-1,0,1,1,1,0,-1};
	static int[][] arr, rain,rain_moving_check;
	static xy[] move;
	static class xy {
		int d;
		int s;
		public xy(int d, int s) {
			this.d = d;
			this.s = s;
		}
	}
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);
        
        arr = new int[n][n];
        rain = new int[n][n];
        move = new xy[m];
        for(int i =0; i< m; i++) move[i] = new xy(0,0);
        
        for(int i = 0; i< n; i++) {
        	String[] r = br.readLine().split(" ");
        	for(int j =0; j< n; j++) 
        		arr[i][j] = Integer.parseInt(r[j]);
        }
        for(int i =0; i<  m; i++) {
        	String[] s2 = br.readLine().split(" ");
        	move[i].d = Integer.parseInt(s2[0]);
        	move[i].s = Integer.parseInt(s2[1]);
        }
        rain[n-1][0] = 1;
        rain[n-1][1] = 1;
        rain[n-2][0] = 1;
        rain[n-2][1] = 1;

        for(int x =0; x< m; x++) {
            rain_moving_check = new int[n][n];
            moving(x);
            checkingCross();
            rain = new int[n][n];
            makeCloud();
        }     
        int res = 0;
        for(int i = 0; i< n; i++) {
        	  for(int j =0; j< n; j++) 
        		  res += arr[i][j];
         }
        System.out.println(res);
    }
    public static void moving(int idx) {
    	for(int i =0; i< n; i++) {
    		for(int j =0; j<n;j++) {
    			if(rain[i][j] == 0) continue;
    			int d = move[idx].d - 1;
    			int s = move[idx].s;
    			int x = (i + dx[d] * s) % n;
    			int y =(j + dy[d] * s ) % n;
    			if(x < 0 ) x = n + x;
    			if(y < 0 ) y = n + y ;
    			rain_moving_check[x][y] = 1;
    			arr[x][y]++;
    		}
    	}
    }
    public static boolean isIn(int x, int y) {
    	if(x >= 0 && x < n && y >=0 && y < n)return true;
    	return false;
    }
    public static void checkingCross() {
    	for(int i =0; i< n; i++) {
    		for(int j =0; j<n;j++) {
    			if(rain_moving_check[i][j]==0) continue;
    			for(int k = 1; k <8; k+=2) {
    				int x = i + dx[k];
    				int y = j + dy[k];
    				if(isIn(x,y)&&arr[x][y] >0)
    					arr[i][j]++;
    			}
    		}
    	}
    }
    public static void makeCloud() {
    	for(int i =0;i<n; i++) {
    		for(int j =0; j< n; j++) {
    			if(arr[i][j] <2) continue;
    			if(rain_moving_check[i][j] == 1) continue;
    			rain[i][j] = 1;
    			arr[i][j] -= 2;
    		}
    	}
    }
}
