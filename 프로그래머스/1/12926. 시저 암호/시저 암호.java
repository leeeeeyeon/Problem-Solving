import java.util.*;
import java.io.*;

class Solution {
    public String solution(String s, int n) {
        String answer = "";
        
        List<Character> lowerAlpha = new ArrayList<>();
        List<Character> upperAlpha = new ArrayList<>();
        
        for (int i = 0; i < 26; i++) {
            lowerAlpha.add((char)('a' + i));
            upperAlpha.add((char)('A' + i));
        }
        
        lowerAlpha.addAll(lowerAlpha);
        upperAlpha.addAll(upperAlpha);
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == ' ') {
                answer += c;
                continue;
            }
            
            if ('a' <= c && c <= 'z') {
                int idx = c - 'a';
                answer += lowerAlpha.get(idx+n);
            } else {
                int idx = c - 'A';
                answer += upperAlpha.get(idx+n);
            }
        }
        
        return answer;
    }
}