import java.util.*;
class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        Arrays.sort(phone_book);
        for(int i = 0; i < phone_book.length - 1; i++){
            String s = phone_book[i];
            String s2 = phone_book[i + 1];
            int len = Math.min(s.length(), s2.length());
            if(s.substring(0, len).equals(s2.substring(0, len))) return false;
        }
        return answer;
    }
}
