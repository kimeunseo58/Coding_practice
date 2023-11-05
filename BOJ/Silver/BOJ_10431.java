
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int n = Integer.parseInt(str);
        for(int t = 0; t < n; t++) {
        	String s[] = br.readLine().split(" ");
        	int x = Integer.parseInt(s[0]);
        	int[] arr = new int[20];
        	for(int i =1; i< 21;i++) arr[i - 1] = Integer.parseInt(s[i]);
        	int res = 0;
        	for(int i = 1; i< 20; i++) {
        		int idx = -1;
        		for(int j = 0; j < i; j++) 
        			if(arr[j] > arr[i]) {
        				idx = j;
        				break;
        			}
        				
        		if(idx != -1) {
        			int tmp = arr[i];
        			for(int j = i; j > idx; j--) {
        				arr[j] = arr[j - 1];
        				res++;
        			}
        			arr[idx] = tmp;
        		}
        	}
        	System.out.println(x + " " + res);
        }
    }
}
