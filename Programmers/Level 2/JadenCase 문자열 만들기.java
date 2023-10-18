
class Solution {
    public String solution(String s) {
        String answer = "";
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(c >= '0' && c <= '9') answer += (char)(s.charAt(i));
            else{
                if(i == 0){
                    if(c >= 'a' && c <= 'z') answer += (char)(c + 'A' - 'a');
                    else answer += c;
                }
                else if(i >= 1 && s.charAt(i - 1) == ' '){
                    if(c >= 'a' && c <= 'z') answer += (char)(c + 'A' - 'a');
                    else answer += c;
                }
                else if(i >= 1 && s.charAt(i -1) != ' '){
                    if(c >= 'A' && c <= 'Z') answer += (char)(c + 'a' - 'A');
                    else answer += c;
                }
                
            }
        }
        return answer;
    }
}
