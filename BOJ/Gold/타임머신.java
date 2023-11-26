import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	static int n, m;
	static class xy{
		int start;
		int end;
		int sec;
		public xy(int start, int end, int sec) {
			this.start = start;
			this.end = end;
			this.sec = sec;
		}
	
	}
	
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s=br.readLine().split(" ");
        n = Integer.parseInt(s[0]);
        m = Integer.parseInt(s[1]);
        xy[] city = new xy[m];
        for(int i =0; i<m; i++) city[i] = new xy(0,0,0);
        long [] res = new long[n+1];
        Arrays.fill(res, Integer.MAX_VALUE);
        for(int i =0; i<m; i++) {
        	String[] s1 = br.readLine().split(" ");
        	city[i].start = Integer.parseInt(s1[0]);
        	city[i].end = Integer.parseInt(s1[1]);
        	city[i].sec = Integer.parseInt(s1[2]);
        }
        res[1] = 0;
        for(int i=1; i<= n; i++) {
        	for(int j =0; j<m; j++) {
        		if(res[city[j].start] != Integer.MAX_VALUE &&
        				res[city[j].start] + city[j].sec < res[city[j].end]) {
        			res[city[j].end] = res[city[j].start] + city[j].sec;
        		}
        	}
        }
        for(int i =0; i<m; i++) {
        	//이미 최단 거리가 계산된 후에도 간선을 통해 노드로 가는 거리가 더 짧아진다면, 
        	//즉 최단 거리가 또 갱신된다면 음수 가중치 사이클이 존재한다는 것을 의미
        	if(res[city[i].start] != Integer.MAX_VALUE && 
        			res[city[i].start] + city[i].sec < res[city[i].end]) {
        		System.out.println(-1);
        		return;
        	}
        }
        for(int i =2; i<=n; i++) {
        	if(res[i]== Integer.MAX_VALUE) System.out.println(-1);
        	else System.out.println(res[i]);
        }
    }
}
