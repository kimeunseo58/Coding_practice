import java.util.*;
class Solution {
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;
        int[] temp = copyArr(number);
        int num = 10;
        for(int i = 0; i < discount.length; i++){
            int idx = findIdx(want, discount[i]);
            if(idx < 0 || (idx >= 0 && temp[idx] <= 0)) {//할인 물품이 원하는 물품에 없을때
                // 이미 해당 물품을 모두 구매했을 때 -> 불가능
                temp = copyArr(number); //장바구니 개수 초기화
                i -= (10 - num);
                num = 10;
            }
            else{
                num--;
                temp[idx]--;
                if(num == 0) {// 할인 물품 모두 구매 완료
                    answer++; // 구매 가능 날짜 추가
                    i -= 10;
                    num = 10;
                }
            }
        }
        
        return answer;
    }
    public int[] copyArr(int[] number){
        int[] temp = new int[number.length];
        for(int i =0 ;i<number.length; i++) temp[i] = number[i];
        return temp;
    }
    public int findIdx(String[] want, String s){
        int idx = -1;
        for(int i = 0 ;i< want.length; i++){
            if(want[i].equals(s)){
                idx = i;
                break;
            }
        }
        return idx;
    }
}
