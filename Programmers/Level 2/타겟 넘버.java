class Solution {
    public int answer = 0;
    public int solution(int[] numbers, int target) {
        dfs(numbers, target, 0, 0);
        return answer;
    }
    public void dfs(int[] numbers, int target, int res, int idx){
        if(idx < numbers.length - 1){
            idx += 1;
            dfs(numbers, target, res + numbers[idx - 1], idx);
            dfs(numbers, target, res - numbers[idx - 1], idx);
        }
        else if(idx == numbers.length - 1){
             if(res + numbers[idx] == target) answer++;
             if(res - numbers[idx] == target) answer++;
        }
    }
}
