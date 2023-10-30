import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        //BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
		String[] numbers = br.readLine().split(" ");
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(numbers[i]);

        int m = Integer.parseInt(br.readLine());
        int[] arrM = new int[m];
        String[] numbersM = br.readLine().split(" ");
        for(int i =0; i < m; i++) arrM[i] = Integer.parseInt(numbersM[i]);
        
        Arrays.sort(arr);
        
        for(int i =0; i < m ; i++) {
        	int x = arrM[i];
        	boolean flag = false;
        	int left = 0;
        	int right = n - 1;
        	while(left<= right) {
        		int mid = (left + right)/2;
        		if(arr[mid] == x) {
        			flag = true;
        			break;
        		}
        		else if(x < arr[mid]) right = mid -1;
        		else if(x > arr[mid]) left = mid + 1;
        	}   
            if(flag) System.out.println(1);
            else System.out.println(0);
        }
	} 
}
