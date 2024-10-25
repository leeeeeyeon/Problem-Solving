import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        
        int idx = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == ' ') {
                answer += c;
                idx = 0;
                continue;
            }
            
            if (idx % 2 == 0) answer += Character.toUpperCase(c);
            else answer += Character.toLowerCase(c);
            idx++;
        }
        
        return answer;
    }
}

// 반례) "A " >> "A "
// 공백 문자를 잘 들고 가는 것이 중요
