class Solution {
    public int[] solution(String s) {
        int[] answer = {0,0};
        int change = 1;
        int cnt0 = 0;
        while(true){
            int len = 0;
            for(int i =0; i< s.length(); i++){
                if(s.charAt(i) == '1') len++;
                else cnt0++;
            }
            s = Integer.toBinaryString(len);
            System.out.println(s);
            if(len == 1){
                answer[0] = change;
                answer[1] = cnt0;
                break;
            }
            change++;
        }
        
        return answer;
    }
}
