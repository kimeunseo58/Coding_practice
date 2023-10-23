
class Solution {
    public int solution(int[] arr) {
        //int answer = 0;
        int num = getNum(arr[0], arr[1]);
        if(arr.length == 1) return arr[0];
        else if (arr.length == 2) return num;
        for(int i = 2; i<arr.length; i++){
           num = getNum(num,arr[i]);
        }
        return num;
    }
    public int getDivider(int a,int b){
        if(a < b){  
            int t = a;
            a = b;
            b = t;
        }
        for(int i = b; i > 0; i--){
            if(a % i == 0 && b % i == 0) return i;
        }
        return 1;
    }
    public int getNum(int a, int b){
        return (a * b / getDivider(a,b));
    }
}
