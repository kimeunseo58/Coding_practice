import java.util.*;
class Solution
{
    public int solution(String s)
    {
        Stack<Integer> stack = new Stack<>();
        stack.push((int)s.charAt(0));
        for(int i =1 ;i < s.length(); i++){
            if(!stack.empty() && stack.peek() == (int)s.charAt(i)) stack.pop();
            else stack.push((int)s.charAt(i));
        }
        int answer = 0;
        if(stack.empty()) answer = 1;
        return answer;
    }
}
