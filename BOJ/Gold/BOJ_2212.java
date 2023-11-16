import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	static class len{
		int idx;
		int dis;
		public len(int idx, int dis) {
			this.idx = idx;
			this.dis = dis;
		}
	}
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int k = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        String[] s = br.readLine().split(" ");
        len[] myLen = new len[n];
        for(int i = 0; i< n; i++) 
        	arr[i] = Integer.parseInt(s[i]);
        Arrays.sort(arr);
        int dis = 0;
        for(int i = 1; i< n; i++) {
        	myLen[i - 1] = new len(i - 1, arr[i] - arr[i-1]);
        	dis += arr[i] - arr[i - 1];
        }
        myLen[n - 1] = new len(n - 1, 0);
        Arrays.sort(myLen, (o1, o2) -> (o2.dis - o1.dis));
        int ans = 0;
        for(int i =k -1; i< n; i++) {
        	ans += myLen[i].dis;
        }
        
        System.out.println(ans);
	}
}
