import java.util.*;

class Solution {
    public int solution(int n) {
        int answer = 0;
        
        String str = "";
        // n을 3진법으로 만든다
        while (n > 0) {
            String temp = (n % 3) + "";
            str = temp + str;
            n /= 3;
        }
        
        // String을 뒤집는다
        StringBuffer sb = new StringBuffer(str);
        str = sb.reverse().toString();
        
        // 10진법으로 표현
        for (int i = str.length()-1; i >= 0; i--) {
            int number = str.charAt(i) - '0';
            
            answer += number * Math.pow(3, str.length()-i-1);
        }
        
        return answer;
    }
}