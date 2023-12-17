import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	static int[] arr;
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        arr = new int[n];
        String[] s = br.readLine().split(" ");
        
        for(int i =0; i<n; i++) {
        	arr[i] = Integer.parseInt(s[i]);
        }
        int[] dp = new int[n];
        dp[0] = 1;
        for(int i =1; i<n; i++) {
        	int temp = -1;
        	for(int j =0; j<i; j++) {
        		if(arr[j] < arr[i]) 
        			temp = Math.max(temp,dp[j]);    
        	}
        	if(temp == -1) dp[i] = 1;
        	else dp[i] = temp + 1;
        }
        Arrays.sort(dp);
        System.out.println(dp[n-1]);
        
	}
	
}
