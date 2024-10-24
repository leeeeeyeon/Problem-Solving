import java.util.*;

class Solution {
    public String solution(String s) {
        char[] charArr = s.toCharArray();
        Arrays.sort(charArr);
        
        String answer = new String(charArr);
        
        StringBuffer sb = new StringBuffer(answer);
        answer = sb.reverse().toString();
        
        return answer;
    }
}